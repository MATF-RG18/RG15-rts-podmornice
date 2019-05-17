#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "display.h"
#include "constants.h"
#include "coords.h"
#include "draw.h"
#include "functions.h"

void on_display(void)
{
	int i,j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    cPers+=cPersMover;
    gluLookAt(
            cPers*sin(rotation_parametar), cPers, cPers*cos(rotation_parametar),
            heliX/3+targetX/3, 0, heliZ/3+targetZ/3,
            0, 1, 0
        );

    rotation_parametar+=rotationDir;
    DrawCircle();
	drawHeli();
	drawTarget();


	//printMatrix(playerShips,gridSize);
	for (i=0;i<gridSize;i++){					//sencenje zauzetih kvadratica
    	for (j=0;j<gridSize;j++){
    		if(playerShips[i][j] != 0) drawShade(getPlXFromMatrix(i),getPlZFromMatrix(j));
    	}
    }

	if (shipSelection!=0){						//crtanje trenutno selektovanog broda
		drawShip(shipSelection,getHeliX(),getHeliZ(),shipRotation);
	}

	
	for (i=0;i<numOfPlatforms;i++){				//Platforms
		if (platform[i] != 0){
			drawPlatform(platformX[i],platformZ[i]);
		}
		else break;
	}

	for (i=0;i<numOf2Ships;i++){				//2Ship
		if (size2Ship[i] != 0){
			draw2Ship(size2ShipX[i],size2ShipZ[i],size2ShipRotation[i]);

		}
		else break;
	}

	for (i=0;i<numOf3Ships;i++){				//3Ship

		if (size3Ship[i] != 0){
			draw3Ship(size3ShipX[i],size3ShipZ[i],size3ShipRotation[i]);

		}
		else break;
	}

	for (i=0;i<numOf4Ships;i++){				//4Ship

		if (size4Ship[i] != 0){
			draw4Ship(size4ShipX[i],size4ShipZ[i],size4ShipRotation[i]);

		}
		else break;
	}

	for (i=0;i<numOf5Ships;i++){				//3Ship

		if (size5Ship[i] != 0){
			draw5Ship(size5ShipX[i],size5ShipZ[i],size5ShipRotation[i]);

		}
		else break;
	}

	


	glBegin(GL_LINES);

		if (coords){
			showCoords();
		}
		

		//grid
		double xPos=-5,zPos=-10.5,yPos = 0.05;
		for (i=0;i<=10;i++){
			glColor3f (0,0,0);
			glVertex3f(i+xPos,yPos,0+zPos);
			glVertex3f(i+xPos,yPos,10+zPos);
			glVertex3f(i+xPos,yPos,11+zPos);
			glVertex3f(i+xPos,yPos,21+zPos);
		}
		for (i=0;i<=21;i++){
			glColor3f (0,0,0);
			glVertex3f(0+xPos,yPos,i+zPos);
			glVertex3f(10+xPos,yPos,i+zPos);
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