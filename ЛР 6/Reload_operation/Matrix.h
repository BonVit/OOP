#pragma once
#include <iostream>

class Matrix
{
private:
	long **arr;
	int n;
	int m;
	bool error;
	void deleteArr();
	void setArr(long);
public:

	void resize(int, int);
	int getN();
	int getM();

	long* operator [](int);
	Matrix& operator =(Matrix&);
	friend std::istream& operator >>(std::istream&, Matrix&);
	friend std::ostream& operator <<(std::ostream&, Matrix&);

	Matrix(Matrix&);
	Matrix(int, int);
	Matrix(int);
	Matrix(void);
	~Matrix(void);
};

