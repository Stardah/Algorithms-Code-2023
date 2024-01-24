#pragma once
#include <cstdlib>

class Calculator
{
private:
	int value;
	int argument;
	int* arr;

public:
	long add(int a, int b);

	~Calculator()
	{
		free(arr);
	}

	Calculator()
	{
		this->arr = static_cast<int*>(malloc(100));
	}

	Calculator(int value)
	{
		this->value = value;
	}
};
