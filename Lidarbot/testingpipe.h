/**************************************************************
* Class: CSC-615-01 Fall 2020
* Project: Line Following robot
*
* File: testingpipe.h
*
* Description:
*
**************************************************************/

#ifndef TESTINGPIPE_H_
#define TESTINGPIPE_H_

#include <stdio.h>
extern double angle;
extern double distance;
extern int quality;
int pipe_setup(void);
void *get_pipe(void *ptr);
#endif
