#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "glut.h"
#include <cmath>

class circle
{
public:
	circle();
	circle(double x_in, double y_in, double radius_in);
	~circle();
	double getX();
	double getY();
	double getRadius();
	double getSpeedX();
	double getSpeedY();
	double getRed();
	double getGreen();
	double getBlue();
	void setX(double x_in);
	void setY(double y_in);
	void setRadius(double radius_in);
	void setSpeeds(double xs, double ys);
	void setColors(double c1, double c2, double c3);
	void draw();
protected:
	double x, y, radius;
	double xSpeed, ySpeed;
	double red,green,blue;
};

#endif