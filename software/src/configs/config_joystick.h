/* joystick-v2-bricklet
 * Copyright (C) 2017 Olaf Lüke <olaf@tinkerforge.com>
 *
 * config_joystick.h: Joystick configuration
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

#ifndef CONFIG_JOYSTICK_H
#define CONFIG_JOYSTICK_H

#define JOYSTICK_SWITCH_PIN         P0_7

#define JOYSTICK_ADC_X_CHANNEL      4 // P2_11
#define JOYSTICK_ADC_Y_CHANNEL      7 // P2_2

#define JOYSTICK_ADC_IRQ            15
#define JOYSTICK_ADC_IRQ_PRIORITY   0

#endif
