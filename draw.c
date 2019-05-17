#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>

#include "draw.h"
#include "constants.h"
#include "functions.h"
//nijansa podloge 0.1,0.3,0.9
static float pomeraj;
float tailRotationAngle;
static const GLdouble klipFja[] = {0, 1, 0, 0};

void DrawCircle()
{
    /*

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
    glEnd();*/

    GLfloat Material[] = { 0, 0.55, 1, 0.5}; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
      
        glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

        



        //glDisable(GL_LIGHTING);                   //TORUS
        
        glPushMatrix();
        glRotatef(90,1,0,0);
        glutSolidCone(12,0.5,100,20);
        glPopMatrix();

        glDisable(GL_LIGHTING); 
}


void drawHeli()
    {

        //podesavanje direkcije repa
        if(heliMoved){
            pomeraj = heliSpeed*sin(rotation_parametar + heliDirAngle)*-1;
            if (heliInsideX(pomeraj)){
                heliX+=pomeraj;
            }

            pomeraj = heliSpeed*cos(rotation_parametar + heliDirAngle)*-1;
            if (heliInsideZ(pomeraj)){
                heliZ+=pomeraj;
            }
        }

        GLfloat Material[] = { 0.7, 0.7, 0.8, 1.0 }; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
      
        glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

        



        //glDisable(GL_LIGHTING);                   //TORUS
        
        glPushMatrix();
        glTranslatef(heliX, 3, heliZ);
        glRotatef(90,1,0,0);
        glutSolidTorus(0.1,0.5,10,10);
        glPopMatrix();

        GLfloat Material1[] = { 0.2, 0.7, 0.4, 1.0 }; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material1);

        

        //glColor3f(0.7, 0.7, 0.7);                   //SFERA
        glPushMatrix();
        glTranslatef(heliX, 2.7, heliZ);
        glRotatef(90,1,0,0);
        glutSolidSphere(0.4,10,10);
        glPopMatrix();

        GLfloat Material2[] = { 0.1, 0.4, 0.2, 1.0 }; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material2);
        


        //glColor3f(0.7, 0.7, 0.7);                   //KUPA
        glPushMatrix();
        glTranslatef(heliX, 2.7, heliZ);

        if (heliMoved){ //rotacija repa u odnosu na smer kretanja
            tailRotationAngle=radToDeg(rotation_parametar + heliDirAngle);
            
        }
        glRotatef((tailRotationAngle),0,1,0);
        glutSolidCone(0.2,1.5,10,10);
        glPopMatrix();

        glDisable(GL_LIGHTING);

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
        //iscrtavanje ciljane tacke za gadjanje na protivnickoj tabli
        if (targetMoved){
            pomeraj = targetSpeed*sin(rotation_parametar + targetDir)*-1;
            if (targetInsideX(pomeraj)){
                targetX+=pomeraj;
            }
            pomeraj = targetSpeed*cos(rotation_parametar + targetDir)*-1;
            if (targetInsideZ(pomeraj)){
                targetZ+=pomeraj;
            }

        }

        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.9,0.3,0.3);
            glVertex3f(getTargetX(), 0.05, getTargetZ());
            glVertex3f(getTargetX(), 0.05, getTargetZ() + 1);
            glVertex3f(getTargetX() + 1,0.05, getTargetZ() + 1);
            glVertex3f(getTargetX() + 1,0.05, getTargetZ());

        glEnd();

        GLfloat Material[] = { 1, 0, 0, 1.0 }; 

        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
      
        glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

        glPushMatrix();
        glTranslatef(targetX, 0.1, targetZ);
        //glutSolidCube(0.5);
        glRotatef(90,1,0,0);
        glutSolidSphere(0.2,10,10);
        glPopMatrix();

        glDisable(GL_LIGHTING);

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
    }

    void draw2Ship(float x,float z, int shipRotation){
        switch (shipRotation){
            //odredjivanje centra broda
            //na osnovu parametra shipRotation
            //slicno ce biri primenjeno i u ostalim brodovima
            case 0:
                z+=0.5;
                break;
            case 1:
                x+=0.5;
                break;
            case 2:
                z+=0.5;
                x+=1;
                break;
            case 3:
                x+=0.5;
                z+=1;
                break;  
        }

        GLfloat Material[] = { 0.9, 0.6, 0.3, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);

        glEnable(GL_CLIP_PLANE0);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
      
        glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

        glPushMatrix();//paluba
        glClipPlane(GL_CLIP_PLANE0, klipFja);
        glTranslatef(x, 0.5, z);
        glRotatef(90,1,0,0);
        glRotatef(90,0,0,shipRotation%2);   //odredjivanje rotacije broda
        glScalef(1,0.5,1);
        glutSolidCone(1,1.3,10,10);
        glPopMatrix();

        GLfloat Material1[] = { 0.2, 0.4, 0.5, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material1);

        glPushMatrix();//dimnjak
        glClipPlane(GL_CLIP_PLANE0, klipFja);
        glTranslatef(x+0.5*((shipRotation+1)%2), 1, z+0.5*(shipRotation%2));
        glRotatef(90,1,0,0);
        glRotatef(90,0,0,shipRotation%2);
        glutSolidCone(0.2,3,10,10);
        glPopMatrix();

        glPushMatrix();//dimnjak
        glClipPlane(GL_CLIP_PLANE0, klipFja);
        glTranslatef(x+0.1*((shipRotation+1)%2), 1.3, z+0.1*(shipRotation%2));
        glRotatef(90,1,0,0);
        glRotatef(90,0,0,shipRotation%2);
        glutSolidCone(0.17,3.5,10,10);
        glPopMatrix();


        

        glDisable(GL_CLIP_PLANE0);
        glDisable(GL_LIGHTING);

    }


    void draw3Ship(float x, float z, int shipRotation){

        switch (shipRotation){
            case 0:
                z+=0.5;
                x-=0.5;
                break;
            case 1:
                z-=0.5;
                x+=0.5;
                break;
            case 2:
                z+=0.5;
                x+=1.5;
                break;
            case 3:
                x+=0.5;
                z+=1.5;
                break;  
        }

        GLfloat Material[] = { 0.9, 0.6, 0.9, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);


        glEnable(GL_LIGHT0);        // telo podmornice (sfera)
        glEnable(GL_LIGHTING);
        glPushMatrix();
        glTranslatef(x, 0.1, z);
        glRotatef(90,0,shipRotation%2,0);
        glScalef( 3, 1, 1);
        
        glutSolidSphere(0.5,10,10);
        glPopMatrix();

        GLfloat Material1[] = { 0.4, 0.3, 0.3, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material1);

        glPushMatrix();             // paluba podmornice (kupa)
        glTranslatef(x+0.5*((shipRotation+1)%2), 1, z+0.5*((shipRotation)%2));
        glRotatef(90,1,0,0);
        glRotatef(90,0,0,shipRotation%2);

        glScalef( 2, 1, 1);
        glutSolidCone(0.2,3.5,10,10);
        glPopMatrix();

        glDisable(GL_LIGHTING);

    }
    void draw4Ship(float x, float z, int shipRotation){

        GLfloat Material[] = { 0.9, 0.2, 0.4, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);


        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);

        switch (shipRotation){
            case 0:
                z+=0.5;
                x-=1;
                break;
            case 1:
                z-=1;
                x+=0.5;
                break;
            case 2:
                z+=0.5;
                x+=2;
                break;
            case 3:
                x+=0.5;
                z+=2;
                break;  
        }

        glPushMatrix();
        glTranslatef(x,0.75,z);

        glRotatef(90,0,shipRotation%2,0);
        glScalef( 2, 1, 1);
        glutSolidCube(0.6);
        glPopMatrix();

        GLfloat Material1[] = { 0.6, 0.6, 0.9, 1.0 };
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material1);
        //iscrtavanje palube
        glPushMatrix();
        glTranslatef(x, 0.6, z);
        glRotatef(90,1,0,0);
        glRotatef(90,0,0,shipRotation%2);
        glScalef( 4, 1, 1);
        
        glutSolidCone(0.5,5,10,10);
        glPopMatrix();

        glDisable(GL_LIGHTING);

    }
    void draw5Ship(float x, float z, int shipRotation){


        switch (shipRotation){
            case 0:
                z+=0.5;
                x-=1.5;
                break;
            case 1:
                z-=1.5;
                x+=0.5;
                break;
            case 2:
                z+=0.5;
                x+=2.5;
                break;
            case 3:
                x+=0.5;
                z+=2.5;
                break;  
        }

        GLfloat Material[] = { 0.9, 0.9, 1, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);
        //iscrtavanje sfere

        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        glPushMatrix();
        glTranslatef(x, 0.7, z);
        glRotatef(90,0,shipRotation%2,0);
        glScalef( 4, 1, 1);
        
        glutSolidSphere(0.35,10,10);
        glPopMatrix();

        GLfloat Material1[] = { 0.6, 0.9, 0.5, 1.0 }; 
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Material1);
        //iscrtavanje palube

        glPushMatrix();
        glTranslatef(x, 0.6, z);
        glRotatef(90,1,0,0);
        glRotatef(90,0,0,shipRotation%2);
        glScalef( 5, 1, 1);
        
        glutSolidCone(0.5,5,10,10);
        glPopMatrix();

        glDisable(GL_LIGHTING);

    }

    void drawShip(int size, float x, float z, float shipRotation){
        // pomocna funkcija koja crta brod dok je selektovan
        switch (size){
            case 1:
                drawPlatform(x,z);
                break;
            case 2:
                draw2Ship(x,z,shipRotation);
                break;
            case 3:
                draw3Ship(x,z,shipRotation);
                break;
            case 4:
                draw4Ship(x,z,shipRotation);
                break;
            case 5:
                draw5Ship(x,z,shipRotation);
                break;
        }
    }

    void drawShade(float x, float z){
        //crta plavu senku na zauzetim poljima
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.1,0.3,0.9);
            glVertex3f(x, 0.04, z);
            glVertex3f(x, 0.04, z+1);
            glVertex3f(x+1, 0.04, z+1);
            glVertex3f(x+1, 0.04, z);

        glEnd(); 

    }