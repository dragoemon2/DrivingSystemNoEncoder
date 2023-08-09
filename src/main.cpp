
#include <mbed.h>
#include "driveMotorNoEncoder.hpp"
#include "driveBaseNoEncoder.hpp"
#include "parameters.hpp"


//エンコーダーのピン，モーターのピン，PIDゲイン
DriveMotorNoEncoder motor0(D2, D3);
DriveMotorNoEncoder motor1(D4, D5);
DriveMotorNoEncoder motor2(D6, D7);
DriveMotorNoEncoder motor3(D8, D9);

//足回り全体
DriveBaseNoEncoder driveBase(&motor0, &motor1, &motor2, &motor3);

int main(){
    
    driveBase.runNoEncoder(0.4, 0, 0, 0, 4);  //直進
    driveBase.runNoEncoder(0, 0, 0, 0.2, 2);  //まわる
    driveBase.runNoEncoder(0.4, 0, 0, 0, 4);  //直進

    while(1){
        
    }
}

