#include "Person.h"
#include <cstring>
#include <iostream>

using namespace std;

void showString(char* str)
{
	cout << str;
}

char* Person::getAddress()
{
	return address;
}

int	Person::getAge()
{
	return age;
}

int	Person::getId()
{
	return id;
}

double Person::getSalary()
{
	return salary;
}

void Person::setAddress(char *address)
{
	strcpy_s(Person::address, address);
}

void Person::setAge(const int& age)
{
	Person::age = age;
}

void Person::setId(const int& id)
{
	Person::id = id;
}

void Person::setSalary(const int& salary)
{
	Person::salary = salary;
}

void Person::changeAgeSalary(const int& age)
{
	Person::age = age;
}

void Person::changeAgeSalary(const int& age, const double& salary)
{
	Person::age = age;
	Person::salary = salary;
}

void Person::show()
{
	cout << "Name:\t\t" << name << endl;
	cout << "Surname:\t" << surname << endl;
	cout << "Age:\t\t" << age << endl;
	cout << "Nationality:\t" << nationality << endl;
	cout << "Sex:\t\t" << ((sex) ? "Male" : "Female") << endl;
	cout << "Address:\t" << address << endl;
	cout << "Salary:\t\t" << salary << endl;
	cout << "Id:\t\t" << id << endl;
}

int Person::searchById(Person *arr, const int& num_elem, const int& id)
{
	for(int i(0); i < num_elem; i++)
		if(arr->id == id)
			return i;
	return -1;
}

void Person::readFromFile(ifstream& fin)
{
	fin.getline(name, sizeof(name));
	fin.getline(surname, sizeof(surname));
	fin >> sex;
	fin.getline(nationality, sizeof(nationality));
	fin.getline(nationality, sizeof(nationality));
	fin >> age;
	fin.getline(address, sizeof(address));
	fin.getline(address, sizeof(address));
	fin >> id >> salary;
}

void Person::writeToFile(ofstream& fout)
{
	static bool flag = 0;
	if(flag)
		fout << std::endl;
	else
		flag = 1;
	fout << name << endl << surname << endl;
	fout << sex << endl << nationality << endl;
	fout << age << endl << address << endl;
	fout << id << std::endl << salary;
}

void Person::fillFromKeyboard()
{
	cout << "Enter name: ";
	cin.getline(name, sizeof(name));
	cout << "Enter surname: ";
	cin.getline(surname, sizeof(surname));
	cout << "Enter sex (1 - male, 0 - female): ";
	cin >> sex;
	cout << "Enter nationality: ";
	cin.ignore();
	cin.getline(nationality, sizeof(nationality));
	cout << "Enter age: ";
	cin >> age;
	cout << "Enter address: ";
	cin.ignore();
	cin.getline(address, sizeof(address));
	cout << "Enter id: ";
	cin >> id;
	cout << "Enter salary: ";
	cin >> salary;
	cin.ignore();
}

Person::Person(const int& age, const int& salary)
{
	strcpy_s(name, "");
	strcpy_s(surname, "");
	sex = 0;
	strcpy_s(nationality, "");
	strcpy_s(address,"");
	Person::age = age;
	id = 0;
	Person::salary = salary;
	_num_workers++;
}

Person::Person(const char* name,	const char* surname,
			   const int& sex,		const char* nationality, 
			   const char* address, const int& age, 
			   const int& id,		const double& salary)
{
	strcpy_s(Person::name, name);
	strcpy_s(Person::surname, surname);
	Person::sex = sex;
	strcpy_s(Person::nationality, nationality);
	strcpy_s(Person::address, address);
	Person::age = age;
	Person::id = id;
	Person::salary = salary;
	_num_workers++;
}

Person::Person(const Person& tmp): id(tmp.id)
{
	strcpy_s(name, tmp.name);
	strcpy_s(surname, tmp.surname);
	sex = tmp.sex;
	strcpy_s(nationality, tmp.nationality);
	strcpy_s(address, tmp.address);
	age = tmp.age;
	salary = tmp.salary;
	_num_workers++;
}

Person::Person(void)
{
	strcpy_s(name, "");
	strcpy_s(surname, "");
	sex = 0;
	strcpy_s(nationality, "");
	strcpy_s(address,"");
	age = 0;
	id = 0;
	salary = 0;
	_num_workers++;
}


Person::~Person(void)
{
	_num_workers--;
}
