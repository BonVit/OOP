#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

#define MAX_SIZE 10
#define MAX_ELEMENT 99

void gener(vector<int>&);
void show(vector<int>&);

void downHeap(vector<int>&, int, int);
void heapSort(vector<int>&);

void main()
{
	srand(time(NULL));

	vector<int> vec;
	gener(vec);
	show(vec);
	heapSort(vec);
	show(vec);


	system("pause");
}

void gener(vector<int>& a)
{
	a.clear();
	int n = rand() % MAX_SIZE + 1;
	for(int i(0); i < n; i++)
		a.push_back(rand() % MAX_ELEMENT + 1);
}

void show(vector<int>& a)
{
	for(auto data : a)
		cout << data << " ";
	cout << endl;
}

void downHeap(vector<int>& vec, int k, int n)
{
    int new_elem;
    int child;
    new_elem = vec[k];
    
	while(k <= n / 2)
    {       
		child = 2*k;
        
		if( child < n && vec[child] < vec[child + 1])
            child++;
		if( new_elem >= vec[child] ) 
            break; 
        vec[k] = vec[child];
        k = child;
    }
	vec[k] = new_elem;
}
 
void heapSort(vector<int>& vec)
{ 
	/*int size = vec.size();
	int *a = new int[size];
	for(int i(0); i < vec.size(); i++)
		a[i] = vec[i];*/

    for(int i(vec.size() / 2 - 1); i >= 0; --i) 
		downHeap(vec, i, vec.size() - 1);

	for(int i(vec.size() - 1); i > 0; --i) 
    {
		swap(vec[0], vec[i]);
		downHeap(vec, 0, i - 1); 
    }

	/*for(int i(0); i < vec.size(); i++)
		vec[i] = a[i];*/
}