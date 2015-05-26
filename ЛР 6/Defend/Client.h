#pragma once
#include "Person.h"
#include "Car.h"
#include <vector>
#include "Form.h"

class Client : public Person
{
private:
	double money;
	Car* car;
public:
	Form form;

	void show();

	int chooseCar(vector<Car>, vector<int>);
	virtual void setForm(int t, int n);

	void setCar(Car vehicle);

	void createForm()
	{
		setForm(0, 0);
	}

	Car& getCar();

	void subMoney(double mon);

	void returnCar();

	Client(char*, const int&, const int&);
	Client(Client&);
	Client(void);
	~Client(void);
};