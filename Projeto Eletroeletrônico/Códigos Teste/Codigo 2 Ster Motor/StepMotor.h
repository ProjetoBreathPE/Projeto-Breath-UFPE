#ifndef __STEPMOTOR_H__
#define __STEPMOTOR_H__

namespace StepMotor {
  /////////////////////////////////////////
//Controle do motor de passo
/////////////////////////////////////////

const short DIR=53;
const short STEP=51;
const short NSLEEP=49;
const short NRESET=47;
const short MS3=45;
const short MS2=43;
const short MS1=41;
const short NENABLE=39;

unsigned long t0=0;
bool Mstep=0; //sinal para ser enviado para o drive
bool Mdir=0; //direção de rotação do motor

int Nspeed=1;  //Para ser ajustável
int counter=0; //Não utilizada diretamente

unsigned long dt=1000; //Tempo em micro segundos

void initMotor()
{
//Controle motor de passo
  pinMode(DIR,OUTPUT);
  pinMode(STEP,OUTPUT);
  pinMode(NSLEEP,OUTPUT);
  pinMode(NRESET,OUTPUT);
  pinMode(MS3,OUTPUT);
  pinMode(MS2,OUTPUT);
  pinMode(MS1,OUTPUT);
  pinMode(NENABLE,OUTPUT);
  
  digitalWrite(DIR,LOW);
  digitalWrite(STEP,LOW);
  digitalWrite(NSLEEP,LOW);
  digitalWrite(NRESET,HIGH);
  digitalWrite(MS3,LOW);
  digitalWrite(MS2,LOW);
  digitalWrite(MS1,LOW);
  digitalWrite(NENABLE,LOW);
}

inline void setDir(bool d) {
  Mdir=d;
}

inline void setEna(bool e) {
  digitalWrite(NENABLE,e);
}

inline void setSpeed(unsigned int s)
{
  NSpeed=s;
}


inline void act(const unsigned long &t1)
{
  ////////////////////////////////////////
  //Controle motor de passo
  ////////////////////////////////////////

  if((t1-t0)>dt)
  {
    counter++;
   
    if((counter%NSpeed)==0) //->T=2*NSpeed*dt
    {
      if(Mstep==true)
        Mstep=false;
      else
        Mstep=true;

      t0=t1;
    }

    digitalWrite(DIR,Mdir);
    digitalWrite(STEP,Mstep);
  }
   

}
}
#endif __STEPMOTOR_H__
