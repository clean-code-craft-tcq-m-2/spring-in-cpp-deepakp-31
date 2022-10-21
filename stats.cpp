#include "stats.h"

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& numbers) {
    //Implement statistics here
    Statistics::Stats Stat{std::nanf("0.0"), std::nanf("0.0"), std::nanf("0.0")};
    
    float temp_min = numbers.at(0);
    float temp_max = numbers.at(0);
    float sum =numbers.at(0);
    for(int i = 0; i< numbers.size(); i++)
    {
        if (temp_max < numbers.at(i))
        {
             temp_max=   numbers.at(i);
        }
        if (temp_min > numbers.at(i))
        {
             temp_min=   numbers.at(i);
        }
        
        sum = sum + numbers.at(i);
            
    }
    Stat.average =sum /numbers.size();
    Stat.max = temp_max;
    Stat.min = temp_min;
        
    return Stat;
}
