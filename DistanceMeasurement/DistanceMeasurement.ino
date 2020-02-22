#include "MovingAverage.h"
#include "DumbMovingAverage.h"

const int trigPin = 8;
const int echoPin = 7;
long duration;
int distance;
MovingAverage mavg(10);
MovingAverage mavg2(25);
DumbMovingAverage dumb(50);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  mavg.putNextNumber(distance);
  mavg2.putNextNumber(distance);
  dumb.putNextNumber(distance);
  
  Serial.print(distance);
  Serial.print(" ");
  Serial.print(mavg.getAverage());
  Serial.print(" ");
  Serial.print(mavg2.getAverage());

  /*if(dumb.canGetAverage()){
    Serial.print(" ");
    Serial.print(distance);
    Serial.print(" ");
    Serial.print(dumb.getAverage());
  }*/
  Serial.println("");
}
