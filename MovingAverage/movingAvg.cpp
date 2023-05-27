#include "movingAvg.h"

double average(double *values, int size)
{
    double temp = 0;
    for(int i = 0; i<size;++i)
    {
        temp += values[i];
    }

    return temp/size;
}

float average(float *values, int size)
{
    float temp = 0;
    for(int i = 0; i<size;++i)
    {
        temp += values[i];
    }

    return temp/size;
}

double getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    
    return (rand() * fraction * (max - min + 1) + min);
}
