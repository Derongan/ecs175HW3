#include <GL/glut.h>
#include "graphics.h"
#include "list.h"

void display();

graphics* g;

int main(int argc, char *argv[])
{
	//Setup graphics object;

	g = new graphics(800, 600);

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


	glutMainLoop();//main display loop, will display until terminate
	return 0;
}

void display()
{
	//Misc.
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	g->resetTransform();
	g->clearBuffer();
	g->clearZBuffer();

	g->setColor((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand()/RAND_MAX);

	//g->rotate(400, 200, .17);
	
	float triangle[] = { 
		200,200,.1,
		400,200,.1,
		200,400, .1
	};

	g->fillPolygonPlanar(triangle,3);

	//g->fillPolygonPlanar(triangle2,3);

	glDrawPixels(g->width, g->height, GL_RGB, GL_FLOAT, g->getCurrentBuffer());

	//window refresh
	glFlush();
}