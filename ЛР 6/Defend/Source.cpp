#include <iostream>
#include <conio.h>
#include <fstream>
#include "Administrator.h"
#include "Company.h"
#include "Client.h"
#include "Park.h"

using namespace std;

void menu();
int del(Administrator*, int, int);

int main(int argc, int **argv)
{
	Company toyota("Toyota", 10);
	Administrator adm("Takashi", 27);
	//toyota.setAdm(adm);
	toyota + adm;
	//toyota--;
	
	Car tmp("Toyota", 6, 1300);
	toyota.addCar(tmp);
	tmp.setName("Shkoda");
	tmp.setAge(10);
	tmp.setPrice(400);
	toyota.addCar(tmp);
	tmp.setName("Merc");
	tmp.setAge(3);
	tmp.setPrice(2300);
	toyota.addCar(tmp);

	toyota[0].show();

	cout << endl;
	Client client("Vitaliy", 19, 50000.52);
	cout << endl;

	char choose;
	do
	{
		toyota.show();
		cout << "\nCars: " << toyota.countCars(0) << endl;
		client.show();
		int hours;
		cout << "\nEnter number of hours:\n";
		cin >> hours;
		cout << "\nChoose the car: \n";
		if(toyota.getAdm().giveForm(client))
			client.setForm(hours, client.chooseCar(toyota.getCars(), toyota.getTimer()));
		if(toyota.getAdm().checkForm(client.form) != -1)
		{
			cout << "Please confirm your request! y/n\n";
			cin >> choose;
			if(choose == 'y')
			{
				client.setCar(toyota.getCars()[client.form.number]);
				toyota.getTimer()[client.form.number] = client.form.time;
				client.subMoney(client.getCar().getPrice() * client.form.time);
				toyota.addMoney(client.getCar().getPrice() * client.form.time);
			}
		}
		else
		{
			cout << "\nU didnt choose a car! Bye!\n";
			_getch();
			return 0;
		}

		client.getCar().setOkay(0); //crush the car

		toyota.show();
		cout << "Cars:\n" << toyota.countCars(0) << endl;

		client.subMoney(toyota.getAdm().penalty(client.getCar().getOkay(), client.getCar().getPrice()));
		toyota.getCarBack(client.form.number, client.getCar().getOkay());
		client.returnCar();

		toyota.show();
		cout << "Cars:\n" << toyota.countCars(0) << endl;

		cout << "\nAgain?y/n\n";
		cin >> choose;
		system("cls");
	}while(choose == 'y');
	

	Administrator stat[5];
	Administrator *dyn = new Administrator[5];
	try
	{
		if(dyn == NULL)
			throw "Pointer is NULL";
	}
	catch(char* s)
	{
		cout << s;
		_getch();
		return -1;
	}
	for(int i(0); i < 5; i++)
	{
		stat[i].fillFromKeyboard();
		dyn[i] = stat[i];
	}
	system("cls");
	for(int i(0); i < 5; i++)
	{
		dyn[i].show();
	}
	
	try
	{
		cout << "\n\n\t\tDELETED\n";
		int n = del(dyn, 5, 18);
		for(int i(0); i < n; i++)
			dyn[i].show();
	}
	catch(char* s)
	{
		cout << s << endl;
		_getch();
		return -1;
	}

	Administrator *obj = new Administrator;
	do
	{
		menu();
		cin >> choose;
		switch(choose)
		{
		case '1':
			if(obj != NULL)
				delete obj;
			obj = new Administrator;
			break;
		case '2':
			if(obj != NULL)
				delete obj;
			obj = NULL;
			break;
		}
	}while(choose == '1' || choose == '2');

	delete [] dyn;

	vector<Car> cars;
	for(int i(0); i < 5; i++)
	{
		Car *c = new Car;
		cars.push_back(c);
		delete c;
	}

	Park park;
	for(int i(0); i < 5; i++)
	{
		park.addCar(cars[i]);
	}


	_getch();
	return 0;
}

void menu()
{
	cout << "\t\t\tMENU\n";
	cout << "1) add element\n";
	cout << "2) delete element.\n";
	cout << "e - exit\n";
}

int del(Administrator* arr, int n, int age)
{
	if(arr == NULL)
	{
		throw "Array == NULL\n";
		return 0;
	}
	if(n < 0)
	{
		throw "Illegal array size!";
		return 0;
	}

	for(int i(0); i < n; i++)
	{
		if(arr[i].getAge() < age)
		{
			for(int j(i); j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			n--;
		}
	}
	return n;
}