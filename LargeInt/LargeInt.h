#pragma once

//The implementation of the class LargeInt will use a dynamic physical structure to store the individual digits of an integer, and will provide some basic I / O and arithmetic operations that can be performed on integers.
//In particular, the class should include :
//
//	1)	A default constructor
//	2)	Operator functions to overload the operators + , -, *, / , %
//	3)	Operator functions to overload the operators == , <, <= , >, >=
//	4)	An operator function to overload the operator <<
//	5)	An operator function to overload the operator >>

#include "LinkedList.h"

//template<class T>
class LargeInt
{
private:
	LinkedList<int> number;
public:
	LargeInt();
	LargeInt(const LargeInt&) = default;
	LargeInt& operator=(const LargeInt&) = default;
	LargeInt(LargeInt&& other) noexcept;
	void print();
	LargeInt operator+(LargeInt&);
	LargeInt operator-(const LargeInt&);
	LargeInt operator*(const LargeInt&);
	LargeInt operator/(const LargeInt&);
	LargeInt operator%(const LargeInt&);
	void operator=(const std::string&);
	bool operator==(const LargeInt&);
	bool operator<(const LargeInt&);
	bool operator<=(const LargeInt&);
	bool operator>(const LargeInt&);
	bool operator>=(const LargeInt&);
	~LargeInt();
};




