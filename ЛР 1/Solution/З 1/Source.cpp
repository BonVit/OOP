#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct date
{
	int day, month, year;
	int compare(const date& a)
	{
		if(year > a.year)
			return 1;
		if(month > a.month && year == a.year)
			return 1;
		if(day > a.day && year == a.year && month == a.month)
			return 1;
		if(day == a.day && year == a.year && month == a.month)
			return 0;
		return -1;
	}
};

struct student
{
	char name[20], surname[20];
	date birthday;
	int mark[3];
};

struct person
{
	char name[20], surname[20], address[50], cell[20];
};

int RW(ofstream&, const student&);
int RD(ifstream&, student&);
int RW(ofstream&, const person&);
int RD(ifstream&, person&);
int RW(ofstream&, const vector<student>&);

int main()
{	
	int n;
	cout << "Enter number of students: ";
	cin >> n;
	student buff;

	//Typed file
	ofstream fout("INFO.DAT");
	for(int i(0); i < n; i++)
	{
		cout << "Enter name: ";
		cin.ignore();
		cin.getline(buff.name, sizeof(buff.name));
		cout << "Enter surname: ";
		cin.getline(buff.surname, sizeof(buff.surname));
		cout << "Enter day of birthday, month and year of your birthday: ";
		cin >> buff.birthday.day >> buff.birthday.month >> buff.birthday.year;
		cout << "Enter 3 marks: ";
		cin >> buff.mark[0] >> buff.mark[1] >> buff.mark[2];
		system("cls");
		RW(fout, buff);
	}
	fout.close();

	ifstream fin("INFO.DAT");
	if(fin.fail())
	{
		cerr << "Cannot open INFO.DAT" << endl;
		return -1;
	}
	date birth;
	cout << "Enter date: ";
	cin >> birth.day >> birth.month >> birth.year;
	vector<student> PTU;
	while(!RD(fin, buff))
	{	
		if(buff.birthday.compare(birth) < 0)
		{
			cout << "Name: \t\t" << buff.name << endl;
			cout << "Surname: \t" << buff.surname << endl;
			cout << "Birthday: \t" << buff.birthday.day << "." << buff.birthday.month << "." << buff.birthday.year << endl;
			cout << "Marks: " << buff.mark[0] << buff.mark[1] << buff.mark[2] << endl << endl;
		}
		for(int i(0); i < 3; i++)
			if(buff.mark[i] < 3)
			{
				PTU.push_back(buff);
				break;
			}
	}
	fin.close();

	fout.open("PTU.txt");
	RW(fout, PTU);
	fout.close();
	PTU.~vector();

	cout << "\n\t\tStudents that are transfered to PTU:\n";
	fin.open("PTU.txt");
	student temp;
	char brush[2];
	while(!fin.eof())
	{
		fin.getline(temp.name, sizeof(temp.name));
		fin.getline(temp.surname, sizeof(temp.surname));
		fin >> temp.birthday.day >> temp.birthday.month >> temp.birthday.year;
		fin.getline(brush, sizeof(brush));
		for(int i(0); i < 3; i++)
			fin >> temp.mark[i];
		fin.getline(brush,sizeof(brush));
		
		cout << "Name: " << temp.name << endl;
		cout << "Surname: " << temp.surname << endl;
		cout << "Birthday: " << temp.birthday.day << "." << temp.birthday.month << "." << temp.birthday.year << endl;
		cout << "Marks: ";
		for(int i(0); i < 3; i++)
			cout << temp.mark[i] << " ";
		cout << endl;
	}
	fin.close();

	cout << "Press any key" << endl;
	cin.ignore();
	cin.get();
	system("cls");

	cout << "Enter number of students: ";
	cin >> n;
	person tmp;

	//Text file
	fout.open("INFO.txt");
	cin.ignore();
	for(int i(0); i < n; i++)
	{
		cout << "Enter name: ";
		cin.getline(tmp.name, sizeof(tmp.name));
		cout << "Enter surname: ";
		cin.getline(tmp.surname, sizeof(tmp.surname));
		cout << "Enter address: ";
		cin >> tmp.address;
		cout << "Enter cell number: ";
		cin.ignore();
		cin.getline(tmp.cell, sizeof(tmp.cell));
		system("cls");
		RW(fout, tmp);
	}
	fout.close();

	fin.open("INFO.txt");
	if(fin.fail())
	{
		cerr << "Cannot open INFO.txt" << endl;
		return -1;
	}
	vector<person> persons;
	while(!RD(fin, tmp))
	{
		persons.push_back(tmp);
	}
	fin.close();
	for(int i(0); i < persons.size(); i++)
		for(int j(0); j < persons.size() - i - 1; j++)
			if(strcmp(persons[j].address, persons[j + 1].address) > 0)
				swap(persons[j], persons[j + 1]);
	for(int i(0); i < persons.size(); i++)
	{
		cout << "Surname: \t" << persons[i].surname << endl;
		cout << "Address: \t" << persons[i].address << endl;
	}
	persons.~vector();

	cout << "Press any key";
	cin.get();
	return 0;
}

int RW(ofstream& fout, const student& buff)
{
	fout.write((char *) &buff, sizeof(buff));
	return 0;
}

int RD(ifstream& fin, student& buff)
{
	fin.read((char *) &buff, sizeof(buff));
	return fin.eof();
}

int RW(ofstream& fout, const person& buff)
{
	fout << buff.name << endl;
	fout << buff.surname << endl;
	fout << buff.address << endl;
	fout << buff.cell << endl;
	return 0;
}

int RD(ifstream& fin, person& buff)
{
	fin.getline(buff.name, sizeof(buff.name));
	fin.getline(buff.surname, sizeof(buff.surname));
	fin.getline(buff.address, sizeof(buff.address));
	fin.getline(buff.cell, sizeof(buff.cell));
	return fin.eof();
}

int RW(ofstream &fout, const vector<student> &a)
{
	for(int i(0); i < a.size(); i++)
	{
		fout << a[i].name << endl;
		fout << a[i].surname << endl;
		fout << a[i].birthday.day << endl;
		fout << a[i].birthday.month << endl;
		fout << a[i].birthday.year << endl;
		for(int j(0); j < 3; j++)
			fout << a[i].mark[j] << " ";
		if(i != a.size() - 1)
			fout << endl;
	}
	return 0;
}
