#pragma once
#include <string>
#include <iostream>

template<typename T>
class List
{
	public:
		int GetSize() { return Size; }
		List() :Size(0), head(nullptr) {}
		void pop_front()
		{
			if (head != nullptr)
			{
				Node<T>* temp = head;
				head = head->pNext;
				delete temp;
				Size--;
			}
		}
		T top()
		{
			if (head != nullptr)
			{
				Node<T>* current = head;
				while (current->pNext != nullptr)
				{
					current = current->pNext;
				}
				return current->Data;
			}
			return 0;
		}
		void push_back(T data)
		{
			if (head == nullptr)
			{
				head = new Node<T>(data);
			}
			else
			{
				Node<T>* current = this->head;
				while (current->pNext != nullptr)
				{
					current = current->pNext;
				}
				current->pNext = new Node<T>(data);
			}
			Size++;
		}
		T& operator[](const int Index)
		{
			//if (Index < Data)
			//{
			Node<T>* current = this->head;
			int counter = 0;
			while (current != nullptr)
			{
				if (counter == Index)
				{
					return current->Data;
				}
				else current = current->pNext;
				counter++;
			}
			//}
			//else return nullptr;
		}
		void turn_over()
		{
			Node<T>** msi;
			msi = new Node<T> * [Size];
			Node<T>* current = this->head;
			int counter = 0;
			for (int i = 0; i < Size; i++)
			{
				msi[i] = current;
				current = current->pNext;
			}
			for (int i = Size - 1; i > -1; i--)
			{
				std::cout << msi[i]->Data << std::endl;
			}
		}
		void Print()
		{
			Node<T>** msi;
			msi = new Node<T> * [Size];
			Node<T>* current = this->head;
			int counter = 0;
			for (int i = 0; i < Size; i++)
			{
				msi[i] = current;
				current = current->pNext;
			}
			for (int i = 0; i < Size; i++)
			{
				std::cout << msi[i]->Data << std::endl;
			}
		}
		~List()
		{
			while (Size)
			{
				pop_front();
			}
		}
		void pop_back()
		{
			//if (head == nullptr)
			//{
			//	throw exception;
			//}
			if (Size == 1)
				pop_front();
			else
			{
				Node<T>* current1 = this->head;
				Node<T>* current2 = current1;
				while (current1->pNext != nullptr)
				{
					current2 = current1;
					current1 = current1->pNext;
				}
				delete current1;
				current2->pNext = nullptr;
				Size--;
			}
		}
	    bool isEmpty()
	    {
	    	//if (head == nullptr)
			   // return 1;
	    	//else return 0;
			if (Size == 0)
				return 1;
			return 0;
    	}
    	private:
		template<typename T>
		class Node
		{
		public:
			Node* pNext;
			T Data;
			Node(T _Data = T(), Node* _pNext = nullptr) :Data(_Data), pNext(_pNext)
			{

			}
		};
		int Size;
		Node<T>* head;
};