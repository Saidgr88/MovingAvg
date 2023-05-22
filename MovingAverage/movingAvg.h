#ifndef MOVINGAVG_H
#define MOVINGAVG_H


#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <map>
#include <cmath>


double getRandomNumber(int min, int max);
//int getRandomNumber(int min, int max);
double movingAverage(double *values, int size);
float movingAverage(float *values, int size);

#endif
