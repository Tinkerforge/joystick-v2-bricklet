var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your Joystick Bricklet 2.0

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var j = new Tinkerforge.BrickletJoystickV2(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Set period for pressed callback to 0.01s (10ms)
        j.setPressedCallbackConfiguration(10, true);
    }
);

// Register pressed callback
j.on(Tinkerforge.BrickletJoystickV2.CALLBACK_PRESSED,
    // Callback function for pressed callback
    function (pressed) {
        console.log('Pressed: ' + pressed);
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
