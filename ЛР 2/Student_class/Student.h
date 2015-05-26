#pragma once
#include <fstream>
#include <iostream>
#include <time.h>

class Student
{
private:
	char record_book[10], address[20];
	double stipend;
public:
	char faculty[20], discipline[20], name[20], surname[20];
	int age;
	int *arr, n_elem;
	
	double get_stipend(){return stipend;}
	void plus_stipend(double plus){if(stipend + plus >= 0) stipend += plus;}
	void plus_stipend(double plus, int limit_age){if(age <= limit_age && stipend + plus >= 0) stipend += plus;}
	void delete_stipend(){stipend = 0;}
	int cmp(char *s){return strcmp(surname, s);}
	int cmp(char *s1, char *s2){return (strcmp(surname, s1) != 0)? strcmp(surname, s1) :  strcmp(name, s2);}
	int cmp(int a){return a - age;}

	int random_arr();
	int sort();

	int fill_from_keyboard();
	int show_on_console();

	int read_from_file(std::ifstream&);
	int write_to_file(std::ofstream&);

	Student();
	~Student();
};
