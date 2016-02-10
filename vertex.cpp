#include "vertex.h"

vertex::vertex(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0;
}

vertex::vertex(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


vertex::~vertex()
{
}
