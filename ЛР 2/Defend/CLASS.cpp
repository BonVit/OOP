#include "CLASS.h"

CLASS::CLASS(void)
{
	a = 0;
	b = 0;
	c = 0;
}

CLASS::CLASS(int A, int B, double C)
{
	CLASS::change(A, B, C);
}

CLASS::~CLASS(void)
{
}

void CLASS::change(int A, int B, double C)
{
	a = A;
	b = B;
	c = C;
}

void CLASS::fill_from_keyboard()
{
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
}