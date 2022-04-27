// This example is not self-contained.
// It requires usage of the example driver specific to your platform.
// See the HAL documentation.

#include "src/bindings/hal_common.h"
#include "src/bindings/bricklet_joystick_v2.h"

void check(int rc, const char *msg);
void example_setup(TF_HAL *hal);
void example_loop(TF_HAL *hal);

// Callback function for pressed callback
static void pressed_handler(TF_JoystickV2 *device, bool pressed, void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	tf_hal_printf("Pressed: %s\n", pressed ? "true" : "false");
}

static TF_JoystickV2 j;

void example_setup(TF_HAL *hal) {
	// Create device object
	check(tf_joystick_v2_create(&j, NULL, hal), "create device object");

	// Register pressed callback to function pressed_handler
	tf_joystick_v2_register_pressed_callback(&j,
	                                         pressed_handler,
	                                         NULL);

	// Set period for pressed callback to 0.01s (10ms)
	tf_joystick_v2_set_pressed_callback_configuration(&j, 10, true);
}

void example_loop(TF_HAL *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
