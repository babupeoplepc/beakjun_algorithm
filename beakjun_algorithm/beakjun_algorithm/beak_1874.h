#pragma once


#include <iostream>
#include <stack>

// 문제 좟같네 진짜
// 우선 이해 안됨.

int sol_1874_main()
{
	

	std::string output_stack_seqeunce;

	std::stack<int> stack_sequence;	

	int number_of_line = 0;
	std::cin >> number_of_line;
	
	int* input_sequence = (number_of_line >1 ) ? new int[number_of_line] : new int;
	int input_index = 0;
	std::fill(input_sequence, input_sequence + number_of_line, 0x00);

	for (int i = 0; i < number_of_line; i++)
	{
		std::cin >> input_sequence[i];
	}

	int number = 0;
	while (1)
	{	
		if(stack_sequence.empty() == false)
		{
			std::cout << stack_sequence.top() << "  ::::  " << *(input_sequence + input_index) << std::endl;

			if (stack_sequence.top() == *(input_sequence+input_index))
			{
				stack_sequence.pop();
				output_stack_seqeunce += '-';
				input_index++;
				if (input_index == number_of_line) break;
			}
			else
			{
				number++;
				if (number > number_of_line) break;
				stack_sequence.push(number);
				output_stack_seqeunce += '+';
			}
			
		}
		else
		{
			number++;
			if (number > number_of_line) break;
			stack_sequence.push(number);
			output_stack_seqeunce += '+';
		}
	}
	if (stack_sequence.empty() == false) std::cout << "NO" << std::endl;
	else
	{
		for (char c : output_stack_seqeunce)
		{
			std::cout << c << std::endl;
		}
	}
		
	
	return 0;
}