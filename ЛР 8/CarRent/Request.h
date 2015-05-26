#pragma once

#include <string>
#include "Car.h"

using namespace std;

class Request
{
private:
	string name;
	int age;
	Car* car;
	bool is_okay;
public:
	void setCar(Car* c)
	{
		car = c;
	}

	Car* getCar()
	{
		return car;
	}

	void setName(string nam)
	{
		name = nam;
	}

	void setAge(int ag)
	{
		age = ag;
	}

	string getName()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}

	bool isOkay()
	{
		return is_okay;
	}

	void setOkay(bool ok)
	{
		is_okay = ok;
	}

	Request(string nam, int ag)
	{
		name = nam;
		age = ag;
		is_okay = false;
		car = NULL;
	}
	Request(void)
	{
		car = NULL;
		is_okay = false;
	}
	~Request(void){}
};