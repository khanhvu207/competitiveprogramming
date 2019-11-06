#include "mbed.h"
#include "physcom.h"
using namespace physcom;

Serial pc(USBTX, USBRX);
M3pi robot;

const int offset_middle = 2;
const int baseSpeed = 0.5;

int previousError = 0, sumError = 0;
    
void move(float left_speed, float right_speed) {
    robot.activate_motor(0, left_speed);
    robot.activate_motor(1, right_speed);
}

int getError() {
    
    int sensors[5];
    robot.calibrated_sensors(sensors);
    
    int avg = 0, sum = 0;
    for (int i = 0; i < 5; ++i) {
        avg += sensors[i] * i;
        sum += sensors[i];
    }
    
    avg /= sum;
    
    return offset_middle - avg;
}

int calcPID(int error) {
    
    int kP = 0.1;
    int kD = 1;
    int kI = 0.00001;
    
    sumError += error;
    
    int PID_speed = kP * error + kD * (error - previousError) + kI * sumError;
    
    previousError = error;
    return PID_speed;
}

int main() {
    robot.sensor_auto_calibrate();

    while (1) {
        int error = getError();
        int pidSpeed = calcPID(error);
        
        int leftMotorSpeed = baseSpeed - pidSpeed;
        int rightMotorSpeed = baseSpeed + pidSpeed;
        
        if (leftMotorSpeed < 0) leftMotorSpeed = 0;
        if (leftMotorSpeed > 1) leftMotorSpeed = 1;
        if (rightMotorSpeed < 0) rightMotorSpeed = 0;
        if (rightMotorSpeed > 1) rightMotorSpeed = 1;
        
        move(leftMotorSpeed, rightMotorSpeed);
    }
}
