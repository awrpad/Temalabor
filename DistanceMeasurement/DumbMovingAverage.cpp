#include "Arduino.h"
#include "DumbMovingAverage.h"

DumbMovingAverage::DumbMovingAverage(int n){
    initialize(n);
}

void DumbMovingAverage::initialize(int n){
    siz = n;
    sum = 0;
    counter = 0;
}

void DumbMovingAverage::putNextNumber(int next){
    if(counter % siz == 0){
        initialize(siz);
    }

    sum += next;
    ++counter;
}

bool DumbMovingAverage::canGetAverage(){
    return counter == siz;
}

double DumbMovingAverage::getAverage(){
    return sum / (double)siz;
}
