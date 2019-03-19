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



#include <GL/freeglut.h>





int pauseGame = true;
float rotation_parametar = pi/4;
int coords = false;
float mainShipX = 0;
float mainShipZ = 5;
float mainShipSpeed = 0.2;






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








