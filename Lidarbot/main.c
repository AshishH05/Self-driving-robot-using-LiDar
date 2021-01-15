/**************************************************************
* Class: CSC-615-01 Fall 2020
* Project: Line Following robot
*
* File: main.c
*
* Description: This code sets up all the GPIO i/p & o/p pins
* and calls the line following and avoid functions
**************************************************************/

#include <softPwm.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <pthread.h>
#include "drive.h"
#include "line.h"
#include "avoid.h"
#include "testingpipe.h"

int main (void)
{

	pipe_setup();
	int x, y;
	printf("Please enter speed one: ");
	scanf("%d", &x);
	spd1 = x;
	printf("Please enter speed two: ");
	scanf("%d", &y);
	spd2 = y;

  	if (wiringPiSetup () < 0)
  	{
    		fprintf (stderr, "Unable to setup wiringPi: %s\n", strerror (errno)) ;
		return 1;
  	}

	pinMode(LINE1,INPUT);
	pinMode(LINE2,INPUT);
	pinMode(LINE3,INPUT);
	pinMode(LINE4,INPUT);
	pinMode(PWM1,OUTPUT);
	softPwmCreate(PWM1,0,100);
  pinMode(CONTROL4a, OUTPUT);
	pinMode(CONTROL4b, OUTPUT);
	pinMode(PWM2,OUTPUT);
	softPwmCreate(PWM2,0,100);
	pinMode(CONTROL2a, OUTPUT);
	pinMode(CONTROL2b, OUTPUT);
	pinMode(PWM3,OUTPUT);
	softPwmCreate(PWM3,0,100);
  pinMode(CONTROL1a, OUTPUT);
	pinMode(CONTROL1b, OUTPUT);
	pinMode(PWM4,OUTPUT);
	softPwmCreate(PWM4,0,100);
  pinMode(CONTROL3a, OUTPUT);
	pinMode(CONTROL3b, OUTPUT);


	while(1)
	{
		avoid();
		line_follow();
	}

	return 0;
}
