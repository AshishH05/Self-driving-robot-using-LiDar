/**************************************************************
* Class: CSC-615-01 Fall 2020
* Project: Line Following robot
*
* File: testingpipe.c
*
* Description:
* C program to implement one side of FIFO
* This side creates the file and reads from the fifo
**************************************************************/
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wiringPi.h>
#include <pthread.h>
#include "testingpipe.h"

double angle = 0;
double distance = 0;
int quality = 0;

// Create a thread to read from the fifo continuously
int pipe_setup(void)
{
	pthread_t thread_id1;

	int status;

	status = pthread_create(&thread_id1, NULL, &get_pipe, NULL);
	if(status < 0)
	{
		printf("Unable to create pthread: [%s]\n", strerror (status));
		return 1;
	}
}

void *get_pipe(void *ptr)
{
    int fd1;
    int val= 0;
    int read_bytes;
    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);

	struct lidar{
	double angle;
	double distance;
	int quality;
	}Lidar1;

  // First open in read only and read
  fd1 = open(myfifo,O_RDONLY);

    while(1)
    {
        // Read from the fifo
	read(fd1, &Lidar1, sizeof(struct lidar));

  // saved the values read from fifo to a global struct
  	angle = Lidar1.angle;
	  distance = Lidar1.distance;
	  quality = Lidar1.quality;

    }
    return 0;
}
