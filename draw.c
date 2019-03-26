#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>

#include "draw.h"
#include "constants.h"
#include "functions.h"
//nijansa podloge 0.1,0.3,0.9
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

float tailRotationAngle;
void drawHeli()
    {
        GLfloat Material[] = { 0.7, 0.7, 0.8, 1.0 }; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
      
        glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

        



        //glDisable(GL_LIGHTING);                   //TORUS
        
        glPushMatrix();
        glTranslatef(heliX, 3, heliZ);
        //glutSolidCube(0.5);
        glRotatef(90,1,0,0);
        glutSolidTorus(0.1,0.5,10,10);
        glPopMatrix();

        GLfloat Material1[] = { 0.2, 0.7, 0.4, 1.0 }; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material1);

        

        //glColor3f(0.7, 0.7, 0.7);                   //SFERA
        glPushMatrix();
        glTranslatef(heliX, 2.7, heliZ);
        //glutSolidCube(0.5);
        glRotatef(90,1,0,0);
        glutSolidSphere(0.4,10,10);
        glPopMatrix();

        GLfloat Material2[] = { 0.1, 0.4, 0.2, 1.0 }; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material2);
        


        //glColor3f(0.7, 0.7, 0.7);                   //KUPA
        glPushMatrix();
        glTranslatef(heliX, 2.7, heliZ);
        //glutSolidCube(0.5);

        if (heliMoved){ //rotacija repa u odnosu na smer kretanja
            tailRotationAngle=radToDeg(rotation_parametar + heliDirAngle);
            
            heliMoved = false;
        }
        glRotatef((tailRotationAngle),0,1,0);
        glutSolidCone(0.2,1.5,10,10);
        glPopMatrix();




        glDisable(GL_LIGHTING);





/* kocka
        glColor3f(1, 0, 0);
        glPushMatrix();
        glTranslatef(heliX, 0.5, heliZ);
        glutWireCube(0.5);
        glPopMatrix();
        
*/
        //glEnable(GL_LIGHTING);


        //mesto gde se nalazi glavni brod odnosno helikopter
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.3,0.9,0.3);
            glVertex3f(getHeliX(), 0.05, getHeliZ());
            glVertex3f(getHeliX(), 0.05, getHeliZ() + 1);
            glVertex3f(getHeliX() + 1,0.05, getHeliZ() + 1);
            glVertex3f(getHeliX() + 1,0.05, getHeliZ());

        glEnd();
    }

    void drawTarget(){
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.9,0.3,0.3);
            glVertex3f(getTargetX(), 0.05, getTargetZ());
            glVertex3f(getTargetX(), 0.05, getTargetZ() + 1);
            glVertex3f(getTargetX() + 1,0.05, getTargetZ() + 1);
            glVertex3f(getTargetX() + 1,0.05, getTargetZ());

        glEnd();

    }


    void drawPlatform(float x, float z){
        GLfloat Material[] = { 0.1, 0.3, 0.4, 1.0 }; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
      
        glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);


        glPushMatrix();//noga
        glTranslatef(x+0.2, 0.5, z+0.2);
        glRotatef(90,1,0,0);
        glutSolidCone(0.12,1.5,10,10);
        glPopMatrix();

        glPushMatrix();//noga
        glTranslatef(x+0.2, 0.5, z+0.8);
        glRotatef(90,1,0,0);
        glutSolidCone(0.12,1.5,10,10);
        glPopMatrix();

        glPushMatrix();//noga
        glTranslatef(x+0.8, 0.5, z+0.8);
        glRotatef(90,1,0,0);
        glutSolidCone(0.12,1.5,10,10);
        glPopMatrix();

        glPushMatrix();//noga
        glTranslatef(x+0.8, 0.5, z+0.2);
        glRotatef(90,1,0,0);
        glutSolidCone(0.12,1.5,10,10);
        glPopMatrix();

        glColor3f(1, 0, 0);//kuca
        glPushMatrix();
        glTranslatef(x+0.5, 0.7, z+0.5);
        glutSolidCube(0.5);
        glPopMatrix();

        GLfloat MaterialDimnjak[] = { 0.4, 0.6, 0.6, 1.0 };
        glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDimnjak);

        glPushMatrix();//dimnjak
        glTranslatef(x+0.65, 0.5, z+0.35);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.1,2.3,10,10);
        glPopMatrix();


        glDisable(GL_LIGHTING);

        glBegin(GL_TRIANGLE_FAN);//ploca
            glColor3f(0.3,0.3,0.3);
            glVertex3f(x+0.1, 0.501, z+0.1);
            glVertex3f(x+0.1, 0.501, z+0.9);
            glVertex3f(x+0.9, 0.501, z+0.9);
            glVertex3f(x+0.9, 0.501, z+0.1);

        glEnd();

        drawShade(x,z);
        drawShade(x+1,z);
        drawShade(x-1,z);
        drawShade(x,z+1);
        drawShade(x,z-1);


              
    }

    void draw2Ship(float x,float z){
        GLfloat Material[] = { 0.9, 0.6, 0.3, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);

        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
      
        glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

        glPushMatrix();//paluba
        glTranslatef(x, 0.5, z);
        glRotatef(90,1,0,0);
        glScalef(1,0.5,1);
        glutSolidCone(1,1.3,10,10);
        glPopMatrix();

        GLfloat Material1[] = { 0.2, 0.4, 0.5, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material1);

        glPushMatrix();//dimnjak
        glTranslatef(x+0.5, 1, z);
        glRotatef(90,1,0,0);
        glutSolidCone(0.2,3,10,10);
        glPopMatrix();

        glPushMatrix();//dimnjak
        glTranslatef(x+0.1, 1.3, z);
        glRotatef(90,1,0,0);
        glutSolidCone(0.17,3.5,10,10);
        glPopMatrix();


        


        glDisable(GL_LIGHTING);

    }


    void drawShade(float x, float z){
        glBegin(GL_TRIANGLE_FAN);               //Senka
            glColor3f(0.1,0.3,0.9);
            glVertex3f(x, 0.04, z);
            glVertex3f(x, 0.04, z+1);
            glVertex3f(x+1, 0.04, z+1);
            glVertex3f(x+1, 0.04, z);

        glEnd(); 

    }

