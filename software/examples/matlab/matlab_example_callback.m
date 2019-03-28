function matlab_example_callback()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletJoystickV2;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Joystick Bricklet 2.0

    ipcon = IPConnection(); % Create IP connection
    j = handle(BrickletJoystickV2(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register pressed callback to function cb_pressed
    set(j, 'PressedCallback', @(h, e) cb_pressed(e));

    % Set period for pressed callback to 0.01s (10ms)
    j.setPressedCallbackConfiguration(10, true);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for pressed callback
function cb_pressed(e)
    fprintf('Pressed: %i\n', e.pressed);
end
