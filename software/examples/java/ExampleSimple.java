import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletJoystickV2;
import com.tinkerforge.BrickletJoystickV2.Position;

public class ExampleSimple {
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

		// Get current position
		Position position = j.getPosition(); // Can throw com.tinkerforge.TimeoutException

		System.out.println("Position [X]: " + position.x);
		System.out.println("Position [Y]: " + position.y);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
