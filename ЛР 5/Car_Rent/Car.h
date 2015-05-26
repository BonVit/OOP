#pragma once

#include <string>
#include "Person.h"

class Car
{
private:
	double price_per_hour;
	int is_okay;
protected:
	string name;
	int age;
public:
	virtual void setPrice(const double&);
	
	void show();

	double getPrice();

	void setOkay(int);
	int	getOkay();


	void setName(char* nam);

	void setAge(const int& age);
	
	string getName();

	int getAge();


	Car(char*, const int&, const double&);	
	Car(Car*);
	Car(void);
	virtual ~Car(void);
};

