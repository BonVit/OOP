#pragma once

#include "Person.h"

class Employee : private Person
{
public:
	Person::name;
	Person::surname;
	Person::showString;
	Person::getId;
	Person::setAge;
	Person::nationality;

	using Person::sex;

	void showId();

	Employee(const int&, const int&);
	Employee(void);
	~Employee(void);
};

