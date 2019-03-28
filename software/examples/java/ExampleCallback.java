import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletJoystickV2;

public class ExampleCallback {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your Joystick Bricklet 2.0
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystickV2 j = new BrickletJoystickV2(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Add pressed listener
		j.addPressedListener(new BrickletJoystickV2.PressedListener() {
			public void pressed(boolean pressed) {
				System.out.println("Pressed: " + pressed);
			}
		});

		// Set period for pressed callback to 0.01s (10ms)
		j.setPressedCallbackConfiguration(10, true);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
