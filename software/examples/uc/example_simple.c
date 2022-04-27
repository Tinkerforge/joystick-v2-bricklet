// This example is not self-contained.
// It requires usage of the example driver specific to your platform.
// See the HAL documentation.

#include "src/bindings/hal_common.h"
#include "src/bindings/bricklet_joystick_v2.h"

void check(int rc, const char *msg);
void example_setup(TF_HAL *hal);
void example_loop(TF_HAL *hal);

static TF_JoystickV2 j;

void example_setup(TF_HAL *hal) {
	// Create device object
	check(tf_joystick_v2_create(&j, NULL, hal), "create device object");

	// Get current position
	int16_t x, y;
	check(tf_joystick_v2_get_position(&j, &x, &y), "get position");

	tf_hal_printf("Position [X]: %I16d\n", x);
	tf_hal_printf("Position [Y]: %I16d\n", y);
}

void example_loop(TF_HAL *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
