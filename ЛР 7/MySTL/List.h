#pragma once

template<typename T>
struct node
{
public:
	T data;
	node<T>* next;
};

template<typename T>
class List
{
private:
	node<T>* head;
	node<T>* tail;
	node<T>* iter;
	int size;
public:

	node<T>* getHead()
	{
		return head;
	}

	node<T>* getTail()
	{
		return tail;
	}

	node<T>* getIter()
	{
		return iter;
	}

	int getSize()
	{
		return size;
	}

	void setIter(node<T>* i)
	{
		iter = i;
	}

	void operator++()
	{
		if(iter != NULL)
			iter = iter->next;
	}

	node<T>* search(T element)
	{
		if(size == 0)
			return NULL;
		int l = 0, r = size - 1;
		int mid;
		node<T>* tmp;
		for(;;)
		{
			mid = (l + r) / 2;
			tmp = head;
			for(int i(0); i < mid; i++)
				tmp = tmp->next;

			if(tmp->data == element)
				return tmp;
			if(element < tmp->data)
			{
				l = mid;
				r = size;
			}
			else
			{
				l = 0;
				r = mid;
			}
			if(l == r)
				return NULL;
		}
		
		return NULL;
	}

	void addElement(T element)
	{
		if(head == NULL)
		{
			head = new node<T>;
			head->data = element;
			head->next = NULL;
			tail = head;
			size++;
			return;
		}
		node<T>* tmp = head;
		//To begin
		if(element > tmp->data)
		{
			tmp = new node<T>;
			tmp->next = head;
			tmp->data = element;
			head = tmp;
			size++;
			return;
		}

		//Insert
		node<T>* prevTmp = tmp;
		tmp = tmp->next;
		while(tmp != NULL)
		{
			if(element > tmp->data)
			{
				prevTmp->next = new node<T>;
				prevTmp->next->next = tmp;
				prevTmp->next->data = element;
				size++;
				return;
			}
			prevTmp = tmp;
			tmp = tmp->next;
		}

		//To end
		tail->next = new node<T>;
		tail = tail->next;
		tail->next = NULL;
		tail->data = element;
		size++;
	}



	void clear()
	{
		node<T>* tmp;
		while(head != NULL)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	List(void)
	{
		head = NULL;
		tail = NULL;
		iter = NULL;
		size = 0;
	}
	~List(void)
	{
		clear();
	}
};

