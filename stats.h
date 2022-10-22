// #ifndef STATS
// #define STATS

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



    //Base class IAlerter
    class IAlerter
    {
    public:
//         virtual ~IAlerter() {};
        virtual void alert();
        
    };

    // Email
    class EmailAlert : public IAlerter
    {
    public:
        bool emailSent;

        EmailAlert()
        {
            emailSent = false;
        }

        virtual void alert(){
            emailSent= true;
        }
    };

    // LED
    class LEDAlert : public IAlerter
    {
    public:
        bool ledGlows;

        LEDAlert()
        {
            ledGlows = false;
        }

        virtual void alert(){
            ledGlows= true;
        }
    };

    class StatsAlerter
    {

    private:
        float mThreshold;
        std::vector<IAlerter *> alerts;

    public:
        // Constructor
        StatsAlerter(const float maxThreshold, std::vector<IAlerter*> alerters)
        {
            mThreshold = maxThreshold;
            alerts = alerters;
        }

        // method checkAndAlert
        void checkAndAlert(const std::vector<float> &numbers);
        
    };


// #endif //STATS
