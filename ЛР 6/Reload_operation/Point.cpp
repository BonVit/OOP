#include "Point.h"

void Point::setX(int a)
{
	x = a;
}

void Point::setY(int a)
{
	y = a;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

Point Point::operator+(Point a)
{
	Point tmp;
	tmp.x = a.x + x;
	tmp.y = a.y + y;
	return tmp;
}

Point Point::operator +(int a)
{
	Point tmp;
	tmp.x = x + a;
	tmp.y = y + a;
	return tmp;
}

Point Point::operator =(Point a)
{
	x = a.x;
	y = a.y;
	return *this;
}

bool Point::operator ==(Point a)
{
	if(x == a.x && y == a.y)
		return true;
	return false;
}

Point::Point(Point& a)
{
	x = a.x;
	y = a.y;
}

Point::Point(void)
{
}


Point::~Point(void)
{
}
