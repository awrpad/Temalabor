#ifndef DumbMovingAverage_h
#define DumbMovingAverage_h

#include "Arduino.h"

class DumbMovingAverage {
    public:
        DumbMovingAverage(int n);
        void putNextNumber(int next);
        bool canGetAverage();
        double getAverage();
    private:
        void initialize(int n);
        int siz;
        int sum;
        int counter;
};

#endif
