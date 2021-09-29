#pragma once
#include <iostream>
#include <vector>
#include <stack>

int sol_17299_main()
{
	int number_of_num = 0;
	std::vector<int> num;
	
	std::cin >> number_of_num;

	int max = 0;
	for (int i = 0; i < number_of_num; i++)
	{
		int n = 0;
		std::cin >> n;

		max = (max > n) ? max : n;
		num.push_back(n);
	}

	max += 1;
	int* number_of_appearances = (max > 1) ? new int[max] : new int;
	
	std::fill(number_of_appearances, number_of_appearances + max, 0x00);
	

	for (int i : num)
	{
		number_of_appearances[i]+=1;
	}


	std::stack<int> num_stack;

	for (int idx = 0; idx < number_of_num; idx++)
	{
		if (num_stack.empty() || number_of_appearances[ num.at(num_stack.top())] >= number_of_appearances[num.at(idx)])
		{			
			num_stack.push(idx);
		}
		else
		{
			while (1)
			{
				if (num_stack.empty() || number_of_appearances[num.at(num_stack.top())] >= number_of_appearances[num.at(idx)])
				{
					
					num_stack.push(idx);
					break;
				}
				else
				{
					num.at(num_stack.top()) = num.at(idx);					
					
					num_stack.pop();
					
				}
			}
		}
	}
	while (!num_stack.empty())
	{
		int idx = num_stack.top();
		num.at(idx) = -1;
		num_stack.pop();
	}
	for (int i : num)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	if (number_of_appearances != nullptr)
		delete[] number_of_appearances;

	return 0;
}
