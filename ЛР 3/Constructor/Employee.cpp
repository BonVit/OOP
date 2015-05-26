#include "Employee.h"
#include <fstream>
#include <iostream>

using namespace std;

#define lim 50000
#define n_hours_month 840

int Employee::change_salary(const double& salary)
{
	if(Employee::salary + salary > lim || Employee::salary + salary < 0)
		return -1;
	Employee::salary += salary;
	return 0;
}

int Employee::change_n_hours(const double& n_hours)
{
	if(Employee::n_hours + n_hours > 0 || Employee::n_hours + n_hours > n_hours_month)
		return -1;
	Employee::n_hours += n_hours;
	return 0;
}

int Employee::increase(const double& salary, const int& experience)
{
	if(Employee::experience < experience)
		return -1;
	change_salary(salary);
	return 0;
}

int Employee::increase(const double& salary, const int& experience, const int& age)
{
	if(Employee::experience < experience && Employee::age > age)
		return -1;
	change_salary(salary);
	return 0;
}

void Employee::read_from_file(ifstream& fin)
{
	fin.getline(name, sizeof(name));
	fin.getline(surname, sizeof(surname));
	fin >> age >> experience >> salary >> n_hours;
	fin.getline(cell, sizeof(cell));
	fin.getline(cell, sizeof(cell));
	fin.getline(address, sizeof(address));
}

void Employee::write_to_file(ofstream& fout)
{
	static bool flag = 0;
	if(flag)
		fout << std::endl;
	else
		flag = 1;
	fout << name << endl << surname << endl;
	fout << age << endl << experience << endl;
	fout << salary << endl << n_hours << endl;
	fout << cell << std::endl << address;
}

void Employee::fill_from_keyboard()
{
	cout << "Enter name: ";
	cin.getline(name, sizeof(name));
	cout << "Enter surname: ";
	cin.getline(surname, sizeof(surname));
	cout << "Enter address: ";
	cin.getline(address, sizeof(address));
	cout << "Enter cell: ";
	cin.getline(cell, sizeof(cell));
	cout << "Enter age: ";
	cin >> age;
	cout << "Enter salary: ";
	cin >> salary;
	cout << "Enter number of worked hours: ";
	cin >> n_hours;
	cout << "Enter experience: ";
	cin >> experience;
}

void Employee::show_on_console()
{
	cout << "Name:\t\t\t" << name << std::endl;
	cout << "Surname:\t\t" << surname << std::endl;
	cout << "Address:\t\t" << address << std::endl;
	cout << "Salary:\t\t\t" << salary << std::endl;
	cout << "Cell:\t\t\t" << cell << std::endl;
	cout << "Number of worked hours:\t" << n_hours << std::endl;
	cout << "Age:\t\t\t" << age << std::endl;
	cout << "Experience:\t\t" << experience << std::endl;
	cout << endl;
}

Employee::Employee(void)
{
	salary = 0;
	n_hours = 0;
	age = 0;
	experience = 0;
	strcpy_s(address, "");
	strcpy_s(cell, "");
	strcpy_s(name, "");
	strcpy_s(surname, "");
}

Employee::Employee(char* name, char* surname, const double& salary, char* cell, char* address, const int& age)
{
	strcpy_s(Employee::name, name);
	strcpy_s(Employee::surname, surname);
	Employee::salary = salary;
	strcpy_s(Employee::cell, cell);
	strcpy_s(Employee::address, address);
	Employee::age = age;
	n_hours = 0;
	experience = 0;
}

Employee::Employee(const Employee& t)
{
	salary = t.salary;
	n_hours = t.n_hours;
	strcpy_s(address, t.address);
	strcpy_s(cell, t.cell);
	strcpy_s(name, t.name);
	strcpy_s(surname, t.surname);
	age = t.age;
	experience = t.experience;
}

Employee::~Employee(void)
{
}
