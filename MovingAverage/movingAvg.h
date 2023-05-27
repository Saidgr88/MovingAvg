#ifndef MOVINGAVG_H
#define MOVINGAVG_H


#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <cmath>


double getRandomNumber(int min, int max);
//int getRandomNumber(int min, int max);
double average(double *values, int size);
float average(float *values, int size);


template<typename T>
int movingAverage(T *data, size_t size, size_t window)
{
    if(size <= window) return 1;
    
    T windowValues[window + 1] {};
    windowValues[0] = data[0];
    
    for (size_t a = 0; a < window + 1; a++)
        windowValues[a] = data[a];

    for (size_t i = 0; i < size - window + 1; i++)
    {
        int curr = i;
        windowValues[window] = data[curr + window];
        
        data[i + window - 1] = average(windowValues,window);
        
        for(size_t b = 0; b < window; b++)
            windowValues[b] = windowValues[b + 1];
    }
   
    return 0;
}


#endif
