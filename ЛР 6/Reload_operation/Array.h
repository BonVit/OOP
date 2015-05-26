#pragma once

template <class T>
class Array
{
private:
	T *arr;
	int size;
public:

	int getSize()
	{
		return size;
	}

	T& operator [](int i)
	{
		return arr[i];
	}
	
	operator int()
	{
		return size;
	}

	Array& operator =(Array& a)
	{
		if(arr != NULL)
		{
			delete [] arr;
			arr = NULL;
		}
		arr = new T [a.size];
		size = a.size;
		for(int i(0); i < size; i++)
		{
			arr[i] = a.arr[i];
		}
		return *this;
	}

	Array(int n, T& data)
	{
		arr = new T [n];
		size = n;
		for(int i(0); i < size; i++)
			arr[i] = data;
	}

	Array(void)
	{
		arr = NULL;
		size = 0;
	}

	~Array(void)
	{
		if(arr != NULL)
		{
			delete [] arr;
			arr = NULL;
			size = 0;
		}
	}
};

