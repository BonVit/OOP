#pragma once

#include "Administrator.h"
#include "Car.h"
#include <vector>

class Company
{
private:
	Administrator	administrator;
	vector<Car>		cars;
	vector<int>		timer;
	double			money;
	string			name;
	int				age;
public:
	
	static int countCars(int k)
	{
		static int num = 0;
		num += k;
		if(num < 0)
			num = 0;
		if(num == 0)
			cout << "There are no cars!\n";
		return num;
	}


	void show();
	
	void setAdm(const Administrator&);
	
	Administrator getAdm();

	void addCar(const Car&);

	vector<Car>	getCars();

	vector<int>& getTimer();

	virtual void addMoney(double mon);

	void getCarBack(int number, int okay);

	void setName(const char* name)
	{
		Company::name = name;
	}

	void setAge(const int& age)
	{
		Company::age = age;
	}

	string getName()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}

	Company(char*, const int&);
	Company(Company&);
	Company(void);
	virtual ~Company(void);
};

