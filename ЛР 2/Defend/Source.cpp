#include <iostream>
#include "CLASS.h"

using namespace std;

int main()
{
	CLASS stat(10, 23, 43.15);
	CLASS *dyn = new CLASS;

	cout << "\t\t\tFirst object:\n";
	cout << "a = " << stat.get_a() << endl;
	cout << "b = " << stat.get_b() << endl;
	cout << "c = " << stat.get_c() << endl;
	stat.fill_from_keyboard();
	cout << "a = " << stat.get_a() << endl;
	cout << "b = " << stat.get_b() << endl;
	cout << "c = " << stat.get_c() << endl;
	cout << "\n\t\t\tSecond object:\n";
	cout << "a = " << dyn->get_a() << endl;
	cout << "b = " << dyn->get_b() << endl;
	cout << "c = " << dyn->get_c() << endl;
	cout << "Change charachteristics to 5, 3, 0.34:\n";
	dyn->change(5, 3, 0.34);
	cout << "a = " << dyn->get_a() << endl;
	cout << "b = " << dyn->get_b() << endl;
	cout << "c = " << dyn->get_c() << endl;

	delete dyn;
	cin.ignore();
	cin.get();
	return 0;
}