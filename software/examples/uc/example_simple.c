// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "bindings/hal_common.h"
#include "bindings/bricklet_joystick_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your Joystick Bricklet 2.0

void check(int rc, const char* msg);

void example_setup(TF_HalContext *hal);
void example_loop(TF_HalContext *hal);


static TF_JoystickV2 j;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_joystick_v2_create(&j, UID, hal), "create device object");

	// Get current position
	int16_t x, y;
	check(tf_joystick_v2_get_position(&j, &x, &y), "get position");

	tf_hal_printf("Position [X]: %I16d\n", x);
	tf_hal_printf("Position [Y]: %I16d\n", y);
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
