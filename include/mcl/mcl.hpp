#ifndef MCL_HPP
#define MCL_HPP

#include "api.h"
#include "lemlib/api.hpp"
#include "robodash/views/console.hpp"

#include <algorithm>
#include <vector>
#include <cmath>
#include <random>

//using namespace pros;

namespace localization {

    struct pose {
        double x;
        double y;
        double theta;
    };

    struct particle {
        double x;
        double y;
        double theta;
        double weight;
    };

    struct expectedDistanceValue {
        double front;
        double right;
        double back;
        double left;
    };

    struct distSensor {
        pros::Distance dist;
        float x;
        float y;
        float theta;
    };

    struct sensorConfig {
        distSensor front;
        distSensor right;
        distSensor back;
        distSensor left;
    };

    struct field {
        float x;
        float y;
    };

    enum wall {
        UP = 0,
        RIGHT = 90,
        DOWN = 180,
        LEFT = 270
    };

    enum sensor {
        UP = 0,
        RIGHT = 90,
        DOWN = 180,
        LEFT = 270
    };

    class MCL {
    public:
        MCL(lemlib::Chassis& chassis, sensorConfig sensors, field field, rd::Console& console);
        ~MCL();

        /*
        @brief This function enables
        
        
        */
        void enable(pose startPose, int particleCount = 200, bool global = false);
        void disable();
        void setPose(); // manual intervention
        bool isEnabled();
    
    private:
        bool running = false;
        void update();
        int particleNumber;
        std::vector<particle> particles;
        
        pose newPose;
        pose oldPose;
        pose deltaPose;

        lemlib::Chassis& chassis;
        rd::Console& console;
        

        std::normal_distribution<double> normal{0.0, 1.0}; //mean, standard deviation

        double mmToIn(double mm);
        double wrapAngle(double angle, bool radians = false);
        double traceRayToWallDistance(pose robotPose, field fieldDimensions, wall selectedWall, sensor selectedSensor, int maxRange = 124);

    };
}

#endif // MCL_HPP
