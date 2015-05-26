#include "Matrix.h"

using namespace std;

void Matrix::resize(int n, int m)
{
	deleteArr();
	Matrix::n = n;
	Matrix::m = m;
}

int Matrix::getN()
{
	return n;
}

int Matrix::getM()
{
	return m;
}

std::istream& operator >>(std::istream& cin, Matrix& a)
{
	for(int i(0); i < a.n; i++)
		for(int j(0); j < a.m; j++)
			cin >> a[i][j];
	return cin;
}

std::ostream& operator <<(std::ostream& cout, Matrix& a)
{
	for(int i(0); i < a.n; i++, cout << endl)
		for(int j(0); j < a.m; j++)
			cout << a[i][j] << " ";
	return cout;
}

long* Matrix::operator [](int i)
{
	return arr[i];
}

Matrix& Matrix::operator =(Matrix& a)
{
	deleteArr();
	n = a.n;
	m = a.m;
	setArr(0);
	for(int i(0); i < n; i++)
		for(int j(0); j < m; j++)
			arr[i][j] = a.arr[i][j];
	error = a.error;
	return *this;
}

void Matrix::deleteArr()
{
	if(arr != NULL)
	{
		for(int i(0); i < n; i++)
			delete [] arr[i];
		delete [] arr;
	}
}

void Matrix::setArr(long data)
{
	arr = new long* [n];
	for(int i(0); i < n; i++)
	{
		arr[i] = new long [m];
		for(int j(0); j < m; j++)
			arr[i][j] = data;
	}
}

Matrix::Matrix(Matrix& a)
{
	deleteArr();
	n = a.n;
	m = a.m;
	setArr(0);
	for(int i(0); i < n; i++)
		for(int j(0); j < m; j++)
			arr[i][j] = a.arr[i][j];
	error = a.error;
}

Matrix::Matrix(int n, int m)
{
	deleteArr();
	Matrix::n = n;
	Matrix::m = m;
	setArr(0);
	error = 0;
}

Matrix::Matrix(int num)
{
	deleteArr();
	n = num;
	m = num;
	setArr(0);
	error = 0;
}

Matrix::Matrix(void)
{
	arr = NULL;
	error = 0;
	n = 0;
	m = 0;
}


Matrix::~Matrix(void)
{
	deleteArr();
}
