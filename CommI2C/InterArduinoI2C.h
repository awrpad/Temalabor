#ifndef InterArduinoI2C_h
#define InterArduinoI2C_h

#include "Arduino.h"

namespace InterArduinoI2C {
    typedef int (*Task)();
    
    class Translator {
      public:
        virtual byte translate(String command);
    };
    
    class Master { 
    private:
        static Translator *translator;
        Master();
    public:
        static void begin(Translator *t);
        ~Master();
        static int sendCommand(int slaveAddress, String command);
    };

    class Slave {
    private:
        static byte lastTask;
        static Task tasks[256];
        static void requestHandler();
        static void receiveHandler(int howMany);
        Slave();
    public:
        ~Slave();
        static void registerTask(int index, Task t);
        static void begin(int myAddress);
    };
    
}

#endif
