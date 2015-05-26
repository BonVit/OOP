#pragma once

#include <iostream>
#include <string>
#include "Request.h"

using namespace std;

class Admin
{
private:
	string name;
	string pass;
public:
	Request* request;
	
	void setName(char* nam)
	{
		name = nam;
	}

	void setPass(char* pas)
	{
		pass = pas;
	}

	string getName()
	{
		return name;
	}

	string getPass()
	{
		return pass;
	}
	
	Admin(char* nam, char* pas)
	{
		name = nam;
		pass = pas;
		request = new Request();
	}

	Admin(void);
	~Admin(void);
};