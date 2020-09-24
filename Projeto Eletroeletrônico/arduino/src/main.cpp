#include <Arduino.h>
#include "Constantes.h"

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
char ventMode;              // C para controlado e A para assistido

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

  Serial.begin(115200, SERIAL_8N1); // SERIAL_8E1 significa palavra de 8 bits com 1 bit de paridade par (E de even) e 1 stop bit. A paridade serve para detecção de erros
  
  digitalWrite(DRIVER_EN, LOW); //nivel baixo habilita driver
}

void loop() {
  pressureReader();
  runControlLoop();
  inputReader();
  pressureReader();
  comunication();
  // put your main code here, to run repeatedly:
}

void inspRoutine(){
  digitalWrite(DRIVER_DIR, HIGH); //direção de rotação
  //pulsos ativos na borda de subida
}

void runControlLoop(){

}

void comunication(){
  //O 's' indica o início da transmissão, a vírgula separa os valores, que devem ser enviados na ordem correta e o p, junto com o println indicam o fim da transmissão.
  Serial.print("s,"); 
  Serial.print(inspTime);
  Serial.print(',');
  Serial.print(PIP);
  Serial.print(',');
  Serial.print(frequency);
  Serial.print(',');
  Serial.print(sensibility);
  Serial.print(',');
  Serial.print(ventMode);
  Serial.println(",p"); //O ln adiciona mais um byte de recuo \r e outro de \n, que finaliza a string no raspberry.
}


float pressureReader(){
  float pressure = analogRead(SENSOR_PRESSURE_1) * PRESSURE_CONVERSOR;
  return pressure;
}

void inputReader(){
  PIP = PIP_CONVERSOR * analogRead(POT_PIP);
  inspTime = inspTime_CONVERSOR * analogRead(POT_INSP_TIME);
  frequency = frequency_CONVERSOR * analogRead(POT_FREQUENCE);
  sensibility = sensibility_CONVERSOR * analogRead(POT_SENSIBILITY);
  if(SWITCH_MODE == LOW)
    ventMode = 'C';
  else
    ventMode = 'A';
}

void waveCalculator(){
  tPeriod = 60 / frequency;
}

//Retorna o tempo (s) atual em segundos desde o inicio da execuçao do arduino. >>>> OVERFLOW em 50 dias (reset). 
unsigned long actualTime(){
  return millis()*1e-3;
}
