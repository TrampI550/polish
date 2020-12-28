#pragma once
#include "List.h"

template<class T>
class Stack
{
public:
	List<T> S;

	int Size()
	{
		return S.GetSize();
	}
	bool isEmpty()
	{
		return S.isEmpty();
	}
	T top()
	{
		return S.top();
	}
	void push(T data)
	{
		S.push_back(data);
	}
	void pop()
	{
		S.pop_back();
	}
	void Print()
	{
		S.Print();
	}
};