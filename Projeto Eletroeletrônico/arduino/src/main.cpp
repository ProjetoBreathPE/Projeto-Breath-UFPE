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
  float pressure = analogRead(SENSOR_PRESSURE_1) * PRESSURE_CONVERSOR;
  return pressure;
}

void inputReader(){
  PIP = PIP_MIN + (PIP_MAX - PIP_MIN) / 1023 * analogRead(POT_PIP);
  inspTime = TINSP_MIN + (TINSP_MAX - TINSP_MIN) / 1023 * analogRead(POT_INSP_TIME);
  frequency = FREQ_MIN + (FREQ_MAX - FREQ_MIN) / 1023 * analogRead(POT_FREQUENCE);
  sensibility = SENS_MIN + (SENS_MAX - SENS_MIN) / 1023 * analogRead(POT_SENSIBILITY);
}

void waveCalculator(){
  tPeríod = 60 / frequency;
}

//Retorna o tempo (s) atual em segundos desde o inicio da execuçao do arduino. >>>> OVERFLOW em 50 dias (reset). 
unsigned long actualTime(){
  return millis()*1e-3;
}
