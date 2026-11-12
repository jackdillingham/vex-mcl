#ifndef MCL_HPP
#define MCL_HPP

#include <algorithm>
#include <vector>
#include <cmath>
#include <random>

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
        MCL(lemlib::chassis chassis, std::vector<distSensor> sensors, field field, rd::Console console);
        ~MCL();

        // You should use nonglobal system like 99% of the time as to be able to set an initial start pose
        void enable(lemlib::Pose startPose, int particleCount = 200, bool global = false);
        void disable();
        void setPose(); // manual intervention
        bool isEnabled();
    
    private:
        bool running = false;
        void update();

        std::normal_distribution<double> normal(0.0, 1.0); //mean, standard deviation

    };
}

#endif // MCL_HPP