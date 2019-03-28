#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickletJoystickV2;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Joystick Bricklet 2.0

# Callback subroutine for pressed callback
sub cb_pressed
{
    my ($pressed) = @_;

    print "Pressed: $pressed\n";
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $j = Tinkerforge::BrickletJoystickV2->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Register pressed callback to subroutine cb_pressed
$j->register_callback($j->CALLBACK_PRESSED, 'cb_pressed');

# Set period for pressed callback to 0.01s (10ms)
$j->set_pressed_callback_configuration(10, 1);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
