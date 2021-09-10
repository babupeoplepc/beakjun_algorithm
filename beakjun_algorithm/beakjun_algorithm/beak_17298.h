#pragma once

#include <iostream>
#include <list>
#include <stack>
#include <vector>
int sol_17298_stack_main()
{
	int number_of_element = 0;
	std::cin >> number_of_element;
	std::vector<int> number;
		
	std::string output;
	
	for (int i = 0; i < number_of_element; i++)
	{
		int num = 0;
		std::cin >> num;
		number.push_back(num);
	}	

	std::stack<int> num_stack;
	for (int idx = 0; idx < number_of_element; idx++)
	{
		
		if (num_stack.empty() || number.at(num_stack.top()) > number.at(idx))
		{
			num_stack.push(idx);
		}
		else
		{	
			while (1)
			{
				if (num_stack.empty() == true || number.at(num_stack.top()) >= number.at(idx))
				{
					num_stack.push(idx);
					break;
				}
				else
				{
					number.at(num_stack.top()) = number.at(idx);
					num_stack.pop();
				}
			}
		}
	}
	while (!num_stack.empty())
	{
		int idx = num_stack.top();
		number.at(idx) = -1;
		num_stack.pop();
	}
	for (int i : number)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}

int sol_17298_list_main()
{
	int number_of_element = 0;
	std::cin >> number_of_element;

	std::list<int> number_list;
	std::string output;
	

	for (int i = 0; i < number_of_element; i++)
	{
		int num = 0;
		std::cin >> num;
		number_list.push_back(num);
	}

	for (auto cur_num = number_list.begin(); cur_num != number_list.end(); ++cur_num)
	{
		auto temp_it = cur_num;
		
		while (1)
		{
			temp_it++;
			
			if (temp_it == number_list.end())
			{
				output += "-1 ";
				break;
			}
			
			if (*cur_num < *temp_it)
			{
				output += std::to_string(*temp_it);
				output += ' ';
				break;
			}
		}
	}
	std::cout << output << std::endl;

	return 0;

}