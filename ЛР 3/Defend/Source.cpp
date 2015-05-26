#include <iostream>
#include <conio.h>

using namespace std;

class B;

class A
{
private:
	int price, count;
public:

	static int num_workers;
	static char name[20];
	
	friend void transfer(const A& a, B& b);

	int get_price(){return price;}
	int get_count(){return count;}
	void set_count(int a){count = a;}
	void set_price(int a){price = a;}

	static void func()
	{
		cout << name;
	}

	void show()
	{
		cout << "Price: " << price;
		cout << "\nCount: " << count;
		cout << "\nNum_workers: " << num_workers;
	}

	A(){};
	A(int a, int b, int c){price = a; count = b; num_workers = c;}
	~A(){}
};

class B
{
private:
	int price, count;
public:
	int num_workers;

	friend void transfer(const A& a, B& b);

	int get_price(){return price;}
	int get_count(){return count;}
	void set_count(int a){count = a;}
	void set_price(int a){price = a;}

	void show()
	{
		cout << "Price: " << price;
		cout << "\nCount: " << count;
		cout << "\nNum_workers: " << A::num_workers;
	}

	B(){};
	~B(){};
};

int A::num_workers;
char A::name[20];

void transfer(const A&, B&);
void trans(A&, B&);

int main()
{
	strcpy_s(A::name, "Apple");
	A::func();
	cout << endl;

	cout << "A:\n";
	A a(3, 7, 10);
	a.show();

	A::num_workers += 5;

	B b;
	trans(a, b);

	cout << endl << endl << "B:\n";
	b.show();


	_getch();
	return 0;
}

void transfer(const A& a, B& b)
{
	b.count = a.count;
	b.price = a.price;
}

void trans(A& a, B& b)
{
	b.set_count(a.get_count());
	b.set_price(a.get_price());
}