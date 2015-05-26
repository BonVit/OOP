#pragma once

#include "Person.h"
#include "Form.h"
#include <iostream>
#include "Client.h"

using namespace std;

class Administrator : public Person
{
public:
	
	static int view(int k)
	{
		static int count = 0;
		
		count += k;
		
		return count;
	}

	void show();

	int checkForm(Form);

	int giveForm(Client&);

	virtual double penalty(int, double);

	void fillFromKeyboard();

	void readFromFile(char*);
	void writeToFile(char*);
	
	Administrator(char*, const int&);
	Administrator(Administrator&);
	Administrator(void);
	~Administrator(void);
};

