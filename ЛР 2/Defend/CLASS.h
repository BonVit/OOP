#pragma once
#include <iostream>

using namespace std;

class CLASS
{
private:
	int a, b;
	double c;
public:
	CLASS(void);
	CLASS(int, int, double);

	int get_a(){return a;}
	
	int get_b(){return b;}
	double get_c(){return c;}

	void change(int, int, double);

	void fill_from_keyboard();

	~CLASS(void);
};

