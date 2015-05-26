#include "Number.h"

void Number::setData(int a)
{
	data = a;
}

int Number::getData()
{
	return data;
}

Number Number::operator --(int)
{
	data--;
	return *this;
}

Number::Number(void)
{
}


Number::~Number(void)
{
}
