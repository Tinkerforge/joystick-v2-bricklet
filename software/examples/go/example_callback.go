package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/joystick_v2_bricklet"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Joystick Bricklet 2.0.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	j, _ := joystick_v2_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	j.RegisterPressedCallback(func(pressed bool) {
		fmt.Printf("Pressed: %s\n", pressed)
	})

	// Set period for pressed callback to 0.01s (10ms).
	j.SetPressedCallbackConfiguration(10, true)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
