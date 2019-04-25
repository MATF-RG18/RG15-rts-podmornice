#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdbool.h>
#include <time.h>

#include "timer.h"
#include "constants.h"

// int brojac=0;
// time_t current_time,start_time,time_passed;
void on_timer(int id)
    {
    	
        if(id != TIMER_ID)
        	return;
/*
		if (!brojac) start_time=time(NULL);
        current_time = time(NULL);
        brojac++;
        time_passed=current_time-start_time;
        printf("\r");
        printf("%d metara u\t%ld sekundi\tmetri u sekundi: %lf", brojac,time_passed,(double) brojac/time_passed);
        */
      
        glutPostRedisplay();
        if (pauseGame) {
             glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
	}