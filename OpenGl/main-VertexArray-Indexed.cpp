#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
 					 
float vertices[] = { 0.0, 0.5, 0.0,  1.0 ,0.0, 0.0, 1.0,
	                 0.5, 0.0, 0.0,  0.0, 1.0, 0.0, 1.0,
					 -0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0};

unsigned char indices[] = {0, 2, 1};


void drawTriangle() {
	//enable sending vertex position data
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	//specify where and how vertex data is stored
	glVertexPointer(3, GL_FLOAT, 28, vertices);

	//specify where and how color data is stored
	glColorPointer(4, GL_FLOAT, 28, vertices + 3);

	//send data to graphics pileline
//	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

}

void display();

void timerFunc(int val) {
	display();

	glutTimerFunc(100, timerFunc, 0);
}
void display(void) {
	printf("display\n");
	//fill the color buffer with the clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glShadeModel(GL_SMOOTH);
	glColor3f(1.0, 0.0, 0.0);
	drawTriangle();

	glutSwapBuffers();
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
}

void init() {
	//specify the clearing color
	glClearColor(1.0, 1.0, 0.0, 1.0);


	//specify the clearing depth value
	glClearDepth(1.0);
}

int main(int argc, char** argv) {
	//initialize the glut library
	glutInit(&argc, argv);

	//initialize the display mode
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);

	//set the window and frame buffer size
	glutInitWindowSize(500, 500);

	glutCreateWindow("Hello GLUT");

	//initialize opengl state
	init();

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutTimerFunc(100, timerFunc, 0);
	glutMainLoop();
	return 1;
}