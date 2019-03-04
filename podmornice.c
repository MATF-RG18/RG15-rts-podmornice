#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>





#include <GL/freeglut.h>

#define TIMER_ID (0)
#define TIMER_INTERVAL (5)
#define pi (3.14159265359)



static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int);
static void drawMainShip(float x, float z);
bool pauseGame = false;
float rotation_parametar = 0;
bool coords = false;
int cPers = 15;
float mainShipX = 0;
float mainShipZ = 5;
float mainShipSpeed = 0.2;


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

static void on_keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'p':
        case 'P':
	     	if(!pauseGame){
	     
	     	  pauseGame=1;
	     	  glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
	     	}
	     	else{
	     		pauseGame=0;

	     	}
	        break;
        case 'q':
        case 'Q':
        	if(pauseGame)
	        	rotation_parametar+=0.03;
	        break;
        case 'e':
        case 'E':
        	if(pauseGame)
        		rotation_parametar-=0.03;
        	break;
        case 'o':
        case 'O':

        	if (coords){
        		coords=0;
        	}
        	else {
        		coords=1;
        	}
        	glutPostRedisplay();
        	break;


        case 'w':
        case 'W':
        	if(pauseGame && mainShipX>-5)
        	mainShipX-=mainShipSpeed;
        	break;
        case 's':
        case 'S':

        	if(pauseGame && mainShipX<5)
        	mainShipX+=mainShipSpeed;
        	break;

        	
        case 'a':
        case 'A':
        	if(pauseGame && mainShipZ<10.5)
        	mainShipZ+=mainShipSpeed;
        	break;
        	
        case 'd':
        case 'D':

        	if(pauseGame && mainShipZ>0.5)
        	mainShipZ-=mainShipSpeed;
        	break;

		case 27:
		default:
			exit(EXIT_SUCCESS);
			break;
		
	}
}


static void on_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    

    gluLookAt(
            cPers*sin(rotation_parametar+pi/4), cPers, cPers*cos(rotation_parametar+pi/4),
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
		DrawCircle();

		

	
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

static void on_reshape(int width, int height)
{
	
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(float)width/height, 1, 100);
}

static void on_timer(int id)
     {
         if(id != TIMER_ID)
          return;         
        
         if (pauseGame) {
             glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
         }
     
        glutPostRedisplay();
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