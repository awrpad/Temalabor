#include "InterArduinoI2C.h"
#include <Wire.h>

using namespace InterArduinoI2C;

void Master::begin(Translator *t) {
    translator = t;
    Wire.begin();
}

int Master::sendCommand(int slaveAddress, String command){
  Wire.beginTransmission(slaveAddress);
  Wire.write(translator->translate(command));
  Wire.endTransmission();

  Wire.requestFrom(slaveAddress, sizeof(int));
}
