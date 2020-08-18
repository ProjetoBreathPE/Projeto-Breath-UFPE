#include <Arduino.h>
#include <Constantes.h>

// PARÂMETROS DO CICLO


unsigned long tCycleTimer = 0;       // Absolute time (s) at start of each breathing cycle
float tHoldInsp = 0;         // Tempo (s) de pausa inspiratória calculado
float tExp = 0;              // Tempo (s) de expiração calculado
float tPeriodo = 0;          // Período (s) do ciclo respiratório

// PARÂMETROS DE ENTRADA

float tInspiracao;             // Tempo (s) de inspiração
float PIP;
float frequencia;
float sensibilidade;

// For the loop
#define controlLoopTime 100 //milliseconds
unsigned long controlNow,controlNext;

void setup() {
  // Inputs
  pinMode(swConfirmar,INPUT_PULLUP);
  pinMode(swFDC, INPUT_PULLUP);
  pinMode(swAssistMode, INPUT_PULLUP);
  // Outputs
  pinMode(DriverDir,OUTPUT);
  pinMode(DriverEn,OUTPUT);
  pinMode(DriverPul,OUTPUT);
  
  digitalWrite(DriverEn, LOW); //nivel baixo habilita driver
}
void inspRoutine(){
  digitalWrite(DriverDir, HIGH); //direção de rotação
  //pulsos ativos na borda de subida
  
  
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

float pressureReader(){
  int Vsensor = analogRead(pressureSensor);
  float Pmin = -10.0;
  float Pmax = 120.0;
  float convertVsensor = 5/ANALOG_PIN_MAX;
  //Tensão a 120 cmH2O = 4.5V nominal (entre 4.4 e 4.6)
  //Tensão a 0 cmH2O = 0.35V nominal (entre 0.30 e 0.40)
  //Tensão a -10 cmH2O = 0.28V novinal (entre 0.23 e 0.33)
  
  float pressure = (Pmax - Pmin) / (4.5 - 0.28) * convertVsensor;
  return pressure;
}

void leParametros(){
  PIP = PIP_MIN + (PIP_MAX - PIP_MIN) * (1 / PIP_RESOLUC) * analogRead(pot_PIP) / ANALOG_PIN_MAX;
  tInspiracao = TINSP_MIN + (TINSP_MAX - TINSP_MIN) * analogRead(pot_tInsp) / ANALOG_PIN_MAX;
  frequencia = FREQ_MIN + (FREQ_MAX - FREQ_MIN) * analogRead(pot_freq) / ANALOG_PIN_MAX;
  sensibilidade = SENS_MIN + (SENS_MAX - SENS_MIN) * analogRead(pot_sens) / ANALOG_PIN_MAX;
}

void calculaFormaDeOnda(){
  tPeríodo = 60 / freq;
}

//Retorna o tempo (s) atual em segundos desde o inicio da execuçao do arduino. >>>> OVERFLOW em 50 dias (reset). 
unsigned long relogio(){
  return millis()*1e-3;
}
