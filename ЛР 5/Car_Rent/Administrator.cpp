#include "Administrator.h"
#include <fstream>

void Administrator::show()
{
	cout << "\tAdministrator" << endl;
	cout << "Name:\t\t" << name << endl;
	cout << "Age:\t\t" << age << endl;
}

int Administrator::checkForm(Form form)
{
	if(form.getAge() < 18)
	{
		cout << "U r too young!\n";
		return -1;
	}
	if(form.number == -1)
	{
		cout << "U didnt choose a car!\n";
		return -1;
	}
	return form.number;
}

double Administrator::penalty(int isOkay, double price)
{
	if(isOkay)
		return 0;
	else
		return price / 10;
}

int Administrator::giveForm(Client& a)
{
	a.createForm();
	return 1;
}

void Administrator::fillFromKeyboard()
{
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> age;
}

void Administrator::readFromFile(char *fname)
{
	ifstream fin(fname);
	if(fin.fail())
	{
		throw "Something goes wrong";
		return;
	}	
	char tmp[20];
	fin >> tmp;
	name = tmp;
	fin >> age;
	fin.close();
}

void Administrator::writeToFile(char *fname)
{
	ofstream fout(fname);
	if(fout.fail())
	{
		throw "Something goes wrong";
		return;
	}
	fout << name << endl;
	fout << age << endl;
}

Administrator::Administrator(char* name, const int& age)
{
	Administrator::name = name;
	Administrator::age = age;
	view(1);
}

Administrator::Administrator(Administrator& adm)
{
	name = adm.getName();
	age = adm.getAge();
	view(1);
}

Administrator::Administrator(void)
{
	view(1);
}


Administrator::~Administrator(void)
{
	view(-1);
}