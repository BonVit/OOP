#include "Person.h"

#include <iostream>

using namespace std;

void Person::setName(const char* name)
{
	Person::name = name;
}

void Person::setAge(const int& age)
{
	Person::age = age;
}

string Person::getName()
{
	return name;
}

int Person::getAge()
{
	return age;
}

Person::Person(void)
{
}


Person::~Person(void)
{
}