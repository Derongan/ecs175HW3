#include <GL/glut.h>
#include "graphics.h"
#include "list.h"

void display();
void mouseDownF(int, int, int, int);
void mouseMove(int, int);

graphics* g;

int viewX = 400;
int viewY = 300;
float viewZ = -1;

int mouseDown = false;

int lastX;
int lastY;

int main(int argc, char *argv[])
{
	//Setup graphics object;

	g = new graphics(800, 600);
	g->setViewPoint(400, 300, -1);

	//allocate new pixel buffer, need initialization!!
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	//set window size to 200*200
	glutInitWindowSize(g->width, g->height);
	//set window position
	glutInitWindowPosition(100, 100);

	//create and set main window title
	int MainWindow = glutCreateWindow("Landscape");
	glClearColor(0, 0, 0, 0); //clears the buffer of OpenGL
	glutDisplayFunc(display); //sets display function
	glutMouseFunc(mouseDownF);
	glutMotionFunc(mouseMove);


	glutMainLoop();//main display loop, will display until terminate
	return 0;
}

void mouseDownF(int button, int state, int x, int y) {
	if (button == 3) {
		if (state == GLUT_UP) {
			viewZ-=.1;
		}
	}
	else if(button == 4) {
		if (state == GLUT_UP) {
			viewZ += .1;
		}
	}
	else if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			mouseDown = true;
			lastX = x;
			lastY = y;
		}
		else if (state == GLUT_UP) {
			mouseDown = false;
		}
	}

	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	if (mouseDown) {
		int dx = x - lastX;
		int dy = y - lastY;
		lastX = x;
		lastY = y;

		viewX += dx;
		viewY += dy;
	}
	glutPostRedisplay();
}

void display()
{
	//Misc.
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	g->resetTransform();
	g->clearBuffer();
	g->clearZBuffer();

	g->setViewPoint(viewX, viewY, viewZ);

	g->setColor(0,1,0);

	//g->rotate(400, 200, .17);
	
	float triangle[] = { 
		100,100,1,
		400,100,0,
		400,500,1
	};

	g->fillPolygonPlanar(triangle,3);


	g->setColor(0,1,0);

	//g->rotate(400, 200, .17);

	float triangle2[] = {
		400,100,0,
		700,100,1,
		400,500,1
	};

	g->fillPolygonPlanar(triangle2, 3);

	g->setColor(0,1,0);

	//g->rotate(400, 200, .17);

	float triangle3[] = {
		100,100,1,
		400,500,1,
		400,100,1
	};

	g->fillPolygonPlanar(triangle3, 3);

	//g->fillPolygonPlanar(triangle2,3);

	g->setColor(1, 0, 0);

	float landscape[] = {
		0,0,0,
		799,0,0,
		799,0,1,
		0,0,1
	};

	g->fillPolygonPlanar(landscape, 4);

	g->setColor(0, 0, 1);

	float square[] = {
		100,100,.6,
		200,100,.6,
		200,200,.6,
		100,200,.6
	};

	g->fillPolygonPlanar(square, 4);

	float square2[] = {
		100,100,.4,
		200,100,.4,
		200,200,.4,
		100,200,.4
	};

	g->fillPolygonPlanar(square2, 4);

	float square3[] = {
		100,100,.4,
		100,100,.6,
		100,200,.6,
		100,200,.4
	};

	g->fillPolygonPlanar(square3, 4);

	float square4[] = {
		200,100,.4,
		200,100,.6,
		200,200,.6,
		200,200,.4
	};

	g->fillPolygonPlanar(square4, 4);

	glDrawPixels(g->width, g->height, GL_RGB, GL_FLOAT, g->getCurrentBuffer());

	//window refresh
	glFlush();
}