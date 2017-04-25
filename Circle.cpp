#include "Circle.h"

circle::circle()
{
	this->setX(0);
	this->setY(0);
	this->setRadius(10);
}

circle::circle(double x_in, double y_in, double radius_in)
{
	this->setX(x_in);
	this->setY(y_in);
	this->setRadius(radius_in);
}

circle::~circle()
{

}

double circle::getX()
{
	return this->x;
}

double circle::getY()
{
	return this->y;
}

double circle::getRadius()
{
	return this->radius;
}

double circle::getSpeedX()
{
	return this->xSpeed;
}

double circle::getSpeedY()
{
	return this->ySpeed;
}

double circle::getRed()
{
	return this->red;
}

double circle::getGreen()
{
	return this->green;
}

double circle::getBlue()
{
	return this->blue;
}

void circle::setX(double x_in)
{
	this->x = x_in;
}

void circle::setY(double y_in)
{
	this->y = y_in;
}
	
void circle::setRadius(double radius_in)
{
	this->radius = radius_in;
}

void circle::setSpeeds(double xs, double ys)
{
	this->xSpeed = xs;
	this->ySpeed = ys;
}

void circle::setColors(double c1, double c2, double c3)
{
	this->red = c1;
	this->green = c2;
	this->blue = c3;
}

void circle::draw()
{
	double x1 = this->x;
	double y1 = this->y;
	double radius = this->radius;
	glBegin(GL_POLYGON);
	for(int i=0; i<32; i++)
	{
		double theta = (double)i/32.0 * 2.0 * 3.1415926;
		double x = x1 + radius * cos(theta);
		double y = y1 + radius * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}