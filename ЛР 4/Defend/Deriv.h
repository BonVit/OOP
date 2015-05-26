#pragma once
#include "Base1.h"
#include "Base2.h"
#include "Base3.h"
#include <iostream>

using namespace std;

class Deriv : virtual public Base1, virtual private Base2, virtual protected Base3
{
public:
	int dataD;

	int getData2()
	{
		return data2;
	}
	
	void setData2(const int& data)
	{
		data2 = data;
	}

	Deriv(const int& data)
	{
		dataD = data;
	}
	Deriv(void);
	~Deriv(void);
};

