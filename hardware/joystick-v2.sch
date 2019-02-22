EESchema Schematic File Version 4
LIBS:power
LIBS:74xx
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Joystick Bricklet"
Date "2018-05-18"
Rev "2.0"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2018, L.Lauer <lukas@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	8300 3200 8700 3200
Connection ~ 8600 3650
Wire Wire Line
	8600 4500 8600 3650
Wire Wire Line
	8600 3300 8700 3300
Connection ~ 8450 3450
Wire Wire Line
	8700 3450 8450 3450
Wire Wire Line
	8450 2900 8450 3100
Wire Wire Line
	8450 4500 8450 4400
Wire Wire Line
	8700 3900 8450 3900
Connection ~ 8450 3900
Wire Wire Line
	8450 3800 8700 3800
Wire Wire Line
	8700 3100 8450 3100
Connection ~ 8450 3100
Wire Wire Line
	8600 3650 8700 3650
Wire Wire Line
	8300 3550 8700 3550
Text Notes 550  7750 0    40   ~ 0
Copyright Tinkerforge GmbH 2018.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
Text GLabel 4700 5850 0    47   Input ~ 0
X
Text GLabel 4700 5350 0    47   Input ~ 0
Y
Text GLabel 8300 3550 0    47   Output ~ 0
X
Text GLabel 8300 3200 0    47   Output ~ 0
Y
$Comp
L tinkerforge:GND #PWR01
U 1 1 4CF8E9C4
P 8600 4500
F 0 "#PWR01" H 8600 4500 30  0001 C CNN
F 1 "GND" H 8600 4430 30  0001 C CNN
F 2 "" H 8600 4500 60  0001 C CNN
F 3 "" H 8600 4500 60  0001 C CNN
	1    8600 4500
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:VCC #PWR02
U 1 1 4CF8E8F2
P 8450 2900
F 0 "#PWR02" H 8450 3000 30  0001 C CNN
F 1 "VCC" H 8450 3000 30  0000 C CNN
F 2 "" H 8450 2900 60  0001 C CNN
F 3 "" H 8450 2900 60  0001 C CNN
	1    8450 2900
	1    0    0    -1  
$EndComp
Text GLabel 4500 3000 0    47   Input ~ 0
SWITCH
$Comp
L tinkerforge:GND #PWR03
U 1 1 4CF8E8AF
P 8450 4500
F 0 "#PWR03" H 8450 4500 30  0001 C CNN
F 1 "GND" H 8450 4430 30  0001 C CNN
F 2 "" H 8450 4500 60  0001 C CNN
F 3 "" H 8450 4500 60  0001 C CNN
	1    8450 4500
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:R R3
U 1 1 4CF8E8A8
P 8450 4150
F 0 "R3" V 8530 4150 50  0000 C CNN
F 1 "10k" V 8450 4150 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 8450 4150 60  0001 C CNN
F 3 "" H 8450 4150 60  0001 C CNN
	1    8450 4150
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:JOYSTICK_BUTTON U3
U 1 1 4CF8E827
P 9350 3500
F 0 "U3" H 8950 4050 60  0000 C CNN
F 1 "JOYSTICK_BUTTON" H 9350 3050 60  0000 C CNN
F 2 "kicad-libraries:Joystick_Button" H 9350 3500 60  0001 C CNN
F 3 "" H 9350 3500 60  0001 C CNN
	1    9350 3500
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:DRILL U4
U 1 1 4C6534CF
P 10700 6200
F 0 "U4" H 10750 6250 60  0001 C CNN
F 1 "DRILL" H 10700 6200 60  0000 C CNN
F 2 "kicad-libraries:DRILL_NP" H 10700 6200 60  0001 C CNN
F 3 "" H 10700 6200 60  0001 C CNN
	1    10700 6200
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:DRILL U5
U 1 1 4C6534CD
P 10700 6400
F 0 "U5" H 10750 6450 60  0001 C CNN
F 1 "DRILL" H 10700 6400 60  0000 C CNN
F 2 "kicad-libraries:DRILL_NP" H 10700 6400 60  0001 C CNN
F 3 "" H 10700 6400 60  0001 C CNN
	1    10700 6400
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:DRILL U7
U 1 1 4C6534CA
P 11000 6400
F 0 "U7" H 11050 6450 60  0001 C CNN
F 1 "DRILL" H 11000 6400 60  0000 C CNN
F 2 "kicad-libraries:DRILL_NP" H 11000 6400 60  0001 C CNN
F 3 "" H 11000 6400 60  0001 C CNN
	1    11000 6400
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:DRILL U6
U 1 1 4C6534C3
P 11000 6200
F 0 "U6" H 11050 6250 60  0001 C CNN
F 1 "DRILL" H 11000 6200 60  0000 C CNN
F 2 "kicad-libraries:DRILL_NP" H 11000 6200 60  0001 C CNN
F 3 "" H 11000 6200 60  0001 C CNN
	1    11000 6200
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:VCC #PWR04
U 1 1 4C5FD35E
P 2400 1000
F 0 "#PWR04" H 2400 1100 30  0001 C CNN
F 1 "VCC" H 2400 1100 30  0000 C CNN
F 2 "" H 2400 1000 60  0001 C CNN
F 3 "" H 2400 1000 60  0001 C CNN
	1    2400 1000
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR05
U 1 1 4C5FCF4F
P 2400 1600
F 0 "#PWR05" H 2400 1600 30  0001 C CNN
F 1 "GND" H 2400 1530 30  0001 C CNN
F 2 "" H 2400 1600 60  0001 C CNN
F 3 "" H 2400 1600 60  0001 C CNN
	1    2400 1600
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:C C1
U 1 1 4CE528C6
P 2000 1300
F 0 "C1" V 1850 1300 50  0000 L CNN
F 1 "10uF" V 2100 1300 50  0000 L CNN
F 2 "kicad-libraries:C0805" H 2000 1300 60  0001 C CNN
F 3 "" H 2000 1300 60  0001 C CNN
	1    2000 1300
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:CON-SENSOR2 P1
U 1 1 5AFE965B
P 1200 1750
F 0 "P1" H 1050 2150 60  0000 C CNN
F 1 "CON-SENSOR2" V 1350 1750 60  0000 C CNN
F 2 "kicad-libraries:CON-SENSOR2" H 1300 1600 60  0001 C CNN
F 3 "" H 1300 1600 60  0000 C CNN
	1    1200 1750
	-1   0    0    -1  
$EndComp
$Comp
L tinkerforge:C C4
U 1 1 5AFE9972
P 2400 1300
F 0 "C4" V 2250 1300 50  0000 L CNN
F 1 "1uF" V 2500 1300 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 2400 1300 60  0001 C CNN
F 3 "" H 2400 1300 60  0001 C CNN
	1    2400 1300
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:R_PACK4 RP1
U 1 1 5AFE9BD4
P 2050 2100
F 0 "RP1" H 2050 2550 50  0000 C CNN
F 1 "82" H 2050 2050 50  0000 C CNN
F 2 "kicad-libraries:4X0402" H 2050 2100 50  0001 C CNN
F 3 "" H 2050 2100 50  0000 C CNN
	1    2050 2100
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:C C3
U 1 1 5AFE9CCD
P 1700 2300
F 0 "C3" V 1550 2300 50  0000 L CNN
F 1 "220pF" V 1800 2300 50  0000 L CNN
F 2 "kicad-libraries:C0402E" H 1700 2300 60  0001 C CNN
F 3 "" H 1700 2300 60  0001 C CNN
	1    1700 2300
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:GND #PWR06
U 1 1 5AFE9E08
P 1700 2550
F 0 "#PWR06" H 1700 2550 30  0001 C CNN
F 1 "GND" H 1700 2480 30  0001 C CNN
F 2 "" H 1700 2550 60  0001 C CNN
F 3 "" H 1700 2550 60  0001 C CNN
	1    1700 2550
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR07
U 1 1 5AFE9E34
P 1200 2550
F 0 "#PWR07" H 1200 2550 30  0001 C CNN
F 1 "GND" H 1200 2480 30  0001 C CNN
F 2 "" H 1200 2550 60  0001 C CNN
F 3 "" H 1200 2550 60  0001 C CNN
	1    1200 2550
	1    0    0    -1  
$EndComp
Text GLabel 2650 1750 2    47   Output ~ 0
S-CS
Text GLabel 2650 1850 2    47   Output ~ 0
S-CLK
Text GLabel 2650 1950 2    47   Output ~ 0
S-MOSI
Text GLabel 2650 2050 2    47   Input ~ 0
S-MISO
Wire Wire Line
	1550 1750 1850 1750
Wire Wire Line
	2250 1750 2650 1750
Wire Wire Line
	2650 1850 2250 1850
Wire Wire Line
	2250 1950 2650 1950
Wire Wire Line
	2650 2050 2250 2050
Wire Wire Line
	1850 1850 1550 1850
Wire Wire Line
	1550 1950 1850 1950
Wire Wire Line
	1850 2050 1700 2050
Wire Wire Line
	1700 2100 1700 2050
Connection ~ 1700 2050
Wire Wire Line
	1700 2550 1700 2500
Wire Wire Line
	1200 2200 1200 2550
Wire Wire Line
	1550 1650 1750 1650
Wire Wire Line
	1750 1650 1750 1050
Wire Wire Line
	1750 1050 2000 1050
Wire Wire Line
	2400 1000 2400 1050
Connection ~ 2400 1050
Wire Wire Line
	2000 1100 2000 1050
Connection ~ 2000 1050
Wire Wire Line
	1550 1550 2000 1550
Wire Wire Line
	2000 1550 2000 1500
Wire Wire Line
	2400 1500 2400 1550
Connection ~ 2000 1550
Connection ~ 2400 1550
NoConn ~ 1550 1450
Text GLabel 8300 3900 0    47   Output ~ 0
SWITCH
$Comp
L tinkerforge:XMC1XXX24 U1
U 1 1 5AFECB86
P 5200 6950
F 0 "U1" H 5050 7350 60  0000 C CNN
F 1 "XMC1100" H 5200 6550 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 5350 7700 60  0001 C CNN
F 3 "" H 5350 7700 60  0000 C CNN
	1    5200 6950
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:XMC1XXX24 U1
U 2 1 5AFECC7B
P 5200 3150
F 0 "U1" H 5050 3700 60  0000 C CNN
F 1 "XMC1100" H 5200 2600 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 5350 3900 60  0001 C CNN
F 3 "" H 5350 3900 60  0000 C CNN
	2    5200 3150
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:XMC1XXX24 U1
U 3 1 5AFECCD0
P 5200 4300
F 0 "U1" H 5050 4550 60  0000 C CNN
F 1 "XMC1100" H 5200 4050 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 5350 5050 60  0001 C CNN
F 3 "" H 5350 5050 60  0000 C CNN
	3    5200 4300
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:XMC1XXX24 U1
U 4 1 5AFECD22
P 5200 5500
F 0 "U1" H 5050 5950 60  0000 C CNN
F 1 "XMC1100" H 5200 5050 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 5350 6250 60  0001 C CNN
F 3 "" H 5350 6250 60  0000 C CNN
	4    5200 5500
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR08
U 1 1 5AFED5D7
P 4700 7300
F 0 "#PWR08" H 4700 7300 30  0001 C CNN
F 1 "GND" H 4700 7230 30  0001 C CNN
F 2 "" H 4700 7300 60  0001 C CNN
F 3 "" H 4700 7300 60  0001 C CNN
	1    4700 7300
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:VCC #PWR09
U 1 1 5AFED62D
P 4700 6600
F 0 "#PWR09" H 4700 6700 30  0001 C CNN
F 1 "VCC" H 4700 6700 30  0000 C CNN
F 2 "" H 4700 6600 60  0001 C CNN
F 3 "" H 4700 6600 60  0001 C CNN
	1    4700 6600
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:C C2
U 1 1 5AFED665
P 4700 6900
F 0 "C2" V 4550 6900 50  0000 L CNN
F 1 "100nF" V 4800 6900 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 4700 6900 60  0001 C CNN
F 3 "" H 4700 6900 60  0001 C CNN
	1    4700 6900
	-1   0    0    1   
$EndComp
Wire Wire Line
	4850 6650 4700 6650
Wire Wire Line
	4700 6600 4700 6650
Connection ~ 4700 6650
Wire Wire Line
	4700 7300 4700 7250
Wire Wire Line
	4700 7150 4850 7150
Connection ~ 4700 7150
Wire Wire Line
	4850 7250 4700 7250
Connection ~ 4700 7250
NoConn ~ 4850 4150
NoConn ~ 4850 4250
NoConn ~ 4850 4350
NoConn ~ 4850 4450
$Comp
L tinkerforge:CONN_01X01 P2
U 1 1 5AFEE8E5
P 4300 2700
F 0 "P2" H 4300 2800 50  0000 C CNN
F 1 "DEBUG" V 4400 2700 50  0000 C CNN
F 2 "kicad-libraries:DEBUG_PAD" H 4300 2700 50  0001 C CNN
F 3 "" H 4300 2700 50  0000 C CNN
	1    4300 2700
	-1   0    0    1   
$EndComp
Text GLabel 4500 3400 0    47   Input ~ 0
S-CS
Text GLabel 4500 3500 0    47   Input ~ 0
S-CLK
Text GLabel 4500 3600 0    47   Input ~ 0
S-MOSI
Text GLabel 4500 5150 0    47   Output ~ 0
S-MISO
Text Notes 2800 3650 0    39   ~ 0
SPI Slave/CH0\nP0.13 : USIC0_CH0-DX2F : SEL\nP0.14 : USIC0_CH0-DX1A : CLK\nP0.15 : USIC0_CH0-DX0B : MOSI\nP2.0 : USIC0_CH0-DOUT0 : MISO
Wire Wire Line
	4500 2700 4850 2700
Wire Wire Line
	4850 3400 4500 3400
Wire Wire Line
	4500 3500 4850 3500
Wire Wire Line
	4850 3600 4500 3600
$Comp
L tinkerforge:CONN_01X02 P3
U 1 1 5AFF00C3
P 4000 5300
F 0 "P3" H 4000 5450 50  0000 C CNN
F 1 "BOOT" V 4100 5300 50  0000 C CNN
F 2 "kicad-libraries:SolderJumper" H 4000 5300 50  0001 C CNN
F 3 "" H 4000 5300 50  0000 C CNN
	1    4000 5300
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:GND #PWR010
U 1 1 5AFF0520
P 4350 5400
F 0 "#PWR010" H 4350 5400 30  0001 C CNN
F 1 "GND" H 4350 5330 30  0001 C CNN
F 2 "" H 4350 5400 60  0001 C CNN
F 3 "" H 4350 5400 60  0001 C CNN
	1    4350 5400
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:R R1
U 1 1 5AFF0821
P 4400 5750
F 0 "R1" V 4480 5750 50  0000 C CNN
F 1 "1k" V 4400 5750 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 4400 5750 60  0001 C CNN
F 3 "" H 4400 5750 60  0000 C CNN
	1    4400 5750
	0    1    1    0   
$EndComp
$Comp
L tinkerforge:LED D1
U 1 1 5AFF0A05
P 3900 5750
F 0 "D1" H 3900 5850 50  0000 C CNN
F 1 "blue" H 3900 5650 50  0000 C CNN
F 2 "kicad-libraries:D0603F" H 3900 5750 50  0001 C CNN
F 3 "" H 3900 5750 50  0000 C CNN
	1    3900 5750
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:VCC #PWR011
U 1 1 5AFF124E
P 3650 5700
F 0 "#PWR011" H 3650 5800 30  0001 C CNN
F 1 "VCC" H 3650 5800 30  0000 C CNN
F 2 "" H 3650 5700 60  0001 C CNN
F 3 "" H 3650 5700 60  0001 C CNN
	1    3650 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 5750 4650 5750
Wire Wire Line
	4150 5750 4100 5750
Wire Wire Line
	3700 5750 3650 5750
Wire Wire Line
	3650 5750 3650 5700
Wire Wire Line
	4850 5150 4500 5150
Wire Wire Line
	4850 3000 4500 3000
Wire Wire Line
	4850 5350 4700 5350
Wire Wire Line
	4700 5850 4850 5850
Text Notes 2500 5600 0    39   ~ 0
INPUT\nP2.2 : VADC0.G0CH7 : Y\nP2.11 : VADC0.G1CH3 : X\n
Wire Wire Line
	4200 5250 4850 5250
Wire Wire Line
	4200 5350 4350 5350
Wire Wire Line
	4350 5350 4350 5400
Wire Wire Line
	8600 3650 8600 3300
Wire Wire Line
	8450 3450 8450 3800
Wire Wire Line
	8450 3900 8300 3900
Wire Wire Line
	8450 3100 8450 3450
Wire Wire Line
	1700 2050 1550 2050
Wire Wire Line
	2400 1050 2400 1100
Wire Wire Line
	2000 1050 2400 1050
Wire Wire Line
	2000 1550 2400 1550
Wire Wire Line
	2400 1550 2400 1600
Wire Wire Line
	4700 6650 4700 6700
Wire Wire Line
	4700 7150 4700 7100
Wire Wire Line
	4700 7250 4700 7150
$EndSCHEMATC
