#pragma once
class Point
{
private:
	int x;
	int y;
public:
	void setX(int);
	void setY(int);
	int getX();
	int getY();

	Point operator +(Point);
	Point operator +(int);
	friend Point operator -(Point, Point);
	friend Point operator -(Point, int);

	Point operator =(Point);
	bool operator ==(Point);

	Point(Point&);
	Point(void);
	~Point(void);
};

