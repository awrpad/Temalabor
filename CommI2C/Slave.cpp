#include "InterArduinoI2C.h"
#include <Wire.h>

using namespace InterArduinoI2C;

byte Slave::lastTask;
Task Slave::tasks[256];

void Slave::receiveHandler(int howMany){
  while(Wire.available() > 1){
    lastTask = Wire.read();
  }
}

void Slave::requestHandler(){
  while(Wire.available() > 1){
    Wire.write(tasks[lastTask]());
  }
}

Slave::~Slave(){}

void Slave::begin(int myAddress){
    Wire.begin(myAddress);
    Wire.onReceive(receiveHandler);
    Wire.onRequest(requestHandler);
}

void Slave::registerTask(int index, Task t){
  tasks[index] = t;
}
