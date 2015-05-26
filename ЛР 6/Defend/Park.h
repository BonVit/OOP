#pragma once
#include "Car.h"
#include <vector>

class Park
{
private:
	vector <Car> cars;
public:
	void addCar(Car a)
	{
		cars.push_back(a);
	}
	vector<Car> getCar()
	{
		return cars;
	}
	Park(void);
	~Park(void);
};

