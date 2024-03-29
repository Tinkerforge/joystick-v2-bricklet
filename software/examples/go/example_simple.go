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

	// Get current position.
	x, y, _ := j.GetPosition()

	fmt.Printf("Position [X]: %d\n", x)
	fmt.Printf("Position [Y]: %d\n", y)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
