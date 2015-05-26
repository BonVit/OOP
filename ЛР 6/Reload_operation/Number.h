#pragma once
class Number
{
private:
	int data;
public:

	void setData(int);
	int getData();

	Number operator --(int);
	friend Number operator ++(Number&, int);

	Number(void);
	~Number(void);
};

