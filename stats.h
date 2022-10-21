#include <iostream>
#include <vector>
#include <cmath>

namespace Statistics {
    
    struct Stats{
        float average;
        float max;
        float min;
    };
    
    Stats ComputeStatistics(const std::vector<float>& numbers); 
}
