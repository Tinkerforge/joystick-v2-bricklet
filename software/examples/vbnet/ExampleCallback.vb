Imports System
Imports Tinkerforge

Module ExampleCallback
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Joystick Bricklet 2.0

    ' Callback subroutine for pressed callback
    Sub PressedCB(ByVal sender As BrickletJoystickV2, ByVal pressed As Boolean)
        Console.WriteLine("Pressed: " + pressed.ToString())
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim j As New BrickletJoystickV2(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Register pressed callback to subroutine PressedCB
        AddHandler j.PressedCallback, AddressOf PressedCB

        ' Set period for pressed callback to 0.01s (10ms)
        j.SetPressedCallbackConfiguration(10, True)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
