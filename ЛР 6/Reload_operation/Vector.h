#pragma once
#include <fstream>

class Vector
{
private:
	long *arr;
	int n;
	bool error;
public:
	void set(int);
	int size();

	long& operator [](int);
	Vector operator =(Vector);

	void writeToFile(std::ofstream&);

	Vector(Vector&);
	Vector(int, long);
	Vector(int);
	Vector(void);
	~Vector(void);
};

