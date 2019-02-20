/* joystick-v2-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * joystick.h: Joystick driver
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

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdint.h>
#include <stdbool.h>

#define JOYSTICK_CALIBRATION_PAGE 1
#define JOYSTICK_CALIBRATION_MAGIC 0x12345678
#define JOYSTICK_CALIBRATION_MAGIC_POS 0
#define JOYSTICK_CALIBRATION_X_POS 1
#define JOYSTICK_CALIBRATION_Y_POS 2

typedef struct {
    int16_t x;
    int16_t y;
    bool pressed;

    bool calibrate;
    
    int16_t x_cal;
    int16_t y_cal;
} Joystick;

extern Joystick joystick;

void joystick_init(void);
void joystick_tick(void);

#endif
