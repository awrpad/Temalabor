#include "Arduino.h"
#include "MovingAverage.h"

MovingAverage::~MovingAverage(){
    delete[] array;
}

MovingAverage::MovingAverage(int n){
    size = n;
    array = new int[n];

    for(int i = 0; i < n; ++i){
        array[i] = -1;
    }
}

void MovingAverage::putNextNumber(int next){
    for(int i = size - 1; i != 0; --i){
        if(array[i] == -1){
            array[i] = next;
            
            return;
        }
    }

    for(int i = size - 1; i != 0; --i){
        array[i] = array[i - 1];
    }
    array[0] = next;
}

double MovingAverage::getAverage(){
    int sum = 0;
    int count = 0;

    for(int i = 0; i < size; ++i){
        if(array[i] != -1){
            sum += array[i];
            ++count;
        }
    }

    return sum / (double)count;
}
