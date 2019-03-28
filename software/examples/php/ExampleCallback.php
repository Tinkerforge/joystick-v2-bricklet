<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystickV2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystickV2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Joystick Bricklet 2.0

// Callback function for pressed callback
function cb_pressed($pressed)
{
    echo "Pressed: $pressed\n";
}

$ipcon = new IPConnection(); // Create IP connection
$j = new BrickletJoystickV2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Register pressed callback to function cb_pressed
$j->registerCallback(BrickletJoystickV2::CALLBACK_PRESSED, 'cb_pressed');

// Set period for pressed callback to 0.01s (10ms)
$j->setPressedCallbackConfiguration(10, TRUE);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
