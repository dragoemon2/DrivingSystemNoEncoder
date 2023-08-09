#pragma once

#include <mbed.h>

class DriveMotorNoEncoder{
    public:
        PwmOut pwmOut; //モーター
        DigitalOut dirOut;

        void setPWM(float signed_pwm); //PWMの直接書き込み

        void stop();
        DriveMotorNoEncoder(PinName pwm_pin, PinName dir_pin);

        bool moving = false;

        float pwm = 0.0f;

        float _s1 = 0;
        float _s2 = 0;

    private:
        Ticker movementTicker;
        
};

