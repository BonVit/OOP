#include "Client.h"
#include "Company.h"
#include <iostream>
using namespace std;

void Client::show()
{
	cout << "\t\tClient" << endl;
	cout << "Name:\t\t" << name << endl;
	cout << "Age:\t\t" << age << endl;
	cout << "Money:\t\t" << money << endl;
}

int Client::chooseCar(vector<Car> cars, vector<int> timer)
{
	char choose;
	for(int i(0); i < cars.size(); i++)
	{
		if(timer[i] != 0)
			continue;
		if(cars[i].getPrice() > money)
			continue;
		cars[i].show();
		cout << "y/n?";
		cin >> choose;
		if(choose == 'y')
			return i;
	}
	system("cls");
	return -1;
}

void Client::setForm(int t, int n)
{
	form.setAge(age);
	form.setName((char*)name.data());
	form.setTime(t);
	form.setNumber(n);
}

void Client::setCar(Car vehicle)
{
	car = new Car;
	*car = vehicle;
	Company::countCars(-1);
}

Car& Client::getCar()
{
	return *car;
}

void Client::subMoney(double mon)
{
	money -= mon;
}

void Client::returnCar()
{
	delete car;
	car = NULL;
}

Client::Client(char* name, const int& age, const int& money)
{
	Client::name = name;
	Client::age = age;
	Client::money = money;
	car = NULL;
}

Client::Client(Client& client)
{
	if(car != NULL)
		delete car;
	car = new Car;
	name = client.getName();
	age = client.getAge();
	*car = client.getCar();
}

Client::Client(void)
{
}


Client::~Client(void)
{
	if(car != NULL)
		delete car;
}
