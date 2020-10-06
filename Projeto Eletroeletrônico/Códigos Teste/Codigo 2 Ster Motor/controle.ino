Daniel Gomes16:41

#include "PComm.h"
#include "StepMotor.h"

#define POT_INSP_TIME A2         //tempo de inspiração
#define POT_PIP A3               //Pressão inspiratória de pico
#define POT_FREQUENCE A4         //frequência respiratória

#define SENSOR_PRESSURE_1 A0

// Limites dos controles
const float TINSP_MIN = 0.3;
const float TINSP_MAX = 6;
const float PIP_MIN = 5;
const float PIP_MAX = 55; 
const float FREQ_MIN = 1;
const float FREQ_MAX = 60;
const float SENS_MIN = 0.4;
const float SENS_MAX = 2;

const float PIP_CONVERSOR = PIP_MIN + (PIP_MAX - PIP_MIN) / 1023;
const float inspTime_CONVERSOR = TINSP_MIN + (TINSP_MAX - TINSP_MIN) / 1023;
const float frequency_CONVERSOR = FREQ_MIN + (FREQ_MAX - FREQ_MIN) / 1023;

const int VOLTAGE_CONVERSOR = 5/1023; // conversão do sinal digital para valores de tensão.

const float PRESSURE_CONVERSOR = VOLTAGE_CONVERSOR * (120 + 10) / (4.5 - 0.28);

float inspTime;             // Tempo (s) de inspiração
float PIP;                  // Pressão inspiratória de pico (pressão máxima)
float frequency;            // Frequência respiratória em rpm (respirações por minuto)
unsigned long timer;
int pulses = 3;             //pulsos por comando

int fase;


unsigned long t0;
unsigned long t1;

void setup() {
  Serial.begin(115200);
  StepMotor::initMotor();

  t0=micros();
  
  
    timer = actualTime();
}


void loop() {

  if((t1-t0)>dt) {
    //Toma alguma decisão
    //StepMotor::setDir(.)
    //StepMotor::setSpeed(.)
    //StepMotor::setEna(.)
  
  }


void inputReader(){
    PIP = PIP_CONVERSOR * analogRead(POT_PIP);
    inspTime = inspTime_CONVERSOR * analogRead(POT_INSP_TIME);
    frequency = frequency_CONVERSOR * analogRead(POT_FREQUENCE);
}

float pressureReader(){
  float pressure = analogRead(SENSOR_PRESSURE_1) * PRESSURE_CONVERSOR;
  return pressure;
}

inline void runControlLoop(){
    switch(fase){
        case 0: //inspiração
            if (micros() - t0 < inspTime){
              StepMotor::setDir(1); //direção de rotação
              StepMotor::setSpeed(1);        
              if(pressureReader() < PIP){
                StepMotor::act(micros());
              }
            }         
            else{
                t0 = micros();
                fase = 1;
            }
        break;

        case 1: //expiração sem o peep        
            if (micros() - t0 < 1/frequency - inspTime) /*período - t_inspiração = t_expiração*/{
              StepMotor::setDir(0); //direção de rotação
              StepMotor::setSpeed(1)            
              if(pressureReader() > 5){ //peep
                StepMotor::act(micros());
              }
            }
            else{
              fase = 0;
              t0 = actualTime();            
            }

        break;
    }
}