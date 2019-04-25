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
            cPers+=0.1;
            break;
        case 't': //zoom in
        case 'T':
            cPers-=0.1;
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

        case ' ':
            if(shipSelection != 0){
                if (canPlaceShip(shipSelection,shipRotation) != 0){
                    placeShip(shipSelection,shipRotation);
                    shipRotation = 0;
                    shipSelection = 0;
                }
                /*
                switch (shipSelection){
                    case 1:


                        if (playerShips[getPlayerMatrixX()][getPlayerMatrixZ()] == 0){
                            platformX[platformCounter] = getHeliX();
                            platformZ[platformCounter] = getHeliZ();
                            platform[platformCounter]=1;
                            platformCounter++;
                            playerShips[getPlayerMatrixX()][getPlayerMatrixZ()]=1;

                            shipRotation = 0;
                            shipSelection = 0;
                        }

                        break;


                    case 2:

                        //TODO treba dodati proveru da li moze da se postavi
                        size2ShipX[size2ShipCounter] = getHeliX();
                        size2ShipZ[size2ShipCounter] = getHeliZ();
                        size2Ship[size2ShipCounter]=1;
                        size2ShipRotation[size2ShipCounter] = shipRotation;
                        size2ShipCounter++;

                        

                        break;
                }
                */
            
                
            }
            break;
        case 'v':
            printXZ();
            break;

        case '1':
            if (platformCounter < numOfPlatforms){
                shipSelection = 1;

                
                
            }
            break;
        //

        case '2':
            if (size2ShipCounter < numOf2Ships){
                shipSelection = 2;

                
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