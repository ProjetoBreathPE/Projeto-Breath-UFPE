#include "Stepper.h"

Stepper meuMotor(200, 8, 10, 9, 11);

/////////////////////////////////////////////////////////////////

class motorPasso
{
  int increment = 3;        // increment to move for each interval
  unsigned long lastUpdate; // last update of position
  int passos;
  int pos;
  int updateInterval;
  unsigned long int temp;
  int cont = 0;


  public:
  
  motorPasso(int interval){
    updateInterval = interval;    
  }

  void Velocity(int spd){
    meuMotor.setSpeed(spd);
  }
  void Passos(int stp){
    passos = stp;
  }
  int Return_pos()
  {
    return pos;
  }
 
  
  void Update()
  {
    
   if((pos < passos)&&(pos > -passos))
   {
       if((millis() - lastUpdate) > updateInterval)  // time to update
       {
            lastUpdate = millis();
            meuMotor.step(increment);
            pos += increment;
        }
    }
    
    if((pos >= passos)||(pos <= -passos)) // end of sweep
    {
        if (cont == 0)
        {
            temp = millis();
            cont = 1;
        }
        if((millis() - temp) > 1000)
        {
            increment = -increment;
            pos = 0;
            cont = 0;
        }
     }
 }
};


///////////////////////////////////////////////////////////////////////////////////////////


motorPasso myStepper(10);

unsigned long int tempo = 0;
int assist;
int temp = 0;
int pos = 0;

void setup() {
  
  Serial.begin(9600);
  myStepper.Velocity(60);
  myStepper.Passos(512);
  assist = 1;
  
  
}

void loop() {

  Serial.println(analogRead(A0));
 
  switch(assist)
  {
    case 0: //controlado
              myStepper.Update();
              Serial.println(analogRead(A0));
              break;
    case 1: //assistido controlado
              if(analogRead(A0) < 200)
              {
                if(temp == 0)
                {
                  myStepper.Velocity(90);
                  myStepper.Passos(1024);
                  temp = 1;
                }
                
                myStepper.Update();
                pos = myStepper.Return_pos();
                Serial.println(pos);

                if(pos <= - 1024)
                {
                  temp = 0;

                }

              }else{
                  myStepper.Velocity(60);
                  myStepper.Passos(512);
                  myStepper.Update();
              }
              break;
  }
  
}
 
