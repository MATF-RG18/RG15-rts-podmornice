#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "display.h"
#include "constants.h"
#include "coords.h"
#include "draw.h"

void on_display(void)
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
	drawHeli();
	drawTarget();

	int i;
	for (i=0;i<NumOfPlatforms;i++){				//Platforms
		if (platform[i] != 0){
			drawPlatform(platformX[i],platformZ[i]);
		}
	}

	draw2Ship(0,0);


	glBegin(GL_LINES);

		if (coords){
			showCoords();
		}
		
		int j;

		//grid
		double xPos=-5,zPos=-10.5,yPos = 0.05;
		for (i=0;i<=10;i++){
			glColor3f (0,0,0);
			glVertex3f(i+xPos,yPos,0+zPos);
			glVertex3f(i+xPos,yPos,10+zPos);
			glVertex3f(i+xPos,yPos,11+zPos);
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