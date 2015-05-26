#pragma once

#include "Car.h"
#include <vector>
#include "Admin.h"

using namespace std;

class Company
{
private:
	Admin *adm;
	vector<Car>		cars;
	int				money;
public:
	void addCar(const Car& car)
	{
		cars.push_back(car);
	}

	void setAdm(Admin *a)
	{
		adm = a;
	}

	Admin* getAdm()
	{
		return adm;
	}

	vector<Car>& getCars()
	{
		return cars;
	}

	int getMoney()
	{
		return money;
	}

	void changeMoney(int money)
	{
		Company::money = Company::money + money;
	}

	Company(int money)
	{
		Company::money = money;
		adm = NULL;
	}
	Company(void){}
	~Company(void){}
};

