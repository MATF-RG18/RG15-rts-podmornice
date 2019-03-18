#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdbool.h>

#include "timer.h"
#include "constants.h"


void on_timer(int id)
     {
         if(id != TIMER_ID)
          return;         
        
         if (pauseGame) {
             glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
         }
     
        glutPostRedisplay();
     }