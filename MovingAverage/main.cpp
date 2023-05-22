#include "movingAvg.h"


int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int size = 2;//getRandomNumber(0,128);
    int timeScale = 1000000;

    double **doubleTest = new double*[timeScale];//[size];
    float **floatTest = new float*[timeScale];
    while(size <= 128)
    {
        for (size_t i = 0; i < timeScale; i++)
        {
            doubleTest[i] = new double[size];
        }
        
        
        for (size_t i = 0; i < timeScale; i++)
        {
            floatTest[i] = new float[size];
        }
        


        for(int a = 0; a < timeScale; a++)
        {
            // std::cout << "Time: " << a << '\n';
            for (size_t i = 0; i < size; i++)
            {
                doubleTest[a][i] = getRandomNumber(0.0,100000);
                // std::cout << doubleTest[a][i];
                // if(i % 16 == 0)
                //     std::cout << '\n';
                // else
                //     std::cout << ' ';
            }
            // std::cout << '\n';
        }
        
        std::cout << "\nAveraged\n";

        unsigned int zeroTime = clock();
        double afterAvg[timeScale];
        for (size_t i = 0; i < timeScale; i++)
        {
            afterAvg[i] = movingAverage(doubleTest[i],size);
            // std::cout << "Time " << i << ": " << afterAvg[i];
            // if(i != 0 && (i+1) % 4 == 0)
            //     std::cout << '\n';
            // else
            //     std::cout << ' ';
        }
        
        std::cout << "\nTime for window " << size << " for double: " << clock() - zeroTime << " mseconds\n";

        zeroTime = clock();

        for (size_t i = 0; i < timeScale; i++)
        {
            afterAvg[i] = movingAverage(floatTest[i],size);
        }
        
        std::cout << "\nTime for window " << size << " for float: " << clock() - zeroTime << " mseconds\n";
        
        for (size_t i = 0; i < timeScale; i++)
        {
            delete[] doubleTest[i];
        }
        

        for (size_t i = 0; i < timeScale; i++)
        {
            delete[] floatTest[i];
        }
        

        size *= 2;
    }
    delete[] floatTest;
    delete[] doubleTest;

    return 0;
}

