#pragma once

#include <string>

using namespace std;

class Person
{
protected:
	string		name;
	int			age;
public:
	void setName(const char*);
	void setAge(const int&);

	string getName();
	int getAge();

	virtual void show() = 0;

	Person(void);
	~Person(void);
};

