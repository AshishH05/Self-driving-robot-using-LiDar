/**************************************************************
* Class: CSC-615-01 Fall 2020
* Project: Line Following robot
*
* File: drive.c
*
* Description: This code sets up all the drive functions
* and takes the speeds from the globar variables declared in main()
**************************************************************/
#include <softPwm.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <pthread.h>
#include "drive.h"

int spd1 = 0;
int spd2 = 0;

void four_wheel_drive(void)
{
	softPwmWrite(PWM1,spd1);
	softPwmWrite(PWM2,spd1);
	softPwmWrite(PWM3,spd1);
	softPwmWrite(PWM4,spd1);
}

void turn_wheel_drive(void)
{
	int i = 30;
	softPwmWrite(PWM1,spd1 + i);
	softPwmWrite(PWM2,spd1 + i);
	softPwmWrite(PWM3,spd1 + i);
	softPwmWrite(PWM4,spd1 + i);
}
void slight_wheel_drive(char c)
{
	if(c == 'l'){
	softPwmWrite(PWM1,spd1);
	softPwmWrite(PWM2,spd2);
	softPwmWrite(PWM3,spd1);
	softPwmWrite(PWM4,spd2);
	}

	if(c == 'r'){
	softPwmWrite(PWM1,spd2);
	softPwmWrite(PWM2,spd1);
	softPwmWrite(PWM3,spd2);
	softPwmWrite(PWM4,spd1);
	}
}


void forward(void)
{
 	digitalWrite(CONTROL1a,HIGH);
	digitalWrite(CONTROL1b,LOW);
	digitalWrite(CONTROL2a,HIGH);
	digitalWrite(CONTROL2b,LOW);
	digitalWrite(CONTROL3a,LOW);
	digitalWrite(CONTROL3b,HIGH);
	digitalWrite(CONTROL4a,LOW);
	digitalWrite(CONTROL4b,HIGH);
	four_wheel_drive();
}

void backward(void)
{
	digitalWrite(CONTROL1a,LOW);
 	digitalWrite(CONTROL1b,HIGH);
	digitalWrite(CONTROL2a,LOW);
	digitalWrite(CONTROL2b,HIGH);
	digitalWrite(CONTROL3a,HIGH);
	digitalWrite(CONTROL3b,LOW);
	digitalWrite(CONTROL4a,HIGH);
	digitalWrite(CONTROL4b,LOW);
	four_wheel_drive();
}

void turn_right(void)
{
	digitalWrite(CONTROL1a,LOW);
	digitalWrite(CONTROL1b,HIGH);
	digitalWrite(CONTROL2a,HIGH);
	digitalWrite(CONTROL2b,LOW);
	digitalWrite(CONTROL3a,HIGH);
	digitalWrite(CONTROL3b,LOW);
	digitalWrite(CONTROL4a,LOW);
	digitalWrite(CONTROL4b,HIGH);
	turn_wheel_drive();
}

void turn_left(void)
{
	digitalWrite(CONTROL1a,HIGH);
	digitalWrite(CONTROL1b,LOW);
	digitalWrite(CONTROL2a,LOW);
	digitalWrite(CONTROL2b,HIGH);
	digitalWrite(CONTROL3a,LOW);
	digitalWrite(CONTROL3b,HIGH);
	digitalWrite(CONTROL4a,HIGH);
	digitalWrite(CONTROL4b,LOW);
	turn_wheel_drive();
}

void slight_right(void)
{
 	digitalWrite(CONTROL1a,HIGH);
	digitalWrite(CONTROL1b,LOW);
	digitalWrite(CONTROL2a,HIGH);
	digitalWrite(CONTROL2b,LOW);
	digitalWrite(CONTROL3a,LOW);
	digitalWrite(CONTROL3b,HIGH);
	digitalWrite(CONTROL4a,LOW);
	digitalWrite(CONTROL4b,HIGH);
	slight_wheel_drive('r');
}

void slight_left(void)
{
 	digitalWrite(CONTROL1a,HIGH);
	digitalWrite(CONTROL1b,LOW);
	digitalWrite(CONTROL2a,HIGH);
	digitalWrite(CONTROL2b,LOW);
	digitalWrite(CONTROL3a,LOW);
	digitalWrite(CONTROL3b,HIGH);
	digitalWrite(CONTROL4a,LOW);
	digitalWrite(CONTROL4b,HIGH);
	slight_wheel_drive('l');
}

void stop(void)
{
	softPwmWrite(PWM1,0);
	softPwmWrite(PWM2,0);
	softPwmWrite(PWM3,0);
	softPwmWrite(PWM4,0);
	digitalWrite(PWM1,LOW);
	digitalWrite(PWM2,LOW);
	digitalWrite(PWM3,LOW);
	digitalWrite(PWM4,LOW);
}
