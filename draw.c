#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "draw.h"
#include "constants.h"

void DrawCircle()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f (0,0.4,1);
    int ii;
    int num_segments = 50;
    int r = 12;
    float x,z,theta;
    for(ii = 0; ii < num_segments; ii++)
    {
        theta = 2.0f * pi * ii / num_segments;

        x = r * cosf(theta);
        z = r * sinf(theta);

        glVertex3f(x, 0, z);

    }
    glEnd();
}
void drawMainShip(float x, float z)
     {
         //glDisable(GL_LIGHTING);
         glColor3f(1, 0.5, 0.5);
         glPushMatrix();
         glTranslatef(x, 0.5, z);
         glutSolidCube(0.5);
         glPopMatrix();

         glColor3f(1, 0, 0);
         glPushMatrix();
         glTranslatef(x, 0.5, z);
         glutWireCube(0.5);
         glPopMatrix();
         //glEnable(GL_LIGHTING);
     }