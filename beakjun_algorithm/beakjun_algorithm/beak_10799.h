#pragma once
#include <iostream>
#include <stack>

int sol_10799_main()
{
	int output = 0;
	std::stack<char> iron_stack;
	//std::string input_str = "()(((()())(())()))(())";	//	17
	//std::string input_str = "(((()(()()))(())()))(()())";		// 24
	std::string input_str;
	std::cin >> input_str;
	
	char pre_ch;
	for (char ch : input_str)
	{
		if(ch == '(')
		{
			iron_stack.push('(');
		}
		else if(ch == ')' && pre_ch == '(')
		{
			iron_stack.pop();
			output += iron_stack.size();
		}
		else if(ch == ')' && pre_ch == ')')
		{
			iron_stack.pop();
			output += 1;
		}
		pre_ch = ch;
	}
	std::cout << output << std::endl;

	return 0;
}