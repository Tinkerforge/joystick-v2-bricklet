/* joystick-v2-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.c: TFP protocol message handling
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

#include "communication.h"

#include "bricklib2/utility/communication_callback.h"
#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/hal/system_timer/system_timer.h"

#include "joystick.h"

BootloaderHandleMessageResponse handle_message(const void *message, void *response) {
	switch(tfp_get_fid_from_message(message)) {
		case FID_GET_POSITION: return get_position(message, response);
		case FID_IS_PRESSED: return is_pressed(message, response);
		case FID_CALIBRATE: return calibrate(message);
		case FID_SET_POSITION_CALLBACK_CONFIGURATION: return set_position_callback_configuration(message);
		case FID_GET_POSITION_CALLBACK_CONFIGURATION: return get_position_callback_configuration(message, response);
		case FID_SET_PRESSED_CALLBACK_CONFIGURATION: return set_pressed_callback_configuration(message);
		case FID_GET_PRESSED_CALLBACK_CONFIGURATION: return get_pressed_callback_configuration(message, response);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
}


BootloaderHandleMessageResponse get_position(const GetPosition *data, GetPosition_Response *response) {
	response->header.length = sizeof(GetPosition_Response);
	response->x             = joystick.x;
	response->y             = joystick.y;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse is_pressed(const IsPressed *data, IsPressed_Response *response) {
	response->header.length = sizeof(IsPressed_Response);
	response->pressed       = joystick.pressed;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse calibrate(const Calibrate *data) {
	joystick.calibrate = true;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse set_position_callback_configuration(const SetPositionCallbackConfiguration *data) {
	joystick.position_callback_period              = data->period;
	joystick.position_callback_value_has_to_change = data->value_has_to_change;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_position_callback_configuration(const GetPositionCallbackConfiguration *data, GetPositionCallbackConfiguration_Response *response) {
	response->header.length       = sizeof(GetPositionCallbackConfiguration_Response);
	response->period              = joystick.position_callback_period;
	response->value_has_to_change = joystick.position_callback_value_has_to_change;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_pressed_callback_configuration(const SetPressedCallbackConfiguration *data) {
	joystick.pressed_callback_period              = data->period;
	joystick.pressed_callback_value_has_to_change = data->value_has_to_change;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_pressed_callback_configuration(const GetPressedCallbackConfiguration *data, GetPressedCallbackConfiguration_Response *response) {
	response->header.length       = sizeof(GetPressedCallbackConfiguration_Response);
	response->period              = joystick.pressed_callback_period;
	response->value_has_to_change = joystick.pressed_callback_value_has_to_change;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}




bool handle_position_callback(void) {
	static bool is_buffered = false;
	static Position_Callback cb;
	static int16_t last_x = 0;
	static int16_t last_y = 0;
	static uint32_t last_time = 0;

	if(!is_buffered) {
		if(joystick.position_callback_period == 0 ||
		    !system_timer_is_time_elapsed_ms(last_time, joystick.position_callback_period)) {
			return false;
		}

		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(Position_Callback), FID_CALLBACK_POSITION);
		cb.x = joystick.x;
		cb.y = joystick.y;

		if(joystick.position_callback_value_has_to_change && (last_x == cb.x) && (last_y == cb.y)) {
			return false;
		}
		
		last_x    = cb.x;
		last_y    = cb.y;
		last_time = system_timer_get_ms();
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(Position_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

bool handle_pressed_callback(void) {
	static bool is_buffered = false;
	static Pressed_Callback cb;
	static bool last_pressed = false;
	static uint32_t last_time = 0;

	if(!is_buffered) {
		if(joystick.pressed_callback_period == 0 ||
		    !system_timer_is_time_elapsed_ms(last_time, joystick.pressed_callback_period)) {
			return false;
		}

		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(Pressed_Callback), FID_CALLBACK_PRESSED);
		cb.pressed = joystick.pressed;

		if(joystick.pressed_callback_value_has_to_change && (last_pressed == cb.pressed)) {
			return false;
		}

		last_pressed = cb.pressed;
		last_time = system_timer_get_ms();
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(Pressed_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

void communication_tick(void) {
	communication_callback_tick();
}

void communication_init(void) {
	communication_callback_init();
}
