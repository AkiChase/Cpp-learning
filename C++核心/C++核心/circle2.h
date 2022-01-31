#pragma once
#include "point.h"

class Circle2
{
public:
	void setR(int n);
	int getR();
	int getX();
	int getY();
	void setX(int n);
	void setY(int n);
	bool ifPointInCircle(Point p);
private:
	int r;
	int x;
	int y;
	double getDistance(Point p);
};
