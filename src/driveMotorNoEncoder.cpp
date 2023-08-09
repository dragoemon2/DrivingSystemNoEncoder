#include <mbed.h>
#include <math.h>
#include "driveMotorNoEncoder.hpp"
#include "parameters.hpp"

//#include <iostream>
//using namespace std;

//初期化
DriveMotorNoEncoder::DriveMotorNoEncoder(PinName pwm_pin, PinName dir_pin): pwmOut(pwm_pin), dirOut(dir_pin) {
    
}

//PWMの書き込み
void DriveMotorNoEncoder::setPWM(float signed_pwm){
    if(signed_pwm > 0){
        pwmOut.write(signed_pwm);
        dirOut.write(1);
    }else{
        pwmOut.write(-signed_pwm);
        dirOut.write(0);
    }
}


//停止
void DriveMotorNoEncoder::stop(){
    setPWM(0);
}



