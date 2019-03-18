#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "keyboard.h"
#include "timer.h"
#include "constants.h"


void on_keyboard(unsigned char key, int x, int y)
{
    
	switch(key)
	{
		case 'p':
        case 'P':
	     	if(!pauseGame){   		
	     	  	pauseGame=1;
	     	  	glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
	     	}
	     	else{
	     		pauseGame=0;

	     	}
	        break;
        case 'q':
        case 'Q':
        	if(pauseGame)
	        	rotation_parametar+=0.03;
	        break;
        case 'e':
        case 'E':
        	if(pauseGame)
        		rotation_parametar-=0.03;
        	break;
        case 'o':
        case 'O':

        	if (coords){
        		coords=0;
        	}
        	else {
        		coords=1;
        	}
        	break;


        case 'w':
        case 'W':
        	if(pauseGame && mainShipX>-5)
        	mainShipX-=mainShipSpeed;
        	break;
        case 's':
        case 'S':

        	if(pauseGame && mainShipX<5)
        	mainShipX+=mainShipSpeed;
        	break;

        	
        case 'a':
        case 'A':
        	if(pauseGame && mainShipZ<10.5)
        	mainShipZ+=mainShipSpeed;
        	break;
        	
        case 'd':
        case 'D':

        	if(pauseGame && mainShipZ>0.5)
        	mainShipZ-=mainShipSpeed;
        	break;

		case 27:
		default:
			exit(EXIT_SUCCESS);
			break;
		
	}
    glutPostRedisplay();
}