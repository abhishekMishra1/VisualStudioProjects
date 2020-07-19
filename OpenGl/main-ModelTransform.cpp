#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
 					 
float vertices[] = { 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 1.0,  
	                 0.5, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0,
					 -0.5, 0.0, 0.0,0.0, 0.0, 1.0, 1.0};
GLuint trianglePositiongVBOID;


int initializeVBO(int size, float arr[]) {

	//generate ID for the buffer object
	GLuint ids[1];
	
	glGenBuffers(1, ids);

	if(ids[0] < 0) {
		printf("Unable to generate ID for VBO");
		return -1;
	}

	//bind to that VBO
	glBindBuffer(GL_ARRAY_BUFFER, ids[0]);

	//allocate memory for the VBO
	glBufferData(GL_ARRAY_BUFFER, size, arr, GL_STATIC_DRAW);

	//unbind from the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return ids[0];

}

void drawTriangle() {
	//enable sending vertex position data
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//bind to the VBO that contains vertex positiond data
	glBindBuffer(GL_ARRAY_BUFFER, trianglePositiongVBOID);

	//specify where and how vertex data is stored
	glVertexPointer(3, GL_FLOAT, 28, 0);

	glColorPointer(4, GL_FLOAT, 28, (void*)12);

	//send data to graphics pileline
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

}

void display();

void timerFunc(int val) {
	display();

	glutTimerFunc(100, timerFunc, 0);
}

float angle = 0.0f;
float xPos = 0.0;
void display(void) {
	printf("display\n");
	//fill the color buffer with the clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glShadeModel(GL_SMOOTH);
	glColor3f(1.0, 0.0, 0.0);

	angle += 1.0f;
	if(angle >= 360.0) {
		angle = 0.0;
	}
	xPos += 0.1;
	if(xPos >= 1.0) {
		xPos = -1.0;
	}
	//set the model view matrix as current matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(angle, 0.0, 1.0, 0.0);


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

	//initialize VBO
	trianglePositiongVBOID = initializeVBO(84, vertices);
}

int main(int argc, char** argv) {
	//initialize the glut library
	glutInit(&argc, argv);

	//initialize the display mode
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);

	//set the window and frame buffer size
	glutInitWindowSize(500, 500);

	glutCreateWindow("Hello GLUT");

	glewInit();

	//initialize opengl state
	init();

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutTimerFunc(100, timerFunc, 0);
	glutMainLoop();
	return 1;
}