#pragma once
#include "pch.h"
#include <iostream>
#include <algorithm>


template <class T>
struct node
{
	T data;
	node<T> * next;
	node<T> * prev;
	node() {
		next = nullptr;
		prev = nullptr;
	};
	node(T data, node<T> * next = nullptr, node<T> * prev = nullptr) 
		: data(data), next(next), prev(prev) {};
};

template <class T>
class LinkedList
{
private:
	node<T> * first;
	node<T> * tail;
	int size = 0;
public:
	LinkedList();
	LinkedList(const LinkedList&);
	void copy(const LinkedList&);
	//void operator=(const LinkedList&);
	//void insert_end(T dat);
	void pushBack(T data);
	void pushFront(T data);
	void display();
	void displayRev();
	int getSize();
	class Iterator
	{
	private:
		node<T> * itr;
		node<T> *end;
	public:
		
		Iterator(node<T> * itr = nullptr) : itr(itr) {};
		
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);

		T operator*();

		bool operator!=(LinkedList<T>::Iterator other);
		bool operator==(LinkedList<T>::Iterator & other);

		~Iterator() {}
	};
	Iterator begin() { return Iterator(first); }
	Iterator end() { return Iterator(tail); }
	~LinkedList();
};

template<class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++()
{
	itr = itr->next;
	return *this;
}

template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int a)
{
	auto tmp = *this;
	itr = itr->next;
	return tmp;
}

template<class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--()
{
	itr = itr->prev;
	return *this;
}

template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(int)
{
	auto tmp = *this;
	itr = itr->prev;
	return tmp;
}

template<class T>
T LinkedList<T>::Iterator::operator*()
{
	if (itr != nullptr)
		return itr->data;
}

template<class T>
bool LinkedList<T>::Iterator::operator!=(LinkedList<T>::Iterator other)
{
	return itr != other.itr;
}

template<class T>
bool LinkedList<T>::Iterator::operator==(LinkedList<T>::Iterator & other)
{
	return itr == other.itr;
}

template <class T>
LinkedList<T>::LinkedList()
{
	first = nullptr;
	tail = nullptr;
	size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& other)
{

	if (other.first == nullptr)
	{
		first = nullptr;
		tail = first;
	}
	else
	{
		copy(other);
	}
}

//template<class T>
//void LinkedList<T>::operator=(const LinkedList& other)
//{
//		node<T> *thisPtr = first;
//
//		while (thisPtr != nullptr)
//		{
//			node<T> *Tmp = thisPtr;
//			thisPtr = thisPtr->next;
//			delete Tmp;
//
//		}
//
//		copy(other);
//}

template<class T>
void LinkedList<T>::copy(const LinkedList& other)
{
	
		first = new node<T>(other.first->data, other.first->next);
		node<T> *copyNode = first->next;
		node<T> *thisNode = first;
		size = other.size;
		while (copyNode != nullptr)
		{
			thisNode->next = new node<T>(copyNode->data, copyNode->next, thisNode);
			thisNode = thisNode->next;
			copyNode = copyNode->next;
		}
		tail = thisNode;
		tail->next = nullptr;
}

template<class T>
void LinkedList<T>::pushBack(T data)
{

	if (first == nullptr)
	{
		first = new node<T>(data);
		tail = nullptr;
		size++;
	}
	else
	{
		if (tail == nullptr)
		{
			tail = new node<T>(data);
			first->next = tail;
			tail->prev = first;
			size++;
		}
		else
		{
			node<T> *prevTail = tail;
			node<T> *newTail = new node<T>(data, nullptr, prevTail);
			prevTail->next = newTail;
			tail = newTail;
			size++;
		}
	}
	
}

template<class T>
void LinkedList<T>::pushFront(T data)
{
	if (first == nullptr)
	{
		first = new node<T>(data);
		tail = nullptr;
		size++;
	}
	else
	{
		if (tail == nullptr)
		{
			first->prev = new node<T>(data);
			tail = first;
			first = first->prev;
			first->next = tail;
			size++;
		}
		else
		{
			node<T> *prevFirst = first;
			node<T> *newFirst = new node<T>(data, prevFirst);
			prevFirst->prev = newFirst;
			first = newFirst;
			size++;
		}
	}
}

template<class T>
void LinkedList<T>::display()
{
	if (first == nullptr)
	{
		std::cout << "nothing to display" << std::endl;
	}
	else
	{
		node<T> *ptr = first;
		while (ptr != nullptr)
		{
			std::cout << ptr->data << "  ";
			ptr = ptr->next;
		}
	}
}

template<class T>
void LinkedList<T>::displayRev()
{
	if (tail == nullptr)
	{
		std::cout << "nothing to display" << std::endl;
	}
	else
	{
		node<T> *ptr = tail;
		while (ptr != nullptr)
		{
			std::cout << ptr->data << "  ";
			ptr = ptr->prev;
		}
		
	}
}

template <class T>
int LinkedList<T>::getSize()
{
	return size;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	node<T> *ptr = first;
	while (ptr != nullptr)
	{
		node<T> * garbage = ptr;
		ptr = ptr->next;

		delete garbage;
	}
}
