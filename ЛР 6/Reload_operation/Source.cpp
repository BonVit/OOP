#include <iostream>
#include "Number.h"
#include "Point.h"
#include "Vector.h"
#include "Matrix.h"
#include "Array.h"

using namespace std;

Number operator ++(Number&, int);
Point operator -(Point, Point);
Point operator -(Point, int);

int main()
{
	cout << "\t\t\t<<<<FIRST TASK>>>>\n";
	Number num;
	num.setData(5);
	cout << "Number is " << num.getData() << endl;
	cout << "Number--: ";
	num--;
	cout << num.getData() << endl;
	cout << "Number++: ";
	num++;
	cout << num.getData() << endl;

	cout << "\n\t\t\t<<<<SECOND TASK>>>>\n";
	Point p1, p2;
	p1.setX(2);
	p1.setY(3);
	cout << "Point1: " << p1.getX() << " " << p1.getY() << endl;
	p2 = p1 - 5;
	cout << "Point2: " << p2.getX() << " " << p2.getY() << endl;
	if(p1 == p2)
	{
		p2 = p2 + p1;
		cout << "Point1: " << p1.getX() << " " << p1.getY() << endl;
		cout << "Point2: " << p2.getX() << " " << p2.getY() << endl;
	}

	cout << "\n\t\t\t<<<<THIRD TASK>>>>\nVector1: ";
	Vector vec1(6);
	for(int i(0); i < vec1.size(); i++)
	{
		vec1[i] = i + 1;
		cout << vec1[i] << " ";
	}
	Vector vec2(vec1);
	cout << "\nVector2: ";
	for(int i(0); i < vec2.size(); i++)
	{
		vec2[i] += 5;
		cout << vec2[i] << " ";
	}

	cout << "\n\n\t\t\t<<<<FOURTH TASK>>>>\n";
	Matrix mat1(2, 3);
	cout << "Enter first " << mat1.getN() << "x" << mat1.getM() << " matrix:\n";
	cin >> mat1;
	Matrix mat2;
	mat2 = mat1;
	for(int i(0), k(0); i < mat2.getN(); i++)
	{
		for(int j(0); j < mat2.getM(); j++)
		{
			mat2[i][j] += vec1[k];
			k++;
		}
	}
	cout << "Matrix1:\n" << mat1 << "\nMatrix2:\n" << mat2 << endl;

	cout << "\n\t\t\t<<<<FIFTH TASK>>>>\n";
	Point tmp;
	tmp.setX(0);
	tmp.setY(0);
	Array<Point> arr(4, tmp);
	for(int i(0); i < int(arr); i++)
	{
		arr[i].setX(i);
		arr[i].setY(i + 1);
	}
	
	Array<Point> arr2;
	arr2 = arr;
	cout << "Array:\n";
	for(int i(0); i < arr.getSize(); i++)
	{
		cout << arr[i].getX() << " " << arr[i].getY();
		cout << endl;
	}

	system("pause");
	return 0;
}

Number operator ++(Number& a, int)
{
	a.data++;
	return a;
}

Point operator -(Point a, Point b)
{
	Point tmp;
	tmp.x = a.x - b.x;
	tmp.y = a.y - b.y;
	return tmp;
}

Point operator -(Point a, int b)
{
	Point tmp;
	tmp.x = a.x - b;
	tmp.y = a.y - b;
	return tmp;
}