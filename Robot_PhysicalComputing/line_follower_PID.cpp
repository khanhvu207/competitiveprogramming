#include "mbed.h"
#include "physcom.h"
using namespace physcom;

Serial pc(USBTX, USBRX);
AnalogIn passive_light(p18); //passive opto sensor on pin 18
DigitalOut redLed(p20);      //red LED on pin 20
DigitalOut greenLed(p19);    //green LED on pin 19
Ping Pinger(p11);            //ultrasound sensor on pin 11


M3pi robot;

const float offset_middle = 2;
const float baseSpeed = 0.3;
const float maxSpeed = 0.8;
const int black_threshold = 700;
const float dark_threshold = 0.2;
const int ultrasoundThreshold = 10;


const float kP = 1.15;
const float kD = 2.5;
const float kI = 0.000015;

bool T_junction;
float previousError = 0;
float sumError = 0;
	
void move(float left_speed, float right_speed) {
	robot.activate_motor(0, left_speed);
	robot.activate_motor(1, right_speed);
}

float getError() {
	
	int sensors[5];
	robot.calibrated_sensors(sensors);
	
	T_junction = false;
	if (sensors[0] > black_threshold && sensors[4] > black_threshold) {
			T_junction = true;
	}
	
	float avg = 0, sum = 0;
	for (int i = 1; i < 4; ++i) {
			avg += sensors[i] * i * 1.0;
			sum += sensors[i] * 1.0;
	}
	
	avg /= sum;
	
	return offset_middle - avg;
}

float calcPID(float error) {
	
	sumError += error;
	float PID_speed = kP * error + kD * (error - previousError) + kI * sumError;
	
	previousError = error;
	return PID_speed;
}

bool inTunnel() {
	float light_value = passive_light.read();
	return (light_value < dark_threshold);
}

bool encounterObstacles() {
	Pinger.Send();
	int range = Pinger.Read_cm();
	return (range < ultrasoundThreshold);
}

int main() {
	robot.sensor_auto_calibrate();

	while (1) {
			redLed = 0, greenLed = 0;
			float error = getError();
			float pidSpeed = calcPID(error);
			
			if (inTunnel()) { //Turn on lights if the robot in the tunnel
					redLed = 1;
					greenLed = 1;
			}
			
			if (T_junction || encounterObstacles()) {
					move(0, 0);   //STOP!
					continue;
			}
			
			float leftMotorSpeed = baseSpeed - pidSpeed;
			float rightMotorSpeed = baseSpeed + pidSpeed; 
			
			if (leftMotorSpeed < 0.0) leftMotorSpeed = 0.0;
			if (leftMotorSpeed > maxSpeed) leftMotorSpeed = maxSpeed;
			if (rightMotorSpeed < 0.0) rightMotorSpeed = 0.0;
			if (rightMotorSpeed > maxSpeed) rightMotorSpeed = maxSpeed;
			
			move(leftMotorSpeed, rightMotorSpeed);
	}
}
