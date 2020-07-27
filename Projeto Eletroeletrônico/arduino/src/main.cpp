#include <Arduino.h>

#include <AccelStepper.h>

// Pins
#define stepperDriverEn  4
#define stepperDriverDir 5
#define stepperDriverPul 6

AccelStepper pumpMotor(AccelStepper::DRIVER,stepperDriverPul,stepperDriverDir);

#define pctLed 9

#define swConfirmar 10    //botão de confirmação
#define swFDC 11          //Chave de fim de curso
#define swModo 2           //Modo de ventilação

#define pot1 A2           //parâmetro 1
#define pot2 A3           //parâmetro 2
#define pot3 A4           //parêmetro 3
#define pot4 A5           //parâmetro 4

#define pressureSensor A0

// For the loop
#define controlLoopTime 100 //milliseconds
unsigned long controlNow,controlNext;

void setup() {
  // Inputs
  pinMode(swConfirmar,INPUT_PULLUP);
  pinMode(swFDC, INPUT_PULLUP);
  pinMode(swPCV, INPUT_PULLUP);
  pinMode(swAC_PCV, INPUT_PULLUP);
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
