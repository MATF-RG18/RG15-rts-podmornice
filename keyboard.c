#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>

#include "keyboard.h"
#include "timer.h"
#include "constants.h"
#include "functions.h"

static float pomeraj; //provera da li heli moze da se pomera za pomeraj

int platformCounter = 0;

void on_keyboard(unsigned char key, int x, int y)
{
    
	switch(key)
	{
        case 'T':
        case 't':
            cPers+=0.1;
            break;
        case 'g':
        case 'G':
            cPers-=0.1;
            break;

        case 'w':
        case 'W':
            heliMoved = true;
            heliDirAngle = 0;
            pomeraj = heliSpeed*sin(rotation_parametar)*-1;
            if(pauseGame && heliInsideX(pomeraj)){
                heliX+=pomeraj;
            }

            pomeraj = heliSpeed*cos(rotation_parametar)*-1;
            if (pauseGame && heliInsideZ(pomeraj)){
                heliZ+=pomeraj;
            }
            break;
        case 's':
        case 'S':
            heliMoved = true;
            heliDirAngle = pi;
            pomeraj = heliSpeed*sin(rotation_parametar);
            if(pauseGame && heliInsideX(pomeraj)){
                heliX+=pomeraj;
            }

            pomeraj = heliSpeed*cos(rotation_parametar);
            if (pauseGame && heliInsideZ(pomeraj)){
                heliZ+=pomeraj;
            }
            break;

            
        case 'a':
        case 'A':
            heliMoved = true;
            heliDirAngle = pi/2;
            pomeraj = heliSpeed*sin(rotation_parametar+pi/2)*-1;
            if(pauseGame && heliInsideX(pomeraj)){
                heliX+=pomeraj;
            }

            pomeraj = heliSpeed*cos(rotation_parametar+pi/2)*-1;
            if (pauseGame && heliInsideZ(pomeraj)){
                heliZ+=pomeraj;
            }
            break;
            
        case 'd':
        case 'D':
            heliMoved = true;
            heliDirAngle = -pi/2;
            pomeraj = heliSpeed*sin(rotation_parametar+pi/2);
            if(pauseGame && heliInsideX(pomeraj)){
                heliX+=pomeraj;
            }

            pomeraj = heliSpeed*cos(rotation_parametar+pi/2);
            if (pauseGame && heliInsideZ(pomeraj)){
                heliZ+=pomeraj;
            }
            break;

        case 'i':
        case 'I':
            pomeraj = targetSpeed*sin(rotation_parametar)*-1;
            if(pauseGame && targetInsideX(pomeraj)){
                targetX+=pomeraj;
            }

            pomeraj = targetSpeed*cos(rotation_parametar)*-1;
            if (pauseGame && targetInsideZ(pomeraj)){
                targetZ+=pomeraj;
            }
            break;
        case 'k':
        case 'K':
            pomeraj = targetSpeed*sin(rotation_parametar);
            if(pauseGame && targetInsideX(pomeraj)){
                targetX+=pomeraj;
            }

            pomeraj = targetSpeed*cos(rotation_parametar);
            if (pauseGame && targetInsideZ(pomeraj)){
                targetZ+=pomeraj;
            }
            break;

            
        case 'j':
        case 'J':
            pomeraj = targetSpeed*sin(rotation_parametar+pi/2)*-1;
            if(pauseGame && targetInsideX(pomeraj)){
                targetX+=pomeraj;
            }

            pomeraj = targetSpeed*cos(rotation_parametar+pi/2)*-1;
            if (pauseGame && targetInsideZ(pomeraj)){
                targetZ+=pomeraj;
            }
            break;
            
        case 'l':
        case 'L':
            pomeraj = targetSpeed*sin(rotation_parametar+pi/2);
            if(pauseGame && targetInsideX(pomeraj)){
                targetX+=pomeraj;
            }

            pomeraj = targetSpeed*cos(rotation_parametar+pi/2);
            if (pauseGame && targetInsideZ(pomeraj)){
                targetZ+=pomeraj;
            }
            break;



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


        case '1':
            if (platformCounter < NumOfPlatforms){
                platformX[platformCounter] = getHeliX();
                platformZ[platformCounter] = getHeliZ();
                platform[platformCounter]=1;
                platformCounter++;
                //treba azurirati matricu brodova
            }
            break;





		case 27:
            exit(EXIT_SUCCESS);
            break;
		default:
            break;
			
		
	}
    glutPostRedisplay();
}