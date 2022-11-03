#include <Arduino.h>

#include <PS4Controller.h>
#include <M5Atom.h>
#include "AtomMotion.h"
int servoPos;

AtomMotion Atom;

void setup() {
  M5.begin(true, false, true);
  Atom.Init();  // sda  25     scl  21
  Atom.SetServoAngle(1,90); // 90 degrees for 360 degree servo
  Serial.begin(115200);
  PS4.begin("b0:52:16:e3:5b:02");
  Serial.println("Ready.");
}

void loop() {
     if (PS4.isConnected()) {
        servoPos =  (127+(PS4.R2Value()/2)) / 1.4; // add 127 for 360 degree servo
        //Serial.println(PS4.R2Value());
     }
 
     Atom.SetServoAngle(1,servoPos);
     delay(10);
}