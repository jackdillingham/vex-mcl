#include "mcl.hpp"

namespace localization {

    double MCL::wrapAngle(double angle, bool radians = false) {
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
    double traceRayToWallDistance(pose robotPose, field fieldDimensions, int maxRange) {
        // Step 1 is to find the pose of the sensor
        pose sensorPose(0, 0, 0);
        sensorPose.x = robotPose.x +
    }
    
    MCL::MCL(lemlib::chassis chassis, std::vector<distSensor> distSensors, field field, rd::Console console) {
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
            std::vector<particle> particles;
            std::vector<expectedDistanceValue> expected;
            for (int i = 0; i < particleCount; i++) {
                particles[i].x = normal.operator() + startPose.x;
                particles[i].y = normal.operator() + startPose.y;
                particles[i].theta = normal.operator() + startPose.theta;
                particles[i].weight = 0; // start with no weight as there is no distance data yet
            }
            
            pose oldPose = startPose;
            pose newPose = startPose;

            int particleNumber = particleCount;
            
            pros::Task mclTask(MCL::update);
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

        newPose = chassis.getPose();
        
        deltaPose.x = newPose.x - oldPose.x
        deltaPose.y = newPose.y - oldPose.y
        deltaPose.theta = newPose.theta - newPose.theta

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

        oldPose = chassis.getPose();
        pros::delay(20);
    }
}

