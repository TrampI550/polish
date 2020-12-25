#pragma once
#include "iostream"
using namespace std;
const int MAX = 25;
template <class T>
class Stack
{
public:

Stack(double size=0)
	{
		size = MAX;
		arr = new T[size];
		Top = 0;
	}

~Stack()
	{
		if (Top == -1)
		{
			throw underflow_error("Empty");
		}
		else
		{
			delete[] arr;
		}
	}

	void push(T a)
	{
		if (Top == (size - 1))
		{
			throw overflow_error("Stack is full");
		}
		else
		{
			Top++;
			arr[Top] = a;
		}
	}

	bool isEmpty()
	{
		return(Top == 0);
	}

	bool isFull()
	{
		return(Top = size - 1);
	}

	void pop()
	{
			Top--;
			int var = arr[Top];
	}

	T top()
	{
		if (Top == -1)
		{
			return 0;
		}
		else
		{
			int var = arr[Top];
			return var;
		}
	}

	void Print()
	{
		for (int i = 1; i <= Top; i++)
		{
			cout << arr[i];
		}
	}
private:
	T* arr;
	int Top;
	int size;
};