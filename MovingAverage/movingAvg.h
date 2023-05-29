#ifndef MOVINGAVG_H
#define MOVINGAVG_H


#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <cmath>
#include <vector>

template<typename T>
int movingAverage(std::vector<T> &inData, std::vector<T> &outData, size_t window)
{
    if(inData.size()<= window) return 1;
    
    T avg = 0;
    
    for (size_t a = 0; a < window; a++)
        avg += inData[a];

    for (size_t i = 0; i < inData.size() - window + 1; i++)
    {
        outData.push_back(avg / window);
        avg += inData[i + window] - inData[i];
    }
   
    return 0;
}


#endif
