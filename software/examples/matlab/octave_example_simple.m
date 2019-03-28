function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Joystick Bricklet 2.0

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    j = javaObject("com.tinkerforge.BrickletJoystickV2", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position
    position = j.getPosition();

    fprintf("Position [X]: %d\n", position.x);
    fprintf("Position [Y]: %d\n", position.y);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
