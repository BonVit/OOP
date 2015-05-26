#pragma once

#include <iostream>

using namespace std;

class Form
{
private:
	int age;
	string name;
public:
	int time;
	int number;
	virtual void setNumber(int n){number = n;}
	void setTime(int t){time = t;}
	
	void show()
	{
		cout << "Name:\t\t" << name.data() << endl;
		cout << "Age:\t\t" << age << endl;
		cout << "Time:\t\t" << time << endl;
		cout << "Number:\t\t" << number << endl;
	}

	int getAge()
	{
		return age;
	}

	void setAge(int a)
	{
		age = a;
	}

	string getName()
	{
		return name;
	}

	void setName(char* s)
	{
		name = s;
	}

	Form(void);
	virtual ~Form(void);
};

