using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Joystick Bricklet 2.0

	// Callback function for pressed callback
	static void PressedCB(BrickletJoystickV2 sender, bool pressed)
	{
		Console.WriteLine("Pressed: " + pressed);
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystickV2 j = new BrickletJoystickV2(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register pressed callback to function PressedCB
		j.PressedCallback += PressedCB;

		// Set period for pressed callback to 0.01s (10ms)
		j.SetPressedCallbackConfiguration(10, true);

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
