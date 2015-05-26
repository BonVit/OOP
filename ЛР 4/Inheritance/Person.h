#pragma once

#include <fstream>

class Person
{
private:
	char					address[20];
	int						age;
	int						id;
	double					salary;
protected:
	void					showString(char*);
public:
	char					name[20];
	char					surname[20];
	int						sex;
	char					nationality[20];

	static int				_num_workers;
	
	char*	getAddress();
	int		getAge();
	int		getId();
	double	getSalary();
	void	setAddress(char*);
	void	setAge(const int&);
	void	setId(const int&);
	void	setSalary(const int&);

	void	changeAgeSalary(const int&);
	void	changeAgeSalary(const int&, const double&);
	void	show();
	int		searchById(Person*, const int&, const int&);

	void	readFromFile(std::ifstream&);
	void	writeToFile(std::ofstream&);
	void	fillFromKeyboard();

	friend void showAddress(const Person&);
	friend class Friendly;


	Person(const int&, const int&);
	Person(	const char*,	const char*,	const int&, 
			const char*,	const char*,	const int&, 
			const int&,		const double&);
	Person(const Person&);
	Person(void);
	~Person(void);
};

