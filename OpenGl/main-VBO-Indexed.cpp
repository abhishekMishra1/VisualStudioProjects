#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
 					 
float vertices[] = { 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 1.0,  
	                 0.5, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0,
					 -0.5, 0.0, 0.0,0.0, 0.0, 1.0, 1.0};
unsigned char indices[] = {0, 1, 2};

GLuint trianglePositiongVBOID;
GLuint triangleIndexVBOID;


int initializeVBOIndexes(int size, unsigned char arr[]) {
	//generate ID for the buffer object
	GLuint ids[1];
	
	glGenBuffers(1, ids);

	if(ids[0] < 0) {
		printf("Unable to generate ID for VBO");
		return -1;
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ids[0]);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, arr, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return ids[0];
}
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIndexVBOID);
	//specify where and how vertex data is stored
	glVertexPointer(3, GL_FLOAT, 28, 0);

	glColorPointer(4, GL_FLOAT, 28, (void*)12);

	//send data to graphics pileline
//	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, 0);

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

	//initialize VBO
	trianglePositiongVBOID = initializeVBO(84, vertices);
	triangleIndexVBOID = initializeVBOIndexes(3, indices);
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