#ifndef MovingAverage_h
#define MovingAverage_h

#include "Arduino.h"

class MovingAverage {
    public:
        MovingAverage(int n);
        ~MovingAverage();
        void putNextNumber(int next);
        double getAverage();
    private:
        int size;
        int *array;
};

#endif