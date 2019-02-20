/* joystick-v2-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.h: TFP protocol message handling
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

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/bootloader/bootloader.h"

// Default functions
BootloaderHandleMessageResponse handle_message(const void *data, void *response);
void communication_tick(void);
void communication_init(void);

// Constants
#define JOYSTICK_V2_BOOTLOADER_MODE_BOOTLOADER 0
#define JOYSTICK_V2_BOOTLOADER_MODE_FIRMWARE 1
#define JOYSTICK_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2
#define JOYSTICK_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3
#define JOYSTICK_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

#define JOYSTICK_V2_BOOTLOADER_STATUS_OK 0
#define JOYSTICK_V2_BOOTLOADER_STATUS_INVALID_MODE 1
#define JOYSTICK_V2_BOOTLOADER_STATUS_NO_CHANGE 2
#define JOYSTICK_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3
#define JOYSTICK_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4
#define JOYSTICK_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

#define JOYSTICK_V2_STATUS_LED_CONFIG_OFF 0
#define JOYSTICK_V2_STATUS_LED_CONFIG_ON 1
#define JOYSTICK_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2
#define JOYSTICK_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

// Function and callback IDs and structs
#define FID_GET_POSITION 1
#define FID_IS_PRESSED 2
#define FID_CALIBRATE 3
#define FID_SET_POSITION_CALLBACK_CONFIGURATION 4
#define FID_GET_POSITION_CALLBACK_CONFIGURATION 5
#define FID_SET_PRESSED_CALLBACK_CONFIGURATION 7
#define FID_GET_PRESSED_CALLBACK_CONFIGURATION 8

#define FID_CALLBACK_POSITION 6
#define FID_CALLBACK_PRESSED 9

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetPosition;

typedef struct {
	TFPMessageHeader header;
	int16_t x;
	int16_t y;
} __attribute__((__packed__)) GetPosition_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) IsPressed;

typedef struct {
	TFPMessageHeader header;
	bool pressed;
} __attribute__((__packed__)) IsPressed_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) Calibrate;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) SetPositionCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetPositionCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) GetPositionCallbackConfiguration_Response;

typedef struct {
	TFPMessageHeader header;
	int16_t x;
	int16_t y;
} __attribute__((__packed__)) Position_Callback;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) SetPressedCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetPressedCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) GetPressedCallbackConfiguration_Response;

typedef struct {
	TFPMessageHeader header;
	bool pressed;
} __attribute__((__packed__)) Pressed_Callback;


// Function prototypes
BootloaderHandleMessageResponse get_position(const GetPosition *data, GetPosition_Response *response);
BootloaderHandleMessageResponse is_pressed(const IsPressed *data, IsPressed_Response *response);
BootloaderHandleMessageResponse calibrate(const Calibrate *data);
BootloaderHandleMessageResponse set_position_callback_configuration(const SetPositionCallbackConfiguration *data);
BootloaderHandleMessageResponse get_position_callback_configuration(const GetPositionCallbackConfiguration *data, GetPositionCallbackConfiguration_Response *response);
BootloaderHandleMessageResponse set_pressed_callback_configuration(const SetPressedCallbackConfiguration *data);
BootloaderHandleMessageResponse get_pressed_callback_configuration(const GetPressedCallbackConfiguration *data, GetPressedCallbackConfiguration_Response *response);

// Callbacks
bool handle_position_callback(void);
bool handle_pressed_callback(void);

#define COMMUNICATION_CALLBACK_TICK_WAIT_MS 1
#define COMMUNICATION_CALLBACK_HANDLER_NUM 2
#define COMMUNICATION_CALLBACK_LIST_INIT \
	handle_position_callback, \
	handle_pressed_callback, \


#endif
