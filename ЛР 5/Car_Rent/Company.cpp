#include "Company.h"
#include <iostream>
using namespace std;

void Company::show()
{
	cout << "\t\t<<Company>>" << endl;
	cout << "Name:\t\t" << name << endl;
	cout << "Age:\t\t" << age << endl;
	cout << "Money:\t\t" << money << endl;
	cout << "Available cars:\n";
	for(int i(0); i < cars.size(); i++)
	{
		if(timer[i] == 0)
		{
			cars[i].show();
		}
	}
	administrator.show();
}

void Company::setAdm(const Administrator& administrator)
{
	Company::administrator = administrator;
}

Administrator Company::getAdm()
{
	return administrator;
}

void Company::addCar(const Car& car)
{
	cars.push_back(car);
	timer.push_back(0);
	countCars(1);
}

vector<Car> Company::getCars()
{
	return cars;
}

vector<int>& Company::getTimer()
{
	return timer;
}

void Company::addMoney(double mon)
{
	money += mon;
}

void Company::getCarBack(int number, int okay)
{
	money += administrator.penalty(okay, cars[number].getPrice());
	timer[number] = 0;
	cars[number].setOkay(1);
	countCars(1);
}

Company::Company(char* name, const int& age)
{
	Company::name = name;
	Company::age = age;
	money = 0;
}

Company::Company(Company& comp)
{
	name = comp.getName();
	age = comp.getAge();
	administrator = comp.getAdm();
	cars = comp.getCars();
	timer = comp.getTimer();
}

Company::Company(void)
{
	money = 0;
}


Company::~Company(void)
{
}
