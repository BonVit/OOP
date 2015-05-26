#include "Vector.h"

void Vector::writeToFile(std::ofstream& fout)
{
	for(int i(0); i < n; i++)
		fout << arr[i] << " ";
}

Vector Vector::operator =(Vector a)
{
	if(arr != 0)
		delete [] arr;
	arr = new long [a.n];
	for(int i(0); i < a.n; i++)
		arr[i] = a.arr[i];
	n = a.n;
	error = a.error;
	return *this;
}

long& Vector::operator [](int i)
{
	if(i >= 0 && i < n)
		return arr[i];
	error = 1;
	throw "WTF?!";
}

void Vector::set(int num)
{
	if(num < 0)
		return;
	if(arr != 0)
		delete [] arr;
	arr = new long [num];
}

int Vector::size()
{
	return n;
}

Vector::Vector(Vector& a)
{
	if(arr != 0)
		delete [] arr;
	arr = new long [a.n];
	for(int i(0); i < a.n; i++)
		arr[i] = a.arr[i];
	error = a.error;
	n = a.n;
}

Vector::Vector(int num, long data)
{
	n = num;
	arr = new long [n];
	for(int i(0); i < n; i++)
		arr[i] = data;
	error = 0;
}

Vector::Vector(int num)
{
	n = num;
	arr = new long [n];
	for(int i(0); i < n; i++)
		arr[i] = 0;
	error = 0;
}

Vector::Vector(void)
{
	arr = 0;
	error = 0;
}


Vector::~Vector(void)
{
	if(arr != 0)
		delete [] arr;
}
