# PIC16F877A_LABS

Software Tools I am going to use throughout the series of these virtual labs are as follows:
- Programming Language: C
- IDE (Integrated Development Environment): MPLAB X
- Compiler: xc8 
- Simulator & Schematic capture: Proteus PRO
- VCS (Version control System): Git and GitBash
- Online server: Github

 Resources:
 https://deepbluembedded.com/pic-programming-tutorials/
 [Deep Blue](https://deepbluembedded.com/pic-programming-tutorials/)
 

## Lab 1: Flashing Leds
In this Lab GPIO pins of the MCU are used to generate digital output signal for flashing RED, BLUE and GREEN LEDS.
## Proteus Simulation & Schematic capture
![lab1](https://github.com/user-attachments/assets/4d7629dc-a67f-47fd-8336-293fb9f688a8)

---------------------------------------------------------------------------------------------------------------------------
## Lab 2: Reading digital inputs
In this Lab GPIO pins of the PIC are used for reading digital input signal, which is then used to control the flashing of an LED (BLUE)
## Schematic capture and Proteus Simulation
![lab2](https://github.com/user-attachments/assets/37fd38ab-6bbd-44a4-af92-cd852cc0be19)

-----------------------------------------------------------------------------------------------------------------------------
## Lab 3: Counting with 7 Segments Display
In this lab it will be demonstrated how to use GPIO to control and interface the Segment to PIC16F877A MCU.
Main aim of this lab is to print out numerical data (0 -9) using 7 Segment display

## Schematic capture and Proteus simulation
![lab3](https://github.com/user-attachments/assets/fbd3ebef-0f6e-46ae-8ec3-e854b222496b)

----------------------------------------------------------------------------------------------------------------------------
## Lab 4: Driving Stepper Motor (Unipolar)
The main obejectives of this laboratory are to operate the stepper motors and develop the necessary firmware that will make the
motor complete one full clockwise (CW) rotation, followed by a counterclockwise (CCW) rotation. Finally, a hardware circuitry will be built
to ensure proper operation of the motor.

## Schematic capture and Proteus Simulation
![lab4](https://github.com/user-attachments/assets/f253d26d-e29e-447d-b6b1-b8275e4daa7f)

----------------------------------------------------------------------------------------------------------------------------
## Lab 5: Stepper Motor Controlled Motion
The primary goals of this lab is to drive stepper motors by writing the neceessary firmware that will make the motor rotate CW
(clockwise) when one input button is pressed and rotate CCW (counterclockwise) when another button is pressed.

## Schematic capture and Proteus Simulation
![lab5](https://github.com/user-attachments/assets/e395300b-7b5f-47c3-b313-d72da9951f04)

-----------------------------------------------------------------------------------------------------------------------------
## Lab 6: Stepper Motor Speed control
In this Lab a firmware will be written to make this stepper motor rotate at different speed levels and hardware circuitry
will be built to ensure the stepper motor operates as desired.

## Schematic capture and simulation (Proteus)
![lab6](https://github.com/user-attachments/assets/435b9edf-0ca3-459b-b839-facb05fb2ba3)

## Lab 7: Polling vs Interrupt-driven system
The main aim of this is to demonstrate fast reponse of the interrupt driven system compared to low responsivenes of a
system based on polling method.

## Schematic capture and simulation (Proteus)
![lab7](https://github.com/user-attachments/assets/3a6c1225-6179-4380-ac98-d39cca5c3233)

## Lab 8: Generate 1s delay with PIC TIMER1 
In this lab, PIC TIMER1 module is configured to operate in timer mode with an aim to generate 1s time interval/delay 
between 2 events which is switching on the LED (event1) and then off (event2) after this modules fires an interrupt signal to the MCU CPU.

## Schematic capture and simulation (Proteus)
![lab8](https://github.com/user-attachments/assets/ab538540-3c70-4b94-8aec-53239f13145c)

## Lab 8: Generate 1s delay with TIMER Preloader
This lab builds on the preceding Lab which had small time error. The aim of this lab is to a generate 100% 1sec time interval.
The calculations involved to prove and solve this error are attached herein this repository and can be found by following this file path
Lab9/Timer1_1s_time_interval.docx .
## Schematic capture and simulation (Proteus)
Refer to Lab8.

## CRO Oscilloscope Outputs
1sec time delay generated without Timer Preloading Techinque (not accurate)

![lab8_time_error](https://github.com/user-attachments/assets/53a66b83-0acb-4deb-8486-cbe0a2e6b8df)

1sec time delay generated with Timer Preloading Techinque (100% accurate)
![lab9](https://github.com/user-attachments/assets/c3d901e6-a293-4dc7-b2ce-ad653b408be8)
