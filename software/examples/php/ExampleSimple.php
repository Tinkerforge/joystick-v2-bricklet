<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystickV2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystickV2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Joystick Bricklet 2.0

$ipcon = new IPConnection(); // Create IP connection
$j = new BrickletJoystickV2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current position
$position = $j->getPosition();

echo "Position [X]: " . $position['x'] . "\n";
echo "Position [Y]: " . $position['y'] . "\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
