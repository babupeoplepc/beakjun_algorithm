#pragma once
#include <iostream>
#include <stack>
#include <iomanip>

int sol_1935_main()
{
	//-- 입력 ----------------------------
#if 1
	int number_of_arg = 0;
	double number[26] = { 0, };	

	std::string equation;
	std::cin >> number_of_arg;
	std::cin >> equation;

	for (int i = 0; i < number_of_arg; i++)
	{
		int num = 0;
		std::cin >> num;
		number[i] = num;
	}
#else
	//std::string equation = "ABC*+DE/-";
	//double number[5] = { 1,2,3,4,5 };
	std::string equation = "AA+A+";
	double number[20] = { 1, };
#endif

	//-- 계산 -----------------------------

	std::stack<double> equ_stack;
	double output = 0.0f;
	for (char c : equation)
	{
		if ('A' <= c && c <= 'Z')
		{
			equ_stack.push(number[c - 'A']);
		}
		else 
		{
			double arg = equ_stack.top();
			equ_stack.pop();
			double output = equ_stack.top();
			equ_stack.pop();

			switch (c)
			{
			case '+':
				output = output + arg;
				break;
			case '-':
				output = output - arg;
				break; 
			case '*':
				output = output * arg;
				break;
			case '/':
				output = output / arg;
				break;
			}
			equ_stack.push(output);
		}
	}
	std::cout << std::setprecision(2)<< std::fixed << equ_stack.top() << std::endl;
	return 0;
}