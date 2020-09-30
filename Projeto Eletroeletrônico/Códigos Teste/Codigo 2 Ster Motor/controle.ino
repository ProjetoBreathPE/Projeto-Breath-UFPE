Daniel Gomes16:41

#include "PComm.h"
#include "StepMotor.h"

unsigned long t0;
unsigned long t1;
int interval=50;

void setup() {
  Serial.begin(115200);
  StepMotor::initMotor();

  t0=micros();
  
}


void loop() {
  
  
  t1 = micros();

  if((t1-t0)>dt) {
    //Toma alguma decisão
    //StepMotor::setDir(.)
    //StepMotor::setSpeed(.)
    //StepMotor::setEna(.)
  
  }
  
  StepMotor::act(t);
}
