#include <Servo.h>

const uint8_t VescOutputPin = 5;

const uint8_t PotentiometerPin = A0;

int myspeed = 1500;
Servo esc;

void setup() {

  esc.attach(VescOutputPin);

  esc.writeMicroseconds(1500);

  Serial.begin(9600);
}

 void loop() {
  if(Serial.available>0){
    myspeed = Serial.read();
  }
  esc.writeMicroseconds(myspeed);

}
