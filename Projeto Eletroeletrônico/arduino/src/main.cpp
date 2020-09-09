#include <Arduino.h>
#include <Constantes.h>

// PARÂMETROS DO CICLO


unsigned long tCycleTimer = 0;       // Absolute time (s) at start of each breathing cycle
float tHoldInsp = 0;         // Tempo (s) de pausa inspiratória calculado
float tExp = 0;              // Tempo (s) de expiração calculado
float tPeriod = 0;          // Período (s) do ciclo respiratório

// PARÂMETROS DE ENTRADA

float inspTime;             // Tempo (s) de inspiração
float PIP;                  // Pressão inspiratória de pico (pressão máxima)
float frequency;            // Frequência respiratória em rpm (respirações por minuto)
float sensibility;          // Sensibilidade de disparo no modo assistido

// For the loop
#define controlLoopTime 100 //milliseconds
unsigned long controlNow,controlNext;

void setup() {
  // Inputs
  pinMode(SWITCH_CONFIRM,INPUT_PULLUP);
  pinMode(SWITCH_POSITION, INPUT_PULLUP);
  pinMode(SWITCH_MODE, INPUT_PULLUP);
  // Outputs
  pinMode(DRIVER_DIR,OUTPUT);
  pinMode(DRIVER_EN,OUTPUT);
  pinMode(DRIVER_PUL,OUTPUT);
  
  digitalWrite(DRIVER_EN, LOW); //nivel baixo habilita driver
}
void loop() {
  runControlLoop();
  checkCOmm();
  // put your main code here, to run repeatedly:
}

void inspRoutine(){
  digitalWrite(DRIVER_DIR, HIGH); //direção de rotação
  //pulsos ativos na borda de subida
}

void runControlLoop(){

}

void checkComm(){

}


float pressureReader(){
  int Vsensor = analogRead(SENSOR_PRESSURE_1);
  float Pmin = -10.0;
  float Pmax = 120.0;
  float convertVsensor = 5/ANALOG_PIN_MAX;
  //Tensão a 120 cmH2O = 4.5V nominal (entre 4.4 e 4.6)
  //Tensão a 0 cmH2O = 0.35V nominal (entre 0.30 e 0.40)
  //Tensão a -10 cmH2O = 0.28V novinal (entre 0.23 e 0.33)
  
  float pressure = (Pmax - Pmin) / (4.5 - 0.28) * convertVsensor;
  return pressure;
}

void inputReader(){
  PIP = round(PIP_MIN + (PIP_MAX - PIP_MIN) / ANALOG_PIN_MAX * analogRead(POT_PIP) / PIP_RESOLUC) * PIP_RESOLUC;
  inspTime = round(TINSP_MIN + (TINSP_MAX - TINSP_MIN) / ANALOG_PIN_MAX * analogRead(POT_INSP_TIME) / TINSP_RESOLUC) * TINSP_RESOLUC;
  frequency = round(FREQ_MIN + (FREQ_MAX - FREQ_MIN) / ANALOG_PIN_MAX * analogRead(POT_FREQUENCE) / FREQ_RESOLUC) * FREQ_RESOLUC;
  sensibility = round(SENS_MIN + (SENS_MAX - SENS_MIN) / ANALOG_PIN_MAX * analogRead(POT_SENSIBILITY) / SENS_RESOLUC) * SENS_RESOLUC;
}

void waveCalculator(){
  tPeríod = 60 / frequency;
}

//Retorna o tempo (s) atual em segundos desde o inicio da execuçao do arduino. >>>> OVERFLOW em 50 dias (reset). 
unsigned long actualTime(){
  return millis()*1e-3;
}
