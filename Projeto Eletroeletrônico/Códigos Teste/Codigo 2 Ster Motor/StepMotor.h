#ifndef __STEPMOTOR_H__
#define __STEPMOTOR_H__

namespace StepMotor {
  /////////////////////////////////////////
//Controle do motor de passo
/////////////////////////////////////////

const short DRIVER_EN=4;
const short DRIVER_DIR=5;
const short DRIVER_PUL=6;
//const short NSLEEP=49;
//const short NRESET=47;
//const short MS3=45;
//const short MS2=43;
//const short MS1=41;

unsigned long t0=0;
bool Mstep=0; //sinal para ser enviado para o drive
bool Mdir=0; //direção de rotação do motor

int Nspeed=1;  //Para ser ajustável
int counter=0; //Não utilizada diretamente

unsigned long dt=500; //Tempo em micro segundos

void initMotor()
{
//Controle motor de passo
  pinMode(DRIVER_EN,OUTPUT);
  pinMode(DRIVER_DIR,OUTPUT);
  pinMode(DRIVER_PUL,OUTPUT);
 // pinMode(NSLEEP,OUTPUT);
  //pinMode(NRESET,OUTPUT);
  //pinMode(MS3,OUTPUT);
  //pinMode(MS2,OUTPUT);
  //pinMode(MS1,OUTPUT);
  
  digitalWrite(DRIVER_EN,LOW);
  digitalWrite(DRIVER_DIR,LOW);
  digitalWrite(DRIVER_PUL,LOW);
  //digitalWrite(NSLEEP,LOW);
  //digitalWrite(NRESET,HIGH);
  //digitalWrite(MS3,LOW);
  //digitalWrite(MS2,LOW);
  //digitalWrite(MS1,LOW);
}

inline void setDir(bool d) {
  Mdir=d;
}

/*inline void setEna(bool e) {
  digitalWrite(DRIVER_EN,e);
}*/

inline void setSpeed(unsigned int s) // em relação a dt(pulsos).
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

    digitalWrite(DRIVER_DIR,Mdir);
    digitalWrite(DRIVER_PUL,Mstep);
  }
   

}
}
#endif __STEPMOTOR_H__
