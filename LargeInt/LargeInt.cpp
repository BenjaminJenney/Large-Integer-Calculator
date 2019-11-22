// LargeInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "LinkedList.h"
#include <iostream>
typedef LinkedList<int>::Iterator iter;
int main()
{
	LinkedList<int> l1;
	l1.pushBack(10);
	l1.pushBack(20);
	l1.pushBack(30);

	for (auto itr = l1.end(); itr != l1.begin(); --itr)
	{
		std::cout << (*itr) << "  ";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output
//   5. Go to Project > Add New Item to create newand other messages
//   4. Use the Error List window to view errors code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
