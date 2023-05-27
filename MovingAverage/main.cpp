#include "movingAvg.h"
#include <vector>

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    size_t size = 2;
    size_t lenData = 1000000;

    std::vector<float> floatTest;
    std::vector<double> doubleTest;

    for (size_t i = 0; i < lenData; i++)
    {
        
        doubleTest.push_back(getRandomNumber(0,100));
        
    }
    

    for (size_t i = 0; i < lenData; i++)
    {
        
        floatTest.push_back(getRandomNumber(0,100));
        
    }
    
    unsigned int zeroTime;
    
    while(size <= 128)
    {
        zeroTime = clock();
        if(!movingAverage(&doubleTest[0],lenData,size))
        {
            std::cout << "\nTime for window " << size << " for double: " << clock() - zeroTime << " mcseconds\n";
            
        }
        else
        {
            std::cout << "Window size error\n";
        }

        zeroTime = clock();
        if(!movingAverage(&floatTest[0],lenData,size))
        {
            std::cout << "\nTime for window " << size << " for float: " << clock() - zeroTime << " mcseconds\n";
            
        }
        else
        {
            std::cout << "Window size error'\n";
        }

        size *= 2;
    }
    
    doubleTest.erase(doubleTest.begin(),doubleTest.begin()+127);
    floatTest.erase(floatTest.begin(),floatTest.begin()+127);
    
    return 0;
}

