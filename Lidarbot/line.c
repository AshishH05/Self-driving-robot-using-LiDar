/**************************************************************
* Class: CSC-615-01 Fall 2020
* Project: Line Following robot
*
* File: line.c
*
* Description: This code is for the robot to follow the line
* depending on the sensor values
**************************************************************/

#include <softPwm.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "drive.h"
#include "line.h"

void line_follow(void)
{

	if(digitalRead(LINE1) == HIGH && digitalRead(LINE2) == HIGH && digitalRead(LINE3) == HIGH && digitalRead(LINE4) == HIGH)
	{
		stop();
	}

	if(digitalRead(LINE1) == HIGH && digitalRead(LINE4) == LOW)
	{
		while(digitalRead(LINE3) == LOW)
		{
			turn_right();
		}
	}

	if(digitalRead(LINE4) == HIGH && digitalRead(LINE1) == LOW)
	{
		while(digitalRead(LINE2) == LOW)
		{
			turn_left();
		}
	}

	 if(digitalRead(LINE2) == HIGH && digitalRead(LINE3) == LOW)
	{
		slight_right();
	}

	 if(digitalRead(LINE3) == HIGH && digitalRead(LINE2) == LOW)
	{
		slight_left();
	}

	 if(digitalRead(LINE2) == LOW && digitalRead(LINE3) == LOW)
	{
		forward();
	}
}

//checkLine int avoidLogic.c
/*
int line_check(void){//if any of the sensors trigger due to finding the line
	if(digitalRead(LINE1) == HIGH || digitalRead(LINE2) == HIGH || digitalRead(LINE3) == HIGH || digitalRead(LINE4) == HIGH)
	{
		return 1;
	}
	else
	{ //no line found
		return 0;
	}

}
*/
