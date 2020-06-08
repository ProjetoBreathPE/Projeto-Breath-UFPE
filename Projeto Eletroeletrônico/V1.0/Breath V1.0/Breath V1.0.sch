EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Diagrama Eletrônico - Projeto Breath"
Date ""
Rev "Igor Morimoto"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_Push SW1
U 1 1 5EBD242D
P 7250 3550
F 0 "SW1" H 7250 3835 50  0000 C CNN
F 1 "Silence/Reset" H 7250 3750 50  0000 C CNN
F 2 "" H 7250 3750 50  0001 C CNN
F 3 "~" H 7250 3750 50  0001 C CNN
	1    7250 3550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5EBD3E96
P 7250 3650
F 0 "SW2" H 7250 3550 50  0000 C CNN
F 1 "Confirmar" H 7250 3450 50  0000 C CNN
F 2 "" H 7250 3850 50  0001 C CNN
F 3 "~" H 7250 3850 50  0001 C CNN
	1    7250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3550 7050 3550
Wire Wire Line
	6800 3650 7050 3650
Wire Wire Line
	7450 3550 8000 3550
Wire Wire Line
	8000 3550 8000 3650
Wire Wire Line
	8000 3650 7450 3650
$Comp
L power:GND #PWR?
U 1 1 5EBDC8FF
P 8150 3900
F 0 "#PWR?" H 8150 3650 50  0001 C CNN
F 1 "GND" H 8155 3727 50  0000 C CNN
F 2 "" H 8150 3900 50  0001 C CNN
F 3 "" H 8150 3900 50  0001 C CNN
	1    8150 3900
	1    0    0    -1  
$EndComp
Connection ~ 8000 3650
$Comp
L Switch:SW_Push_SPDT SW3
U 1 1 5EBE19C4
P 7250 4350
F 0 "SW3" H 7700 4450 50  0000 C CNN
F 1 "Fim de Curso" H 7700 4350 50  0000 C CNN
F 2 "" H 7250 4350 50  0001 C CNN
F 3 "~" H 7250 4350 50  0001 C CNN
	1    7250 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 4450 8000 4450
Wire Wire Line
	8000 3650 8000 4450
Wire Wire Line
	8000 3650 8150 3650
Wire Wire Line
	8150 3650 8150 3900
$Comp
L Device:R_POT_US POT1
U 1 1 5EBE4197
P 2000 2650
F 0 "POT1" H 1932 2696 50  0000 R CNN
F 1 "10k" H 1932 2605 50  0000 R CNN
F 2 "" H 2000 2650 50  0001 C CNN
F 3 "~" H 2000 2650 50  0001 C CNN
	1    2000 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_US POT2
U 1 1 5EBE4665
P 2000 3100
F 0 "POT2" H 1932 3146 50  0000 R CNN
F 1 "10k" H 1932 3055 50  0000 R CNN
F 2 "" H 2000 3100 50  0001 C CNN
F 3 "~" H 2000 3100 50  0001 C CNN
	1    2000 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_US POT3
U 1 1 5EBE50D2
P 2000 3550
F 0 "POT3" H 1932 3596 50  0000 R CNN
F 1 "10k" H 1932 3505 50  0000 R CNN
F 2 "" H 2000 3550 50  0001 C CNN
F 3 "~" H 2000 3550 50  0001 C CNN
	1    2000 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_US POT4
U 1 1 5EBE5B68
P 2000 4000
F 0 "POT4" H 1932 4046 50  0000 R CNN
F 1 "10k" H 1932 3955 50  0000 R CNN
F 2 "" H 2000 4000 50  0001 C CNN
F 3 "~" H 2000 4000 50  0001 C CNN
	1    2000 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 2800 2000 2800
Wire Wire Line
	2000 3250 1700 3250
Connection ~ 1700 3250
Wire Wire Line
	1700 3250 1700 2800
Wire Wire Line
	2000 3700 1700 3700
Connection ~ 1700 3700
Wire Wire Line
	1700 3700 1700 3250
Wire Wire Line
	2000 4150 1700 4150
Connection ~ 1700 4150
Wire Wire Line
	1700 4150 1700 3700
Wire Wire Line
	4200 4750 2350 4750
Wire Wire Line
	2000 3850 2350 3850
Wire Wire Line
	2000 3400 2350 3400
Wire Wire Line
	2000 2950 2350 2950
Wire Wire Line
	2350 2500 2000 2500
Wire Wire Line
	4200 5350 1700 5350
Connection ~ 2350 2950
Wire Wire Line
	2350 2950 2350 3400
Connection ~ 2350 3400
Wire Wire Line
	2350 3400 2350 3850
Connection ~ 2350 3850
Wire Wire Line
	2350 3850 2350 4750
Wire Wire Line
	2150 2650 4200 2650
Wire Wire Line
	2350 2500 2350 2950
Wire Wire Line
	1700 4150 1700 5350
Wire Wire Line
	4200 2750 2400 2750
Wire Wire Line
	2400 2750 2400 3100
Wire Wire Line
	2400 3100 2150 3100
Wire Wire Line
	4200 2850 2450 2850
Wire Wire Line
	2450 2850 2450 3550
Wire Wire Line
	2450 3550 2150 3550
Wire Wire Line
	4200 2950 2500 2950
Wire Wire Line
	2500 2950 2500 4000
Wire Wire Line
	2500 4000 2150 4000
$Comp
L Device:Buzzer BZ1
U 1 1 5EC1028F
P 8550 4050
F 0 "BZ1" H 8702 4079 50  0000 L CNN
F 1 "Buzzer" H 8702 3988 50  0000 L CNN
F 2 "" V 8525 4150 50  0001 C CNN
F 3 "~" V 8525 4150 50  0001 C CNN
	1    8550 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3150 3650 3150
Wire Wire Line
	3650 4000 3300 4000
Wire Wire Line
	3650 3150 3650 4000
$Comp
L Sensor_Pressure:40PC015G U1
U 1 1 5EC237E7
P 3300 3600
F 0 "U1" V 2733 3600 50  0000 C CNN
F 1 "120 CMH2O-D1-4V-MINI" V 2824 3600 50  0000 C CNN
F 2 "" H 3400 3600 50  0001 C CNN
F 3 "" H 3400 3600 50  0001 C CNN
	1    3300 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 4850 3000 4850
Wire Wire Line
	3000 4850 3000 3600
Wire Wire Line
	3600 3600 3600 5450
Wire Wire Line
	3600 5450 4200 5450
$Comp
L Regulator_Linear:L7805 U2
U 1 1 5EC349AC
P 2300 6700
F 0 "U2" H 2300 6942 50  0000 C CNN
F 1 "L7805" H 2300 6851 50  0000 C CNN
F 2 "" H 2325 6550 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2300 6650 50  0001 C CNN
	1    2300 6700
	1    0    0    -1  
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5EC3AB4C
P 1450 6700
F 0 "#PWR?" H 1450 6550 50  0001 C CNN
F 1 "+24V" V 1465 6828 50  0000 L CNN
F 2 "" H 1450 6700 50  0001 C CNN
F 3 "" H 1450 6700 50  0001 C CNN
	1    1450 6700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4200 5650 2750 5650
Wire Wire Line
	2750 5650 2750 6700
Wire Wire Line
	2750 6700 2600 6700
$Comp
L power:GND #PWR?
U 1 1 5EBDBE9A
P 3850 6000
F 0 "#PWR?" H 3850 5750 50  0001 C CNN
F 1 "GND" H 3855 5827 50  0000 C CNN
F 2 "" H 3850 6000 50  0001 C CNN
F 3 "" H 3850 6000 50  0001 C CNN
	1    3850 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 7000 2300 7150
Wire Wire Line
	3700 7150 3700 5150
Wire Wire Line
	3700 5150 4200 5150
Wire Wire Line
	3850 6000 3850 5050
Wire Wire Line
	3850 5050 4200 5050
$Comp
L Device:LED D2
U 1 1 5EC52FCD
P 7700 2800
F 0 "D2" V 7739 2683 50  0000 R CNN
F 1 "LED ALARME" V 7648 2683 50  0000 R CNN
F 2 "" H 7700 2800 50  0001 C CNN
F 3 "~" H 7700 2800 50  0001 C CNN
	1    7700 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 2650 7700 2550
Wire Wire Line
	7400 2950 7400 3100
Wire Wire Line
	7400 3100 7700 3100
Wire Wire Line
	7700 3100 7700 2950
Wire Wire Line
	7700 3100 8000 3100
Wire Wire Line
	8000 3100 8000 3550
Connection ~ 7700 3100
Connection ~ 8000 3550
$Comp
L Device:LED D1
U 1 1 5EC50131
P 7400 2800
F 0 "D1" V 7450 3000 50  0000 R CNN
F 1 "LED PCT" V 7350 3200 50  0000 R CNN
F 2 "" H 7400 2800 50  0001 C CNN
F 3 "~" H 7400 2800 50  0001 C CNN
	1    7400 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7400 2650 7250 2650
$Comp
L Device:R_US R2
U 1 1 5EC5F217
P 7450 2550
F 0 "R2" V 7245 2550 50  0000 C CNN
F 1 "150R" V 7336 2550 50  0000 C CNN
F 2 "" V 7490 2540 50  0001 C CNN
F 3 "~" H 7450 2550 50  0001 C CNN
	1    7450 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	7700 2550 7600 2550
Wire Wire Line
	7300 2550 6800 2550
$Comp
L Device:R_US R1
U 1 1 5EC74A82
P 7100 2650
F 0 "R1" V 6850 2650 50  0000 C CNN
F 1 "150R" V 6950 2650 50  0000 C CNN
F 2 "" V 7140 2640 50  0001 C CNN
F 3 "~" H 7100 2650 50  0001 C CNN
	1    7100 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	6950 2650 6800 2650
$Comp
L Device:C C1
U 1 1 5EC75E36
P 2750 6900
F 0 "C1" H 2865 6946 50  0000 L CNN
F 1 "100nF" H 2865 6855 50  0000 L CNN
F 2 "" H 2788 6750 50  0001 C CNN
F 3 "~" H 2750 6900 50  0001 C CNN
	1    2750 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 6750 2750 6700
Connection ~ 2750 6700
Wire Wire Line
	2750 7050 2750 7150
Text GLabel 3850 2350 0    50   Input ~ 0
DisplaySDA
Text GLabel 3850 2450 0    50   Input ~ 0
DisplaySCL
Wire Wire Line
	3850 2350 4200 2350
Wire Wire Line
	3850 2450 4200 2450
Text GLabel 3850 2250 0    50   Output ~ 0
DisplayVCC
Text GLabel 3850 2150 0    50   Output ~ 0
DisplayGND
Wire Wire Line
	4200 4950 4050 4950
Wire Wire Line
	4050 4950 4050 2150
Wire Wire Line
	4050 2150 3850 2150
Wire Wire Line
	3850 2250 3900 2250
Wire Wire Line
	3900 2250 3900 5550
Wire Wire Line
	3900 5550 4200 5550
Wire Wire Line
	6800 4350 7050 4350
$Comp
L eventArduinoMega-rescue:Arduino_Mega2560_Shield-arduino-eventArduinoMega-rescue ArduinoMega
U 1 1 5EBCC92C
P 5500 3500
F 0 "ArduinoMega" H 5500 1119 60  0000 C CNN
F 1 "Arduino_Mega2560_Shield-arduino-eventArduinoMega-rescue" H 5500 1013 60  0001 C CNN
F 2 "" H 6200 6250 60  0001 C CNN
F 3 "" H 6200 6250 60  0001 C CNN
	1    5500 3500
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q1
U 1 1 5ECF21A6
P 8350 4850
F 0 "Q1" H 8554 4896 50  0000 L CNN
F 1 "2N7000" H 8554 4805 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8550 4775 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 8350 4850 50  0001 L CNN
	1    8350 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 5ECFF41E
P 7750 4850
F 0 "R3" V 7545 4850 50  0000 C CNN
F 1 "470" V 7636 4850 50  0000 C CNN
F 2 "" V 7790 4840 50  0001 C CNN
F 3 "~" H 7750 4850 50  0001 C CNN
	1    7750 4850
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R4
U 1 1 5ECFFD31
P 8450 4400
F 0 "R4" H 8518 4446 50  0000 L CNN
F 1 "820" H 8518 4355 50  0000 L CNN
F 2 "" V 8490 4390 50  0001 C CNN
F 3 "~" H 8450 4400 50  0001 C CNN
	1    8450 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 4850 7600 4850
Wire Wire Line
	7900 4850 8150 4850
$Comp
L power:GND #PWR?
U 1 1 5ED0676A
P 8450 5300
F 0 "#PWR?" H 8450 5050 50  0001 C CNN
F 1 "GND" H 8455 5127 50  0000 C CNN
F 2 "" H 8450 5300 50  0001 C CNN
F 3 "" H 8450 5300 50  0001 C CNN
	1    8450 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 4550 8450 4650
Text GLabel 7050 1550 2    50   Output ~ 0
DriverPul+
Text GLabel 7050 1650 2    50   Output ~ 0
DriverEn
Text GLabel 7050 1750 2    50   Output ~ 0
DriverDir
Text GLabel 7050 1450 2    50   Output ~ 0
DriverOPTO
Wire Wire Line
	7050 1550 6800 1550
Wire Wire Line
	7050 1650 6800 1650
Wire Wire Line
	6800 1750 7050 1750
Wire Wire Line
	2300 7150 2750 7150
$Comp
L power:VCC #PWR?
U 1 1 5ED41848
P 6950 1400
F 0 "#PWR?" H 6950 1250 50  0001 C CNN
F 1 "VCC" H 6967 1573 50  0000 C CNN
F 2 "" H 6950 1400 50  0001 C CNN
F 3 "" H 6950 1400 50  0001 C CNN
	1    6950 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 1450 6950 1450
Wire Wire Line
	6950 1450 6950 1400
Connection ~ 2750 7150
Wire Wire Line
	2750 7150 3700 7150
Wire Wire Line
	8450 5050 8450 5300
Wire Wire Line
	8450 4150 8450 4250
Wire Wire Line
	8450 3950 8450 700 
Wire Wire Line
	8450 700  1450 700 
Wire Wire Line
	1450 700  1450 6700
Connection ~ 1450 6700
Wire Wire Line
	1450 6700 2000 6700
$EndSCHEMATC
