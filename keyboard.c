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
int size2ShipCounter = 0;
int size3ShipCounter = 0;
int size4ShipCounter = 0;
int size5ShipCounter = 0;

int shipRotation=0;
int shipSelection=0;



void on_keyboard(unsigned char key, int x, int y)
{
    
	switch(key)
	{
        case 'g': //zoom out
        case 'G':
            cPersMover=0.1;
            break;
        case 't': //zoom in
        case 'T':
            cPersMover=-0.1;
            break;

        case 'w':
        case 'W':
            if(pauseGame){
                heliMoved = true;
                heliDirAngle = 0;
            }
            break;
        case 's':
        case 'S':
            if(pauseGame){
                heliMoved = true;
                heliDirAngle = pi;
            }
            break;

            
        case 'a':
        case 'A':
            if(pauseGame){
                heliMoved = true;
                heliDirAngle = pi/2;
            }
            break;
            
        case 'd':
        case 'D':
            if(pauseGame){
                heliMoved = true;
                heliDirAngle = -pi/2;
            }
            break;

        case 'i':
        case 'I':

            if(pauseGame){
                targetMoved = true;
                targetDir = 0;
            }
            break;
        case 'k':
        case 'K':
            if(pauseGame){
                targetMoved = true;
                targetDir = pi;
            }
            break;

            
        case 'j':
        case 'J':
            if(pauseGame){
                targetMoved = true;
                targetDir = pi/2;
            }
            break;
            
        case 'l':
        case 'L':
            if(pauseGame){
                targetMoved = true;
                targetDir = -pi/2;
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
	        	rotationDir=rotationSpeed;
	        break;
        case 'e':
        case 'E':
        	if(pauseGame)
        		rotationDir=-rotationSpeed;
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

        case 'r':
        case 'R':
            if(shipSelection != 0){
                shipRotation+=1;
                shipRotation%=4;
            }
            break;

        case 'v':
        case 'V':
            printXZ();
            break;

        case ' ':
            if(shipSelection != 0){
                if (canPlaceShip(shipSelection,shipRotation) != 0
                    && shipPrices[shipSelection] <= novac
                    ){
                    placeShip(shipSelection,shipRotation);
                    
                    printf ("kupljeno za %d!\n", shipPrices[shipSelection]/15);
                    novac -= shipPrices[shipSelection];

                    shipRotation = 0;
                    shipSelection = 0;
                }
            
                
            }
            break;

        case '1':
            if (platformCounter < numOfPlatforms){
                shipSelection = 1;

                
                
            }
            break;
        case '2':
            if (size2ShipCounter < numOf2Ships){
                shipSelection = 2;

                
            }
            break;
        case '3':
            if (size3ShipCounter < numOf3Ships){
                shipSelection = 3;

                
            }
            break;
        case '4':
            if (size4ShipCounter < numOf4Ships){
                shipSelection = 4;

                
            }
            break;
        case '5':
            if (size5ShipCounter < numOf5Ships){
                shipSelection = 5;

                
            }
            break;
        case'0':
            printMatrix(playerShips, gridSize);
            printf("x: %d\n", getPlayerMatrixX());
            printf("z: %d\n", getPlayerMatrixZ());
            printf("\n");
            break;







		case 27:
            exit(EXIT_SUCCESS);
            break;
		default:
            break;
			
		
	}
    glutPostRedisplay();
}

void up_key(unsigned char key, int x, int y){
    switch(key)
    {
        case 'g': //zoom out
        case 'G':
        case 't': //zoom in
        case 'T':
            cPersMover=0;
            break;
        

        case 'w':
        case 'W':
            
        case 's':
        case 'S':
            

            
        case 'a':
        case 'A':
            
            
        case 'd':
        case 'D':
            heliMoved=0;
            break;


        case 'q':
        case 'Q':

        case 'e':
        case 'E':
            
                rotationDir=0;
            break;


        case 'i':
        case 'I':

        case 'k':
        case 'K':
         
        case 'j':
        case 'J':
       
        case 'l':
        case 'L':
            
            targetMoved = 0;
            
            break;
    }
}