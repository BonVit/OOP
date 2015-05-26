#include "Student.h"

Student::Student(void)
{
	arr = NULL;
}

Student::~Student(void)
{
	if(arr != NULL)
		delete [] arr;
}

int Student::fill_from_keyboard()
{
	std::cout << "Enter name: ";
	std::cin.getline(name, sizeof(name));
	std::cout << "Enter surname: ";
	std::cin.getline(surname, sizeof(surname));
	std::cout << "Enter faculty: ";
	std::cin.getline(faculty, sizeof(faculty));
	std::cout << "Enter discipline: ";
	std::cin.getline(discipline, sizeof(discipline));
	std::cout << "Enter address: ";
	std::cin.getline(address, sizeof(address));
	std::cout << "Enter number of record book: ";
	std::cin.getline(record_book, sizeof(record_book));
	std::cout << "Enter age: ";
	std::cin >> age;
	std::cout << "Enter stipend: ";
	std::cin >> stipend;
	return 0;
}

int Student::show_on_console()
{
	std::cout << "Name:\t\t\t" << name << std::endl;
	std::cout << "Surname:\t\t" << surname << std::endl;
	std::cout << "Faculty:\t\t" << faculty << std::endl;
	std::cout << "Discipline:\t\t" << discipline << std::endl;
	std::cout << "Address:\t\t" << address << std::endl;
	std::cout << "Number of record book:\t" << record_book << std::endl;
	std::cout << "Age:\t\t\t" << age << std::endl;
	std::cout << "Stipend:\t\t" << stipend << std::endl;
	return 0;
}

int Student::read_from_file(std::ifstream& fin)
{
	fin.getline(name, sizeof(name));
	fin.getline(surname, sizeof(surname));
	fin.getline(faculty, sizeof(faculty));
	fin.getline(discipline, sizeof(discipline));
	fin >> age >> stipend;
	fin.getline(record_book, sizeof(record_book));
	fin.getline(record_book, sizeof(record_book));
	fin.getline(address, sizeof(address));
	return 0;
}

int Student::write_to_file(std::ofstream& fout)
{
	static bool flag = 0;
	if(flag)
		fout << std::endl;
	else
		flag = 1;
	fout << name << std::endl << surname << std::endl;
	fout << faculty << std::endl << discipline << std::endl;
	fout << age << std::endl << stipend << std::endl;
	fout << record_book << std::endl << address;
	return 0;
}

int Student::random_arr()
{
	srand(time(NULL));
	n_elem = rand()%100;
	if(arr != NULL)
		delete [] arr;
	arr = new int [n_elem];
	for(int i(0); i < n_elem; i++)
		arr[i] = rand() % 101 - 50;
	return 0;
}

int Student::sort()
{
	for(int i(0); i < n_elem; i++)
		for(int j(0); j < n_elem - i - 1; j++)
			if(arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
	return 0;
}