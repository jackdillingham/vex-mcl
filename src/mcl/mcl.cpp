#include "mcl/mcl.hpp"

namespace localization {

    double MCL::wrapAngle(double angle, bool radians) {
        while (angle > 360.0) {
            angle -= 360.0;
        }
        while (angle < 0.0) {
            angle += 360.0;
        }

        return angle;
    }

    double MCL::mmToIn(double mm) {return mm/25.4;}

    //
    double MCL::traceRayToWallDistance(pose robotPose, field fieldDimensions, int maxRange) {
        // TODO: Find the sensor pose and trace the ray to the wall.
        return maxRange;
    }
    
    MCL::MCL(lemlib::TrackingWheelOdometry& odom, std::vector<distSensor> distSensors, field field, rd::Console& console)
        : odom(odom) {
        // Constructor implementation for creating the MCL object with data
        


    }

    MCL::~MCL() {
        // Destructor implementation
    }

    void MCL::enable(pose startPose, int particleCount, bool isGlobal) {
        // Enable implementation for initializing particles and placing update in a task

        running = true;

        // Initialize particles around the start pose

        if (!isGlobal) {
            particles.resize(particleCount);
            std::vector<expectedDistanceValue> expected;
            std::mt19937 engine;
            for (int i = 0; i < particleCount; i++) {
                particles[i].x = normal(engine) + startPose.x;
                particles[i].y = normal(engine) + startPose.y;
                particles[i].theta = normal(engine) + startPose.theta;
                particles[i].weight = 0; // start with no weight as there is no distance data yet
            }
            
            oldPose = startPose;
            newPose = startPose;

            particleNumber = particleCount;
            
            pros::Task mclTask([this] { update(); });
        }

    }

    void MCL::disable() {
        // Disable implementation
    }

    void MCL::setPose() {
        // Set pose implementation
    }

    bool MCL::isEnabled() {
        return running;
    }

    void MCL::update() {
        // STEP 1: propagation step
        // 
        // The robot takes in deltaPose using odometry and prpagates all particles in the same way as the bot moved

        const auto odomPose = odom.getPose();
        newPose = {to_in(odomPose.x), to_in(odomPose.y), to_cDeg(odomPose.orientation)};
        
        deltaPose.x = newPose.x - oldPose.x;
        deltaPose.y = newPose.y - oldPose.y;
        deltaPose.theta = newPose.theta - oldPose.theta;

        for (int i = 0; i < particleNumber; i++) {
            particles[i].x += deltaPose.x;
            particles[i].y += deltaPose.y;
            particles[i].theta += deltaPose.theta;
        }

        /* STEP 2: prediction step
        
        From each particle, using the offsets of the distance sensors, 
        we can calulate what the sensors should show from that point assuming the robot was there
        */

        for (int i = 0; i < particleNumber; i++) {

        }

        oldPose = newPose;
        pros::delay(20);
    }
}

