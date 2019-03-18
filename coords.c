#include <GL/glut.h>

void showCoords(){
			glColor3f (0,0,1);
			glVertex3f(0,0,0);
			glVertex3f(50,0,0);

			glColor3f (0,1,0);
			glVertex3f(0,0,0);
			glVertex3f(0,50,0);

			glColor3f (1,0,0);
			glVertex3f(0,0,0);
			glVertex3f(0,0,50);
}