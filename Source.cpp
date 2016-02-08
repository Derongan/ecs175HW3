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

	g->setColor(1, 0, 0);

	float poly[] = { 5,5,50,50,100,7,100,100,75,125,30,40,5,100,5,5 };

	g->fillPolygon(poly, 7);

	float poly2[] = { 5,5,100,7,100,100,5,100,5,5 };

	//g->fillPolygon(poly2, 5);
	
	glDrawPixels(g->width, g->height, GL_RGB, GL_FLOAT, g->getCurrentBuffer());

	//window refresh
	glFlush();
}