#include "InterArduinoI2C.h"

using namespace InterArduinoI2C;

String a;

void setup() {
  // put your setup code here, to run once:
 /* Slave::begin(123);
  Slave::registerTask(1, testTask);*/

  Translator t;
  Master::begin(&t);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

int testTask(){
  return 404;
}
