#include <iostream>
#include <conio.h>
#include "Employee.h"

using namespace std;

#define n 5

int Employee::company_days;

class chief
{
public:
	int n_people, rank;

	void set_salary(Employee& emp, double val)
	{
		emp.salary = val;
	}

	chief():n_people(0), rank(0){}
	~chief(){}
};

int func(Employee);
int func(Employee*);

int main()
{
	Employee stat[n], *dyn = new Employee[n];


	ofstream fout("DATA.txt");
	for(int i(0); i < n; cin.ignore(), i++)
	{
		stat[i].fill_from_keyboard();
		stat[i].write_to_file(fout);
		cout << endl;
	}
	fout.close();
	cout << "\nPress any key";
	_getch();
	system("cls");

	ifstream fin("DATA.txt");
	for(int i(0); i < n; i++)
	{
		dyn[i].read_from_file(fin);
		dyn[i].show_on_console();
	}
	fin.close();
	cout << "Press any key";
	_getch();
	system("cls");
	
	if(comp_salary(dyn[0], dyn[1]) > 0)
		cout << dyn[0].name << " has a larger salary than " << dyn[1].name << ".\n";
	else
		if(comp_salary(dyn[0], dyn[1]) < 0)
			cout << dyn[1].name << " has a larger salary than " << dyn[0].name << ".\n";
		else
			cout << dyn[0].name << " and " << dyn[1].name << " has equal salary.\n";

	class chief dir;
	dir.n_people = 5;
	dir.rank = 6;
	dir.set_salary(dyn[0], 10000);
	cout << "Now " << dyn[0].name << " has " << dyn[0].get_salary() << " salary.\n";
	
	cout << "Let's check who is older - " << dyn[0].name << " or " << dyn[1].name << ".\n";
	Employee tmp = dyn[0].get_older_emp(dyn[1]);
	cout << tmp.name << " is older.\n";

	func(dyn[0]);
	dyn[0].show_on_console();
	func(&dyn[0]);
	dyn[0].show_on_console();
	
	Employee buff(dyn[0]);
	buff.show_on_console();

	
	delete [] dyn;
	_getch();
	return 0;
}

int comp_salary(const Employee& a, const Employee& b)
{
	if(a.salary > b.salary)
		return 1;
	if(a.salary < b.salary)
		return -1;
	return 0;
}

int func(Employee t)
{
	t.age += 5;
	t.experience += 5;
	t.show_on_console();
	return 0;
}

int func(Employee* t)
{
	t->age += 5;
	t->experience += 5;
	t->show_on_console();
	return 0;
}