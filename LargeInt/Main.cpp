// LargeInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "LinkedList.h"
#include "LargeInt.h"
#include <iostream>
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	/*LinkedList<int> l1;
	
	std::cout << "enter a number" << std::endl;

	std::string hotpotato = "";

	std::cin >> hotpotato;

	for (int i = 0; i < hotpotato.length(); i++)
	{
		l1.pushBack(hotpotato[i] - '0');
	}

	for (auto itr = l1.begin(); itr != l1.end(); itr++)
	{
		std::cout << (*itr) << " ";
	}*/

	LargeInt num;
	num = "12345";
	LargeInt num2;
	num2 = "11111";
	LargeInt sum;
	sum = num + num2;

	std::cout << "sum: ";
	sum.print();
}
