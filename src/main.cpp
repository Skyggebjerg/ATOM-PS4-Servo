#include <M5Atom.h> 
#include "AtomMotion.h"
//#include <PS4Controller.h>

AtomMotion Atom;
int servoPos;
int stigning;

void setup(){ 
  M5.begin(true, false, true);
  Atom.Init();

  //PS4.begin("4C:75:25:AD:78:7A");
  Serial.println("Ready.");
  servoPos =  0;
  stigning = 1;
}

void loop() {

       
        servoPos =  servoPos+stigning;
        if(servoPos==180) stigning = -1;
        if(servoPos==0) stigning = 1;

 
     Atom.SetServoAngle(1,servoPos);
     delay(2000);
}