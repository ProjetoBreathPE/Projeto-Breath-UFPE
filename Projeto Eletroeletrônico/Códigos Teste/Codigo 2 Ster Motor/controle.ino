Daniel Gomes16:41

#include "PComm.h"
#include "StepMotor.h"

#define SENSOR_PRESSURE_1 A0

const int VOLTAGE_CONVERSOR = 5/1023; // conversão do sinal digital para valores de tensão.

float inspTime;             // Tempo (s) de inspiração
float PIP;                  // Pressão inspiratória de pico (pressão máxima)
float frequency;            // Frequência respiratória em rpm (respirações por minuto)
int pulses = 3;             //pulsos por comando

int fase;


unsigned long t0, t1, t2;
unsigned long dt;

void setup() {
  Serial.begin(115200);
  StepMotor::initMotor();

  dt = 1000;
  actualTime = micros();
  t1 = 0;
  t2 = actualTime;
  fase = 0;
}


void loop() {
   actualTime = micros();
   if((actualTime-t1)>dt) {
    inputReader();
    pressureReader();
    runControlLoop();
  
    Serial.print(pressureReader());
    t1 = actualTime;
  }
}


inline void inputReader(){
    PIP = 30; //fixo para o teste do motor
    inspTime = 1; //fixo para o teste do motor
    frequency = 15; //fixo para o teste do motor
}

float pressureReader(){
  float pressure = analogRead(SENSOR_PRESSURE_1) * 1023/35; //aDAPTADO para o teste do motor
  return pressure;
}

inline void runControlLoop(){
    switch(fase){
        case 0: //inspiração
            if (actualTime - t2 < inspTime){
              StepMotor::setDir(1); //direção de rotação
              StepMotor::setSpeed(1);        
              if(pressureReader() < PIP){
                StepMotor::act(actualTime);
              }
            }         
            else{
                t2 = actualTime;
                fase = 1;
            }
        break;

        case 1: //expiração com o peep        
            if (actualTime - t2 < 1/frequency - inspTime) /*período - t_inspiração = t_expiração TRANSFORMAR EM INTEIRO*/
            {
              StepMotor::setDir(0); //direção de rotação
              StepMotor::setSpeed(1)            
              if(pressureReader() > 5)
                { //peep
                StepMotor::act(t1);
                }
            }
            else
            {
              fase = 0;
              t2 = actualTime;            
            }

        break;
    }
}
