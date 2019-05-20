use std::{error::Error, io, thread};
use tinkerforge::{ip_connection::IpConnection, joystick_v2_bricklet::*};

const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Joystick Bricklet 2.0.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let j = JoystickV2Bricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
                                          // Don't use device before ipcon is connected.

    let pressed_receiver = j.get_pressed_callback_receiver();

    // Spawn thread to handle received callback messages.
    // This thread ends when the `j` object
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for pressed in pressed_receiver {
            println!("Pressed: {}", pressed);
        }
    });

    // Set period for pressed callback to 0.01s (10ms).
    j.set_pressed_callback_configuration(10, true);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
