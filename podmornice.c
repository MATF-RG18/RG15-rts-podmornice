#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>






static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);


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

	
	glClearColor(0.4,0.4,0.4,1);

	glEnable(GL_DEPTH_TEST);

	glLineWidth(1);	

	glutMainLoop();
	
	return 0;

}

static void on_keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
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

    int cPers = 2;

    gluLookAt(
            4*cPers, 3*cPers, 7*cPers,
            0, 0, 0,
            0, 1, 0
        );
    
    
    		


	glBegin(GL_LINES);

		glColor3f (0,0,1);
		glVertex3f(0,0,0);
		glVertex3f(50,0,0);

		glColor3f (0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(0,50,0);

		glColor3f (1,0,0);
		glVertex3f(0,0,0);
		glVertex3f(0,0,50);

		
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

