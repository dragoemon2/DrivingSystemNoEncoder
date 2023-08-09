#pragma once

#include <mbed.h>
#include "driveMotorNoEncoder.hpp"
#include "parameters.hpp"


float radiansMod(float x, float y=2*PI);

class DriveBaseNoEncoder{
    public:
        DriveMotorNoEncoder* motors[4];
        

        void runNoEncoder(float pwmX, float pwmY, float dir, float pwmD, float time);

        //曲線移動 これから作る
        

        //移動の停止
        void stopMovement();

        bool moving = false;

        DriveBaseNoEncoder(DriveMotorNoEncoder* motor_0, DriveMotorNoEncoder* motor_1, DriveMotorNoEncoder* motor_2, DriveMotorNoEncoder* motor_3);

        int _s1;

    private: 
        Ticker movementTicker;
        Timer timer;
};



