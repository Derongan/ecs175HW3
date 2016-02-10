#pragma once
#include <math.h>
#include <algorithm>
#include "list.h"
#include "vertex.h"

class graphics
{
private:
	float color[4];
	float *buffer;
	float *zbuffer;

	float viewPoint[3];
	float viewUp[3];
	float zView[3];

	float resetMatrix[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};

	float transformationMatrix[4][4] = {
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 }
	};

public:
	int width;
	int height;

	graphics(int width = 200, int height = 200);
	~graphics();
	void setPixel(int, int);
	void setColor(float, float, float);
	void bLine(int,int,int,int);
	float * getCurrentBuffer();
	void clearBuffer();
	void clearZBuffer();
	void fillPolygon(float* points, int num);
	void fillPolygon(vertex* verticies, int num);
	void fillPolygonZ(float *points, int num, float z);
	void strokePolygon(float* points, int num);
	void fillPolygonPlanar(float *points, int num);
	void applyTransformationMatrix(float *points, int num);
	void addTransform(float matrix[][4]);
	void resetTransform();

	//Transformations
	void rotate(float x, float y, float theta);	//Theta in radians
	void translate(float x, float y, float z);

	//3D
	void setViewPoint(float x, float y, float z);
	void setViewUp(float dx, float dy, float dz);
	void setZView(float dx, float dy, float dz);

	void project(float* points, int num);
};