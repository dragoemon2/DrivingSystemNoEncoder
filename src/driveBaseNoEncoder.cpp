#include <mbed.h>
#include <math.h>
#include <chrono>
#include "driveBaseNoEncoder.hpp"
#include "parameters.hpp"

float radiansMod(float x, float y){
    //x (mod y) を -y/2 ~ y/2の範囲で出力
    //主に2つの方角のなす角度を計算するのに使用
    return fmod((fmod(x,y) + y/2.0),y) - y/2.0;
}

//初期化
DriveBaseNoEncoder::DriveBaseNoEncoder(DriveMotorNoEncoder* motor_0, DriveMotorNoEncoder* motor_1, DriveMotorNoEncoder* motor_2, DriveMotorNoEncoder* motor_3) {
    motors[0] = motor_0;
    motors[1] = motor_1;
    motors[2] = motor_2;
    motors[3] = motor_3;

    moving = false;
};

//モーターの停止
void DriveBaseNoEncoder::stopMovement(){
    movementTicker.detach();
    moving = false;
    for(int i=0;i<4;i++){
        motors[i]->stop();
    }
}


void DriveBaseNoEncoder::runNoEncoder(float pwmX, float pwmY, float dir, float pwmD, float time){
    if(moving){
        printf("warning: a motion requested while the robot is moving.");
        movementTicker.detach();
    }

    float vx = cos(dir)*pwmX + sin(dir)*pwmY;
    float vy = -sin(dir)*pwmX + cos(dir)*pwmY;

    //各モーターの速度
    float speeds[4]; //モーターの速度
    speeds[0] = SQRT2/2 * (- vx + vy) + pwmD;
    speeds[1] = SQRT2/2 * (- vx - vy) + pwmD;
    speeds[2] = SQRT2/2 * (+ vx - vy) + pwmD;
    speeds[3] = SQRT2/2 * (+ vx + vy) + pwmD;

    timer.reset();
    timer.start();

    for(int i=0;i<4;i++){
        motors[i]->setPWM(speeds[i]);
    }
    

    while(chrono::duration<float>(timer.elapsed_time()).count() < time){
        wait_ns(1);
    }

    stopMovement();
}

