// FirstCppApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstdint>

#include "Calculator.h"

//using namespace std;

int main()
{
	int int_value = INT32_MAX;

	int* a = &int_value;
	int* int_prt = &int_value;

	char char_value = 'b';
	char* char_ptr = &char_value;

	float float_value = 1.3f;
	int_value = static_cast<int>(float_value);


	std::string str = "awdwqdwqd";
	std::vector<int> vector;

	char_value = static_cast<char>(int_value);
	char_ptr = reinterpret_cast<char*>(int_prt);

	if (char_ptr != nullptr)
	{
		std::cout << char_ptr << std::endl;
	}
	else
	{
		std::cout << "nullptr" << std::endl;
	}

	Calculator calc;

	std::cout << calc.add(10, 20);

	//delete calc;

	//if (calc == nullptr)
	//{
	//	std::cout << "nullptr" << std::endl;
	//}


	//const int& bindA = 10;

	//int int_value = 10;
	//float float_value = 10;

	//int_value = float_value;


	//bindA++;
	//bindA = *b;

	//ABC::Calculator;

	//std::cout << bindA << "hii" << "wdawd" << std::endl;
	//std::cin >> int_value;

	//std::cout << "Hello World!\n";
}
