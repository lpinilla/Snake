#include <GL/gl.h>
#include <GL/glut.h>
//#include "game.h"

/*
#define COLUMNS 5
#define ROWS 5
#define FPS 10

extern short sDirection;

void timer_callback(int);
void display_callback();
void reshape_callback(int, int);
void keyboard_callback(int, int, int); 
*/

void renderScene();
void changeSize(int w, int h);

int main(int argc, char ** argv){
	//init glut & create window

	glutInit(&argc, argv);
	glutInitWindowPosition(-1,-1);
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); //single necessary?
	glutCreateWindow("Shnek");


	//register callback
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	//enter glub event processing cycle	
	glutMainLoop();

	return 1;
}

void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3f(-2, -2,-5.0);
		glVertex3f(2, 0,-5.0);
		glVertex3f(0.0, 2,-5.0);
	glEnd();
	glutSwapBuffers();
}

void changeSize(int w, int h){
	h = (!h) ? 1: h;
	float ratio = 1.0f * w / h;	
	glMatrixMode(GL_PROJECTION); //projection matrix
	glLoadIdentity(); //Reset Matrix
	glViewport(0, 0, w, h); //set the viewport to the entire window
	gluPerspective(45, ratio, 1, 100); //set the correct perspective
	glMatrixMode(GL_MODELVIEW); //go back to model view
}

//compile with: -lglut -lGLU -ILG -lGL