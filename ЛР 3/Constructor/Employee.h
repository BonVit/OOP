#pragma once

#include <fstream>

using namespace std;

class Employee
{
private:
	double salary, n_hours;
	char address[30], cell[15];
public:
	char name[20], surname[20];
	int age, experience;

	static int company_days;

	friend class chief;

	double get_salary(){return salary;}
	double get_hours(){return n_hours;}

	int change_salary(const double&);
	int change_n_hours(const double&);
	int increase(const double&, const int&);
	int increase(const double&, const int&, const int&);

	void read_from_file(ifstream&);
	void write_to_file(ofstream&);

	void fill_from_keyboard();
	void show_on_console();

	Employee get_older_emp(const Employee& t){if(age > t.age) return *this; else return t;}

	friend int comp_salary(const Employee&, const Employee&);

	Employee(void);
	Employee(char*, char*, const double&, char*, char*, const int&);
    Employee(const Employee&);
	~Employee(void);
};