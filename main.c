#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "test.h"
#include "draw.h"
#include "constants.h"
#include "coords.h"
#include "timer.h"
#include "reshape.h"
#include "keyboard.h"



#include <GL/freeglut.h>



static void on_display(void);

int pauseGame = true;
float rotation_parametar = pi/4;
int coords = false;
int cPers = 17;
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




static void on_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    

    gluLookAt(
            cPers*sin(rotation_parametar), cPers, cPers*cos(rotation_parametar),
            0, 0, 0,
            0, 1, 0
        );
    		
	DrawCircle();
	drawMainShip(mainShipX,mainShipZ);
	glBegin(GL_LINES);

		if (coords){
			showCoords();
		}
		
		int i,j;
		double xPos=-5,zPos=-10.5,yPos = 0.1;
		for (i=0;i<=10;i++){
			glColor3f (0,0,0);
			glVertex3f(i+xPos,yPos,0+zPos);
			glVertex3f(i+xPos,yPos,21+zPos);
		}
		for (j=0;j<=21;j++){
			glColor3f (0,0,0);
			glVertex3f(0+xPos,yPos,j+zPos);
			glVertex3f(10+xPos,yPos,j+zPos);
		}
		

		

	
/*
	
    	glColor3f( 1, 1, 1 );
		glRasterPos2i(0, 0);
		DrawCircle();
		char *tmpText = "1";

		glutStrokeString(GLUT_STROKE_MONO_ROMAN, tmpText);
*/
		

    glEnd();
	


	glutSwapBuffers();

}




