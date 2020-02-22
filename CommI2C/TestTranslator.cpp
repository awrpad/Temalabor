#include "InterArduinoI2C.h"

using namespace InterArduinoI2C;

class TestTranslator : Translator {
    byte translate(String command){
        return 1;
    }
};
