#include "movingAvg.h"




int main()
{
    srand(static_cast<unsigned int>(time(0)));

    size_t window = 2;
    size_t lenData = 1000000;

    std::vector<float> floatTest;
    std::vector<float> floatTestOut;
    std::vector<double> doubleTest;
    std::vector<double> doubleTestOut;

    for (size_t i = 0; i < lenData; i++)
    {
        
        doubleTest.push_back(getRandomNumber(0,100));
        
    }
    

    for (size_t i = 0; i < lenData; i++)
    {
        
        floatTest.push_back(getRandomNumber(0,100));
        
    }
    
    unsigned int zeroTime;
    
    while(window <= 128)
    {
        floatTestOut.clear();
        doubleTestOut.clear();

        zeroTime = clock();
        if(!movingAverage(doubleTest,doubleTestOut,window))
        {
            std::cout << "\nTime for window " << window << " for double: " << clock() - zeroTime << " mcseconds\n";
            
        }
        else
        {
            std::cout << "Window size error\n";
        }

        zeroTime = clock();
        if(!movingAverage(floatTest,floatTestOut,window))
        {
            std::cout << "\nTime for window " << window << " for float: " << clock() - zeroTime << " mcseconds\n";
            
        }
        else
        {
            std::cout << "Window size error'\n";
        }
        
        window *= 2;
    }

    
    return 0;
}

