#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

void display();

void timerFunc(int val) {
	display();

	glutTimerFunc(100, timerFunc, 0);
}
void display(void) {
	printf("display\n");
	//fill the color buffer with the clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glutSwapBuffers();
}

void reshape(int width, int height) {
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