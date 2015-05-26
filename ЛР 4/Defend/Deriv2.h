#pragma once
#include "Deriv.h"
#include <iostream>

using namespace std;

class Deriv2 : public Deriv
{
public:
	int dataD2;

	void show()
	{
		cout << "DataD2: " << dataD2 << endl;
		cout << "DataD: " << dataD << endl;
		cout << "Data1: " << data1 << endl;
		cout << "Data2: " << getData2() << endl;
		cout << "Data3: " << data3 << endl;
	}

	Deriv2(const int& dataD2, const int& dataD, const int& data1, const int& data2, const int& data3) : Deriv(dataD), Base1(data1), Base3(data3)
	{
		Deriv2::dataD2 = dataD2;
		setData2(data2);
	}
	Deriv2(void);
	~Deriv2(void);
};

