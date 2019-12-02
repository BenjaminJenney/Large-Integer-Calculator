#include "pch.h"
#include "LargeInt.h"


LargeInt::LargeInt()
{
}


LargeInt::LargeInt(LargeInt&& other) noexcept : number(other.number)
{
}

void LargeInt::print()
{
	for (auto i = number.begin(); i != number.end(); i++)
	{
		std::cout << (*i);
	}
	std::cout << std::endl;
}

void LargeInt::operator=(const std::string& num)
{
	for (char c : num)
	{
		number.pushBack((int)c - '0');
	}
}

LargeInt LargeInt::operator+(LargeInt& toBeAdded)
{
	LargeInt result;

	int sum = -1111111111;
	int carry = 0;
	int num;
	int num2;

	for (auto i = number.end(), j = toBeAdded.number.end(); i != nullptr && j != nullptr; i--, j--)
	{
		sum = (*i) + (*j);
		result.number.pushFront(sum);
	}

	return result;
}

LargeInt::~LargeInt() {};