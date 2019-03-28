#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_joystick_v2'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your Joystick Bricklet 2.0

ipcon = IPConnection.new # Create IP connection
j = BrickletJoystickV2.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Register pressed callback
j.register_callback(BrickletJoystickV2::CALLBACK_PRESSED) do |pressed|
  puts "Pressed: #{pressed}"
end

# Set period for pressed callback to 0.01s (10ms)
j.set_pressed_callback_configuration 10, true

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
