#include <Arduino.h>

// Pins
#define DriverEn  4
#define DriverDir 5
#define DriverPul 6

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


// PARÂMETROS DO CICLO


float tCycleTimer = 0;       // Absolute time (s) at start of each breathing cycle
float tInsp = 0;             // Tempo (s) de inspiração calculado
float tHoldInsp = 0;         // Tempo (s) de pausa inspiratória calculado
float tExp = 0;              // Tempo (s) de expiração calculado
float tPeriodo = 0;          // Período (s) do ciclo respiratório


// For the loop
#define controlLoopTime 100 //milliseconds
unsigned long controlNow,controlNext;

void setup() {
  // Inputs
  pinMode(swConfirmar,INPUT_PULLUP);
  pinMode(swFDC, INPUT_PULLUP);
  pinMode(swModo, INPUT_PULLUP);
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
  float convertVsensor = 5/1023;
  //Tensão a 120 cmH2O = 4.5V nominal (entre 4.4 e 4.6)
  //Tensão a 0 cmH2O = 0.35V nominal (entre 0.30 e 0.40)
  //Tensão a -10 cmH2O = 0.28V novinal (entre 0.23 e 0.33)
  
  float pressure = (Pmax - Pmin) / (4.5 - 0.28) * convertVsensor;
  return pressure;
}

void calculaFormaDeOnda(){
  tPeríodo = 60 / pot1;
}

//Retorna o tempo (s) atual em segundos desde o inicio da execuçao do arduino. >>>> OVERFLOW em 50 dias (reset). 
unsigned long relogio(){
  return millis()*1e-3;
}
