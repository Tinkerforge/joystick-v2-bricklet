function octave_example_callback()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Joystick Bricklet 2.0

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    j = javaObject("com.tinkerforge.BrickletJoystickV2", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register pressed callback to function cb_pressed
    j.addPressedCallback(@cb_pressed);

    % Set period for pressed callback to 0.01s (10ms)
    j.setPressedCallbackConfiguration(10, true);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

% Callback function for pressed callback
function cb_pressed(e)
    fprintf("Pressed: %d\n", e.pressed);
end
