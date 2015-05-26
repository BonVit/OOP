#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

void Car::setPrice(const double& price)
{
	Car::price_per_hour = price;
}

void Car::show()
{
	cout << "\tCar" << endl;
	cout << "Name:\t\t" << name << endl;
	cout << "Age:\t\t" << age << endl;
	cout << "Price:\t\t" << price_per_hour << endl;
}

double Car::getPrice()
{
	return price_per_hour;
}

Car::Car(char* nam, const int& age, const double& price)
{
	name = nam;
	Car::age = age;
	Car::price_per_hour = price;
	is_okay = 1;
}

void Car::setOkay(int k)
{
	is_okay = k;
}

int Car::getOkay()
{
	return is_okay;
}

void Car::setName(char* nam)
{
	Car::name = nam;
}

void Car::setAge(const int& age)
{
	Car::age = age;
}
	
string Car::getName()
{
	return name;
}

int Car::getAge()
{
	return age;
}

Car::Car(Car* car)
{
	name = car->getName();
	age = car->getAge();
	price_per_hour = car->getPrice();
	is_okay = car->getOkay();
}

Car::Car(void)
{
}


Car::~Car(void)
{
}
