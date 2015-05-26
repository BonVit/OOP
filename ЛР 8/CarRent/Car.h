#pragma once

#include <string>
using namespace std;

class Car
{
private:
	int price;
	string name;
public:
	bool operator ==(Car c)
	{
		if(price == c.price && name == c.name)
			return true;
		return false;
	}

	void setPrice(int price)
	{
		Car::price = price;
	}

	int getPrice()
	{
		return price;
	}

	void setName(string name)
	{
		Car::name = name;
	}
	
	string getName()
	{
		return name;
	}

	Car(string name, int price)
	{
		Car::name = name;
		Car::price = price;
	}
	Car(void){}
	~Car(void){}
};