#include "mcl.hpp"

namespace localization {
    MCL::MCL(lemlib::chassis chassis, std::vector<distSensor> sensors, field field) {
        // Constructor implementation for creating the MCL object with data



    }

    MCL::~MCL() {
        // Destructor implementation
    }

    void MCL::enable(lemlib::Pose startPose, int particleCount, bool global) {
        // Enable implementation for initializing particles and placing update in a task

        running = true;

        // Initialize particles around the start pose

        if (!global) {
            std::vector<particle> particles;
            for (int i = 0; i < particleCount; i++) {
                particles[i].x = normal.operator() + startPose.x;
                particles[i].y = normal.operator() + startPose.y;
                particles[i].theta = normal.operator() + startPose.theta;
                particles[i].weight = 0; // start with no weight as there is no distance data yet
            }
            
            lemlib::Pose oldPose = startPose;
            lemlib::Pose newPose = startPose;

            int particleNumber = particleCount;
            
            pros::Task mclTask(update);
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
        
        

        for (int i = 0; i < particleNumber; i++) {
            particle[i].x += deltaPose.x;
            particle[i].y += deltaPose.y;
            particle[i].theta += deltaPose.theta;
        }

        pros::delay(20);
    }
}