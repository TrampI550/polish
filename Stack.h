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
		return S.Top();
	}
	void push(T data)
	{
		S.push_back(data);
	}
	void pop()
	{
		S.pop_back();
	}
	void turn_over()
	{
		S.turn_over();
	}
};