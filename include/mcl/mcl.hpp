#ifndef MCL_HPP
#define MCL_HPP

#include <algorithm>
#include <vector>

namespace localization {

    struct particle {
        double x;
        double y;
        double theta;
        double weight;
    };

    struct distSensor {
        pros::Distance dist;
        float x;
        float y;
        float theta;
    };

    struct field {
        float x;
        float y;
    };

    class MCL {
    public:
        MCL(lemlib::chassis chassis, std::vector<distSensor> sensors, field field);
        ~MCL();

        void enable();
        void disable();
        void setStartPose();
        bool isEnabled();
    
    private:
        
    };
}

#endif // MCL_HPP