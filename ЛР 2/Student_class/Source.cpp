#include <iostream>
#include "Student.h"

using namespace std;

#define n 5

int main()
{
	ofstream fout("data.txt");
	Student a[n];
	for(int i(0); i < n; system("cls"), cin.ignore(), i++)
	{
		a[i].fill_from_keyboard();
		a[i].write_to_file(fout);
	}
	fout.close();

	ifstream fin("data.txt");
	Student *b = new Student[n];
	for(int i(0); i < n; i++)
		b[i].read_from_file(fin);
	for(int i(0); i < n; cout << endl, i++)
		b[i].show_on_console();
	fin.close();
	cin.get();
	system("cls");

	cout << "\t\tSearch by surname\n";
	cout << "Enter surname: ";
	char t[20];
	cin.getline(t, sizeof(t));
	for(int i(0), l(0); i < n; i++)
	{
		if(!b[i].cmp(t))
		{
			b[i].show_on_console();
			cout << endl;
			l = 1;
		}
		if(l == 0 && i == n - 1)
			cout << "Nothing found!\n";
	}
	cout << "Array: " << endl;
	Student *tmp = new Student;
	tmp->random_arr();
	for(int i(0); i < tmp->n_elem; i++)
		cout << tmp->arr[i] << " ";
	tmp->sort();
	cout << "\nSorted array:\n";
	for(int i(0); i < tmp->n_elem; i++)
		cout << tmp->arr[i] << " ";

	cout << "\nLets check stipend of 1st student\n";
	cout << "Stipend: " << b[0].get_stipend() << endl;
	cout << "Lets increase stipend on 55 hryvnas\n";
	b[0].plus_stipend(55);
	cout << "Stipend: " << b[0].get_stipend() << endl;
	cout << "Lets increase stipend on 105 hryvnas if student's age is less than 24\n";
	b[0].plus_stipend(105, 23);
	cout << "Stipend: " << b[0].get_stipend() << endl;

	delete tmp;
	for(int i(0); i < n; i++)
		b[i].~Student();
	delete [] b;
	cin.get();
	return 0;
}