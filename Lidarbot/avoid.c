/**************************************************************
* Class: CSC-615-01 Fall 2020
* Project: Line Following robot
*
* File: avoid.c
*
* Description: The code is for avoiding the Obstacle
* and going around it to follow the line
**************************************************************/
#include <stdio.h>
#include <wiringPi.h>
#include <stdint.h>
#include <stdlib.h>
#include <softPwm.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include "drive.h"
#include "avoid.h"
#include "line.h"
#include "testingpipe.h"

//avoid method using Lidar,
//turn, then follow line if found at any point after this
void avoid()
{
	if (angle > 176 && angle < 184 && quality > 10)
	{
				if (distance < 200)
				{
					stop();
					printf("Obstacle detected/n");
					delay(3000);
						turn_left();
						delay(1000);
						forward();
						delay(1500);
						turn_right();
						delay(1000);
						forward();
						delay(1500);
						turn_right();
						delay(1000);
						while(digitalRead(LINE1) == LOW)
						{
							forward();
						}
						turn_left();
						delay(1000);
				}
	}

}
