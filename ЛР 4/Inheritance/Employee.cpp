#include "Employee.h"
#include <iostream>

void Employee::showId()
{
	std::cout << getId();
}

Employee::Employee(const int& age, const int& salary) : Person(age, salary)
{
}

Employee::Employee(void)
{
}


Employee::~Employee(void)
{
}
