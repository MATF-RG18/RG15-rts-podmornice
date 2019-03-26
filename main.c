#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "constants.h"

#include "timer.h"
#include "reshape.h"
#include "keyboard.h"
#include "display.h"
#include "functions.h"



#include <GL/freeglut.h>





float cPers = 17;
int pauseGame = true;
float rotation_parametar = pi/4;
int coords = false;
float heliX = 0;
float heliZ = 5.5;
int playerShips[10][10];
float AIShips[10][10];
float heliDirAngle = 0;
int heliMoved;
int platform[NumOfPlatforms] = {0,0,0,0,0};
float platformX[NumOfPlatforms],platformZ[NumOfPlatforms];
float targetX = 0;
float targetZ = -5.5;






int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(100,100);
	glutCreateWindow("RTSPodmornice");

	
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	
	glClearColor(0.5,0.5,0.8,1);

	glEnable(GL_DEPTH_TEST);

	glLineWidth(1);	

	

	glutMainLoop();
	
	return 0;

}








