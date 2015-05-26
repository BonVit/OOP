#include <iostream>
#include <forward_list>
#include <functional>
#include <list>
#include <set>
#include <queue>

using namespace std;

struct asoc
{
	int data;
	int key;
};

//int search(forward_list<int>, int);
template<typename T>
int search(forward_list<T>, T);
void insertSort(list<int>&);
template<typename T>
set<T> operator+(set<T>, set<T>);
set<int> operator*(set<int>, set<int>);
bool operator==(set<int>, set<int>);
set<int> operator-(set<int>, set<int>);
set<int> operator~(set<int>);
void add(list<asoc>&, asoc);
void add(queue<asoc>&, asoc);

void main()
{
	//FIRST TASK
	cout << "\t\t\tFIRST TASK\n";
	forward_list<int> f_list;
	forward_list<int>::iterator f_iter;
	f_list.push_front(5);
	f_list.push_front(7);
	f_list.push_front(4);
	f_list.sort(greater<int>());
	for(f_iter = f_list.begin(); f_iter != f_list.end(); f_iter++)
		cout << *f_iter << " ";
	cout << endl;
	int index = search(f_list, 5);
	cout << "Index: " << index << endl;
	

	//SECOND TASK
	cout << "\n\t\t\tSECOND TASK\n";
	list<int> d_list;
	list<int>::iterator d_iter;
	d_list.push_back(5);
	d_list.push_back(7);
	d_list.push_back(4);
	for(d_iter = d_list.begin(); d_iter != d_list.end(); d_iter++)
		cout << *d_iter << " ";
	cout << endl;
	insertSort(d_list);
	for(d_iter = d_list.begin(); d_iter != d_list.end(); d_iter++)
		cout << *d_iter << " ";
	cout << endl;

	//THIRD TASK
	cout << "\t\t\tTHIRD TASK\n";
	set<int> set1;
	set<int> set2;
	set<int> tmp;
	set<int>::iterator s_iter;
	set1.insert(5);
	set1.insert(7);
	set1.insert(4);
	set2.insert(4);
	set2.insert(3);
	cout << "Set1: ";
	for(s_iter = set1.begin(); s_iter != set1.end(); s_iter++)
		cout << *s_iter << " ";
	cout << "\nSet2: ";
	for(s_iter = set2.begin(); s_iter != set2.end(); s_iter++)
		cout << *s_iter << " ";
	cout << "\nSet1 + Set2: ";
	tmp = set1 + set2;
	for(s_iter = tmp.begin(); s_iter != tmp.end(); s_iter++)
		cout << *s_iter << " ";
	cout << "\nSet1 * Set2: ";
	tmp = set1 * set2;
	for(s_iter = tmp.begin(); s_iter != tmp.end(); s_iter++)
		cout << *s_iter << " ";
	cout << "\nSet1 == Set2: " << (set1 == set2);
	cout << "\nSet1 - Set2: ";
	tmp = set1 - set2;
	for(s_iter = tmp.begin(); s_iter != tmp.end(); s_iter++)
		cout << *s_iter << " ";
	cout << "\n~Set1: ";
	tmp = ~set1;
	for(s_iter = tmp.begin(); s_iter != tmp.end(); s_iter++)
		cout << *s_iter << " ";

	cout << "\n\t\t\tFOURTH TASK\n";
	list<asoc> a_list;
	list<asoc>::iterator a_iter;
	queue<asoc> q;
	asoc temp[3];
	temp[0].key = 1;
	temp[1].key = 3;
	temp[2].key = 1;
	for(int i(0); i < 3; i++)
	{
		temp[i].data = i * 3 + 1;
		add(a_list, temp[i]);
		add(q, temp[i]);
	}
	cout << "Asoc list(data | key):\n";
	for(a_iter = a_list.begin(); a_iter != a_list.end(); a_iter++)
		cout << (*a_iter).data << " | " << (*a_iter).key << endl;
	cout << "Asoc queue(data | key):\n";
	while(!q.empty())
	{
		cout << q.front().data << " | " << q.front().key << endl;
		q.pop();
	}
	
	system("pause");
}

template<typename T>
int search(forward_list<T> f_list, T element)
{
	if(f_list.empty())
		return -1;
	int size = 0;
	forward_list<T>::iterator f_iter;
	for(f_iter = f_list.begin(); f_iter != f_list.end(); f_iter++)
		size++;
	int l = 0, r = size - 1;
	int mid;
	for(;;)
	{
		mid = (l + r) / 2;
		f_iter = f_list.begin();
		for(int i(0); i < mid; i++)
			f_iter++;
		if(*f_iter == element)
			return mid;
		if(l == r)
			return -1;
		if(element < *f_iter)
			l = mid + (l + r) % 2;
		else
			r = mid;
	}
	return -1;
}

void insertSort(list<int>& d_list)
{
	int n = d_list.size();
	int *tmp = new int[n];
	for(int i(0); i < n; i++)
	{
		tmp[i] = d_list.front(); 
		d_list.pop_front();
	}

    for(int i(1); i < n; i++)     
		for(int j(i); j > 0 && tmp[j - 1] > tmp[j]; j--) 
            swap(tmp[j - 1], tmp[j]);

	for(int i(0); i < n; i++)
		d_list.push_back(tmp[i]);

	delete [] tmp;
}

template<typename T>
set<T> operator+(set<T> set1, set<T> set2)
{
	set<T>::iterator iter;
	set<T> result;
	for(iter = set1.begin(); iter != set1.end(); iter++)
		result.insert(*iter);
	for(iter = set2.begin(); iter != set2.end(); iter++)
		result.insert(*iter);
	return result;
}

set<int> operator*(set<int> set1, set<int> set2)
{
	set<int> result;
	set<int>::iterator iter;
	for(iter = set1.begin(); iter != set1.end(); iter++)
		if(set2.find(*iter) != set2.end())
			result.insert(*iter);
	return result;
}

bool operator==(set<int> set1, set<int> set2)
{
	if(set1.size() != set2.size())
		return false;
	set<int>::iterator iter1, iter2;
	for(iter1 = set1.begin(), iter2 = set2.begin(); iter1 != set1.end() && iter2 != set2.end(); iter1++, iter2++)
		if(*iter1 != *iter2)
			return false;
	return true;
}

set<int> operator-(set<int> set1, set<int> set2)
{
	set<int> result;
	set<int>::iterator iter;
	for(iter = set1.begin(); iter != set1.end(); iter++)
		if(set2.find(*iter) == set2.end())
			result.insert(*iter);

	return result;
}

set<int> operator~(set<int> set1)
{
	set<int> result;
	set<int>::iterator iter;

	for(iter = set1.begin(); iter != set1.end(); iter++)
		result.insert(~(*iter));

	return result;
}

void add(list<asoc>& l, asoc d)
{
	list<asoc>::iterator iter;
	for(iter = l.begin(); iter != l.end(); iter++)
		if((*iter).key == d.key)
			return;
	l.push_back(d);
}

void add(queue<asoc>& q, asoc d)
{
	queue<asoc> tmp;
	bool flag = true;
	while(!q.empty())
	{
		if(q.front().key == d.key)
			flag = false;
		tmp.push(q.front());
		q.pop();
	}

	while(!tmp.empty())
	{
		q.push(tmp.front());
		tmp.pop();
	}
	if(flag)
		q.push(d);
}