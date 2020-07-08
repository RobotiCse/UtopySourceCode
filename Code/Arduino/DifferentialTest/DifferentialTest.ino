#include <PWMServo.h>

#include "pins.h"

PWMServo vesc1;
PWMServo vesc2;

void setup() {
  vesc1.attach(vesc01);
  vesc2.attach(vesc02);
  Serial.begin(9600);  
  Serial1.begin(9600);
}
void loop() {

  vesc1.write(servoValueLeft());
  Serial.println("L:" + String(servoValueLeft()));
  vesc2.write(servoValueRight());
  Serial.println("R:" + String(servoValueRight()));
  if(Serial1.available
}

float servoValueLeft(){
  if(getDirectionStrenght() == 0){
    return map(getThrottleStrenght(), -90, 90, 0, 180);
  }
  if(getDirectionStrenght() > 0){
    //CAS : VERS LA DROITE
    return map(getThrottleStrenght(), -90, 90, 0, 180);
  }
  if(getDirectionStrenght() < 0){
    //CAS : VERS LA GAUCHE
    float newStrenght = 1-(abs(getDirectionStrenght()/ 100));
    return map((getThrottleStrenght()*newStrenght), -90, 90, 0, 180);
  }
  else{
    return 90;
  }
}

float servoValueRight(){
  if(getDirectionStrenght() == 0){
    return map(getThrottleStrenght(), -90, 90, 0, 180);
  }
  if(getDirectionStrenght() > 0){
    //CAS : VERS LA DROITE
    float newStrenght = 1-(abs(getDirectionStrenght()/ 100));
    return map((getThrottleStrenght()*newStrenght), -90, 90, 0, 180);
  }
  if(getDirectionStrenght() < 0){
    return map(getThrottleStrenght(), -90, 90, 0, 180);
  }
  else{
    return 90;
  }
}

float getDirectionStrenght(){
  float strenght = map(analogRead(analogicSensor01), 0, 1023, -100, 100);
  return strenght;
}

float getThrottleStrenght(){
  float strenght = map(analogRead(analogicSensor02), 0, 1023, -90, 90);
  return strenght;
}
