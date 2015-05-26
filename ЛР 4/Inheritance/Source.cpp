#include <iostream>
#include <conio.h>
#include <fstream>
#include "Person.h"
#include "Employee.h"
#include "Worker.h"
#include "Engineer.h"

using namespace std;

const int n = 1;

int Person::_num_workers;

class Friendly
{
public:
	void showAddress(const Person& tmp)
	{
		cout << tmp.address;
	}
};

class University
{
public:
	int data;

	University(int key){data = key;}
	University(){}
	~University(){}
};

class Graduator : public Person, public University
{
public:
	int data;

	Graduator(int key){data = key;}
	Graduator(){}
	~Graduator(){}
};

int main()
{
	Person	stat[n];
	Person*	dyn = new Person[n];

	ofstream fout("data.txt");
	for(int i(0); i < n; i++)
	{
		stat[i].fillFromKeyboard();
		stat[i].writeToFile(fout);
		system("cls");
	}
	fout.close();

	ifstream fin("data.txt");
	for(int i(0); i < n; i++)
	{
		dyn[i].readFromFile(fin);
		dyn[i].show();
		cout << endl;
	}
	cout << "Press any key..." << endl;
	_getch();
	system("cls");
	fin.close();

	Person temp(dyn[0]);
	temp.show();

	_getch();
	return 0;
}

void showAddress(const Person& tmp)
{
	cout << tmp.address;
}