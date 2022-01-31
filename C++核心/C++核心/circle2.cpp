#include <iostream>
#include "point.h"
#include "circle2.h"
using namespace std;

void Circle2::setR(int n)
{
	r = n;
}

int Circle2::getR()
{
	return r;
}

int Circle2::getX()
{
	return x;
}

int Circle2::getY()
{
	return y;
}

void Circle2::setX(int n)
{
	x = n;
}

void Circle2::setY(int n)
{
	y = n;
}

bool Circle2::ifPointInCircle(Point p)
{
	double ds = getDistance(p);
	return (ds < r*r);
}

double Circle2::getDistance(Point p)
{
	int px = p.getX(), py = p.getY();
	return (x - px)*(x - px) + (y - py)*(y - py);
}

void func_22()
{
	Circle2 c;
	Point p;
	c.setR(5);
	c.setX(0);
	c.setY(0);

	p.setX(4);
	p.setY(0);
	cout << c.ifPointInCircle(p) << endl;
}

