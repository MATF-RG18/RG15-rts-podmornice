#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <GL/freeglut.h>

#include "constants.h"
#include "timer.h"
#include "reshape.h"
#include "keyboard.h"
#include "display.h"
#include "functions.h"


float cPers = 15,cPersMover;
int pauseGame;
float rotation_parametar = pi/4,rotationDir=0;
int coords = false;
float heliX = 0;
float heliZ = 5.5;
float heliDirAngle = 0;
int heliMoved;

float targetDir = 0;
int targetMoved = 0;

int **playerShips;
int **AIShips;



int platform[numOfPlatforms];
float platformX[numOfPlatforms],platformZ[numOfPlatforms];

int size2Ship[numOf2Ships], size2ShipRotation[numOf2Ships];
float size2ShipX[numOf2Ships],size2ShipZ[numOf2Ships];

int size3Ship[numOf3Ships],size3ShipRotation[numOf3Ships];
float size3ShipX[numOf3Ships],size3ShipZ[numOf3Ships];

int size4Ship[numOf4Ships],size4ShipRotation[numOf4Ships];
float size4ShipX[numOf4Ships],size4ShipZ[numOf4Ships];

int size5Ship[numOf5Ships],size5ShipRotation[numOf5Ships];
float size5ShipX[numOf5Ships],size5ShipZ[numOf5Ships];


float targetX = 0;
float targetZ = -5.5;

int brojac = 0;
int novac = 30 * 25;

int shipPrices[6];




int main(int argc, char** argv)
{
    pauseGame=1;
    heliMoved=0;
    glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(100,100);
	glutCreateWindow("RTSPodmornice");

	
	glutKeyboardFunc(on_keyboard);
	glutIgnoreKeyRepeat(1);
	glutKeyboardUpFunc(up_key);


	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	setArrayNull(platform,numOfPlatforms);
	setArrayNull(size2Ship,numOf2Ships);
	setArrayNull(size3Ship,numOf3Ships);
	setArrayNull(size4Ship,numOf4Ships);
	setArrayNull(size5Ship,numOf5Ships);

	playerShips = initMatrixToZero(playerShips, gridSize);
	AIShips = initMatrixToZero(AIShips, gridSize);

	shipPrices[1] = 30 * 25;
	shipPrices[2] = 25 * 25;
	shipPrices[3] = 50 * 25;
	shipPrices[4] = 75 * 25;
	shipPrices[5] = 100 * 25;

	
	glClearColor(0.5,0.5,0.8,1);

	glEnable(GL_DEPTH_TEST);

	glLineWidth(1);	

	glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);

	glutMainLoop();
	
	return 0;

}








