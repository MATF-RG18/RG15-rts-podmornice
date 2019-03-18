#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "reshape.h"

void on_reshape(int width, int height)
{
	
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(float)width/height, 1, 100);
}