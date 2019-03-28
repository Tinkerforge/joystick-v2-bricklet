#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Joystick Bricklet 2.0

# Handle incoming pressed callbacks
tinkerforge dispatch joystick-v2-bricklet $uid pressed &

# Set period for pressed callback to 0.01s (10ms)
tinkerforge call joystick-v2-bricklet $uid set-pressed-callback-configuration 10 true

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
