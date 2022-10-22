#include "stats.h"

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float> &numbers)
{
    // Implement statistics here
    Statistics::Stats Stat{std::nanf("0.0"), std::nanf("0.0"), std::nanf("0.0")};

    if ((numbers.size()) == 0)
    {
        Stat.average = std::nanf("0.0");
        Stat.max = std::nanf("0.0");
        Stat.min = std::nanf("0.0");
    }

    else
    {
        float temp_min = numbers.at(0);
        float temp_max = numbers.at(0);
        float sum = numbers.at(0);
        for (long unsigned int i = 1; i < numbers.size(); i++)
        {
            if (temp_max < numbers.at(i))
            {
                temp_max = numbers.at(i);
            }
            if (temp_min > numbers.at(i))
            {
                temp_min = numbers.at(i);
            }

            sum = sum + numbers.at(i);
        }
        Stat.average = sum / numbers.size();
        Stat.max = temp_max;
        Stat.min = temp_min;
    }

    return Stat;
}
        
void Alert::StatsAlerter::checkAndAlert(const std::vector<float> &numbers)
{
    auto checkStat = Statistics::ComputeStatistics(numbers);

    // Checking threshold
    if (checkStat.max > mThreshold)
    {
        // alert
        for (long unsigned int i = 0; i < alerts.size(); i++)
        {
            alerts.at(i)->alert();
        }
    }
}
