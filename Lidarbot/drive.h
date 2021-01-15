/**************************************************************
* Class: CSC-615-01 Fall 2020
* Project: Line Following robot
*
* File: drive.h
*
* Description:
*
**************************************************************/

#ifndef DRIVE_H_
#define DRIVE_H_

#include <stdio.h>

#define CONTROL4a 	2
#define CONTROL4b 	3
#define CONTROL2a 	4
#define CONTROL2b	  5
#define CONTROL1a 	13
#define CONTROL1b	  14
#define CONTROL3a 	11
#define CONTROL3b 	10
#define PWM1		    12
#define PWM2		    6
#define PWM3		    26
#define PWM4		    0

extern int spd1;
extern int spd2;
void four_wheel_drive(void);
void turn_wheel_drive(void);
void two_wheel_drive(char c);
void forward(void);
void backward(void);
void turn_right(void);
void turn_left(void);
void slight_right(void);
void slight_left(void);
void stop(void);

#endif
