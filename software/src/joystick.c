/* joystick-v2-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * joystick.c: Joystick driver
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "joystick.h"

#include "configs/config.h"
#include "configs/config_joystick.h"

#include "bricklib2/hal/system_timer/system_timer.h"
#include "bricklib2/utility/util_definitions.h"
#include "bricklib2/bootloader/bootloader.h"

#include "xmc_vadc.h"
#include "xmc_gpio.h"

#define JOYSTICK_MAX_ADC_VALUE ((1  << 12) - 1)

#define joystick_adc_irq_handler IRQ_Hdlr_15

Joystick joystick;

static volatile uint32_t joystick_adc_value_x_sum = 0;
static volatile uint32_t joystick_adc_value_x_num = 0;

static volatile uint32_t joystick_adc_value_y_sum = 0;
static volatile uint32_t joystick_adc_value_y_num = 0;

void __attribute__((optimize("-O3"))) __attribute__ ((section (".ram_code"))) joystick_adc_irq_handler(void) {
	const uint32_t value = VADC->GLOBRES;
	const uint32_t channel = (value >> 20) & 0b1111;
	if(channel == 4) {
		joystick_adc_value_x_sum += (value & 0xFFFF);
		joystick_adc_value_x_num++;
	} else {
		joystick_adc_value_y_sum += (value & 0xFFFF);
		joystick_adc_value_y_num++;
	}
}

void joystick_write_calibration(int16_t x, int16_t y) {
	uint32_t page[EEPROM_PAGE_SIZE/sizeof(uint32_t)];
	page[JOYSTICK_CALIBRATION_MAGIC_POS] = JOYSTICK_CALIBRATION_MAGIC;
	page[JOYSTICK_CALIBRATION_X_POS]     = x + INT16_MAX;
	page[JOYSTICK_CALIBRATION_Y_POS]     = y + INT16_MAX;

	if(!bootloader_write_eeprom_page(JOYSTICK_CALIBRATION_PAGE, page)) {
		// TODO: Error handling?
	}
}


void joystick_read_calibration(void) {
	uint32_t page[EEPROM_PAGE_SIZE/sizeof(uint32_t)];

	bootloader_read_eeprom_page(JOYSTICK_CALIBRATION_PAGE, page);

	// The magic number is not where it is supposed to be.
	// This is either our first startup or something went wrong.
	// We initialize the calibration data with sane default values.
	if(page[JOYSTICK_CALIBRATION_MAGIC_POS] != JOYSTICK_CALIBRATION_MAGIC) {
		joystick.x_cal = 0;
		joystick.y_cal = 0;

		joystick_write_calibration(0, 0);

		return;
	}

	joystick.x_cal = page[JOYSTICK_CALIBRATION_X_POS] - INT16_MAX;
	joystick.y_cal = page[JOYSTICK_CALIBRATION_Y_POS] - INT16_MAX;
}

void joystick_calibrate(void) {
	int16_t x = JOYSTICK_MAX_ADC_VALUE/2  - joystick_adc_value_x_sum / joystick_adc_value_x_num;
	int16_t y = JOYSTICK_MAX_ADC_VALUE/2  - joystick_adc_value_y_sum / joystick_adc_value_y_num;

	joystick.x_cal = x;
	joystick.y_cal = y;

	joystick_write_calibration(x, y);
}

void joystick_init(void) {
	memset(&joystick, 0, sizeof(Joystick));

	joystick_read_calibration();

	const XMC_GPIO_CONFIG_t switch_pin_config = {
		.mode             = XMC_GPIO_MODE_INPUT_TRISTATE,
		.input_hysteresis = XMC_GPIO_INPUT_HYSTERESIS_STANDARD
	};
	XMC_GPIO_Init(JOYSTICK_SWITCH_PIN, &switch_pin_config);

	// This structure contains the Global related Configuration.
	const XMC_VADC_GLOBAL_CONFIG_t adc_global_config = {
		.boundary0 = (uint32_t) 0, // Lower boundary value for Normal comparison mode
		.boundary1 = (uint32_t) 0, // Upper boundary value for Normal comparison mode

		.class0 = {
			.sample_time_std_conv     = 31,                      // The Sample time is (2*tadci)
			.conversion_mode_standard = XMC_VADC_CONVMODE_12BIT, // 12bit conversion Selected

		},
		.class1 = {
			.sample_time_std_conv     = 31,                      // The Sample time is (2*tadci)
			.conversion_mode_standard = XMC_VADC_CONVMODE_12BIT, // 12bit conversion Selected

		},

		.data_reduction_control         = 0b11, // Accumulate 4 result values
		.wait_for_read_mode             = 0, // GLOBRES Register will not be overwritten until the previous value is read
		.event_gen_enable               = 1, // Result Event from GLOBRES is enabled
		.disable_sleep_mode_control     = 0  // Sleep mode is enabled
	};


	// Global iclass0 configuration
	const XMC_VADC_GLOBAL_CLASS_t adc_global_iclass_config = {
		.conversion_mode_standard = XMC_VADC_CONVMODE_12BIT,
		.sample_time_std_conv	  = 31,
	};

	// Global Result Register configuration structure
	XMC_VADC_RESULT_CONFIG_t adc_global_result_config = {
		.data_reduction_control = 0, //0b11, // Accumulate 4 result values
		.post_processing_mode   = XMC_VADC_DMM_REDUCTION_MODE,
		.wait_for_read_mode  	= 1, // Enabled
		.part_of_fifo       	= 0, // No FIFO
		.event_gen_enable   	= 1  // Enable Result event
	};

	// LLD Background Scan Init Structure
	const XMC_VADC_BACKGROUND_CONFIG_t adc_background_config = {
		.conv_start_mode   = XMC_VADC_STARTMODE_CIR,       // Conversion start mode selected as cancel inject repeat
		.req_src_priority  = XMC_VADC_GROUP_RS_PRIORITY_1, // Priority of the Background request source in the VADC module
		.trigger_signal    = XMC_VADC_REQ_TR_A,            // If Trigger needed then this denotes the Trigger signal
		.trigger_edge      = XMC_VADC_TRIGGER_EDGE_NONE,   // If Trigger needed then this denotes Trigger edge selected
		.gate_signal       = XMC_VADC_REQ_GT_A,			   // If Gating needed then this denotes the Gating signal
		.timer_mode        = 0,							   // Timer Mode Disabled
		.external_trigger  = 0,                            // Trigger is Disabled
		.req_src_interrupt = 0,                            // Background Request source interrupt Disabled
		.enable_auto_scan  = 1,
		.load_mode         = XMC_VADC_SCAN_LOAD_OVERWRITE
	};


	XMC_VADC_GLOBAL_Init(VADC, &adc_global_config);
	XMC_VADC_GLOBAL_StartupCalibration(VADC);

	// Initialize the Global Conversion class 0
	XMC_VADC_GLOBAL_InputClassInit(VADC, adc_global_iclass_config, XMC_VADC_GROUP_CONV_STD, 0);
	// Initialize the Global Conversion class 1
	XMC_VADC_GLOBAL_InputClassInit(VADC, adc_global_iclass_config, XMC_VADC_GROUP_CONV_STD, 1);

	// Initialize the Background Scan hardware
	XMC_VADC_GLOBAL_BackgroundInit(VADC, &adc_background_config);

	// Initialize the global result register
	XMC_VADC_GLOBAL_ResultInit(VADC, &adc_global_result_config);

	XMC_VADC_GLOBAL_BackgroundAddChannelToSequence(VADC, 0, JOYSTICK_ADC_X_CHANNEL);
	XMC_VADC_GLOBAL_BackgroundAddChannelToSequence(VADC, 0, JOYSTICK_ADC_Y_CHANNEL);
	XMC_VADC_GLOBAL_SetResultEventInterruptNode(VADC, XMC_VADC_SR_SHARED_SR0);

	XMC_VADC_GLOBAL_BackgroundTriggerConversion(VADC);

    NVIC_SetPriority(JOYSTICK_ADC_IRQ, JOYSTICK_ADC_IRQ_PRIORITY);
    NVIC_EnableIRQ(JOYSTICK_ADC_IRQ);
}

void joystick_tick(void) {
	static uint32_t last_update = 0;
		
	joystick.pressed = XMC_GPIO_GetInput(JOYSTICK_SWITCH_PIN);

	if(system_timer_is_time_elapsed_ms(last_update, 1)) {
		NVIC_DisableIRQ(JOYSTICK_ADC_IRQ);

		if(joystick.calibrate) {
			joystick_calibrate();
			joystick.calibrate = false;
		}

		if(joystick_adc_value_x_num > 0) {
			if((joystick_adc_value_x_sum > JOYSTICK_MAX_ADC_VALUE*joystick_adc_value_x_num/4) && (joystick_adc_value_x_sum < JOYSTICK_MAX_ADC_VALUE*joystick_adc_value_x_num*3/4)) {
				joystick_adc_value_x_sum += joystick.x_cal*joystick_adc_value_x_num;
			}
			joystick.x = 100 - (joystick_adc_value_x_sum*200 + JOYSTICK_MAX_ADC_VALUE*joystick_adc_value_x_num/2) / (JOYSTICK_MAX_ADC_VALUE*joystick_adc_value_x_num);
		}

		if(joystick_adc_value_y_num > 0) {
			if((joystick_adc_value_y_sum > JOYSTICK_MAX_ADC_VALUE*joystick_adc_value_y_num/4) && (joystick_adc_value_y_sum < JOYSTICK_MAX_ADC_VALUE*joystick_adc_value_y_num*3/4)) {
				joystick_adc_value_y_sum += joystick.y_cal*joystick_adc_value_y_num;
			}
			joystick.y = 100 - (joystick_adc_value_y_sum*200 + JOYSTICK_MAX_ADC_VALUE*joystick_adc_value_y_num/2) / (JOYSTICK_MAX_ADC_VALUE*joystick_adc_value_y_num);
		}

		joystick.x = BETWEEN(-100, joystick.x, 100);
		joystick.y = BETWEEN(-100, joystick.y, 100);

		joystick_adc_value_x_sum = 0;
		joystick_adc_value_x_num = 0;
		joystick_adc_value_y_sum = 0;
		joystick_adc_value_y_num = 0;
		last_update = system_timer_get_ms();

		NVIC_EnableIRQ(JOYSTICK_ADC_IRQ);
	}
}