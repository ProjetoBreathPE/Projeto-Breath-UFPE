#include <Arduino.h>

#include <AccelStepper.h>

// Pins
#define stepperDriverPul 4
#define stepperDriverEn  5
#define stepperDriverDir 6

AccelStepper pumpMotor(AccelStepper::DRIVER,stepperDriverPul,stepperDriverDir);

#define pctLed 23
#define alarmeLed 22
#define buzzer 45

#define swSilence 32
#define swConfirmar 33
#define swFDC 40

#define pot1 14
#define pot2 15
#define pot3 16
#define pot4 17

#define pressureSensor 19

// For the loop
#define controlLoopTime 100 //milliseconds
unsigned long controlNow,controlNext;

void setup() {
  // Inputs
  pinMode(swSilence,INPUT_PULLUP);
  pinMode(swConfirmar,INPUT_PULLUP);
  pinMode(swFDC, INPUT_PULLUP);
  // Outputs
  pinMode(stepperDriverDir,OUTPUT);
  pinMode(stepperDriverEn,OUTPUT);
  pinMode(stepperDriverPul,OUTPUT);
}

void runControlLoop(){

}

void checkComm(){

}

void loop() {
  runControlLoop();
  checkCOmm();
  // put your main code here, to run repeatedly:
}