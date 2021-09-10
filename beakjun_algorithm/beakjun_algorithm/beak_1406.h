#pragma once
#include <iostream>
#include <list>


void print_list(std::list<char> string_list)
{
	for (char c : string_list)
	{
		std::cout << c;
	}
	std::cout << std::endl;



}

int sol_1406_main()
{
	int number_of_line = 0;
	std::string input_string;
	std::cin >> input_string >> number_of_line;


	std::list<char> data_list(input_string.begin(), input_string.end());
	auto cursor = data_list.end();


	for (int i = 0; i < number_of_line; i++)
	{
		char command = 0;
		std::cin >> command;

		switch (command)
		{
		case 'L':
			if (cursor != data_list.begin()) cursor--;
			break;
		case 'D':
			if (cursor != data_list.end()) cursor++;
			break;
		case 'B':
			if (cursor != data_list.begin())
			{
				cursor--;
				cursor = data_list.erase(cursor);

			}
			//print_list(data_list);
			break;
		case 'P':
			char c;
			std::cin >> c;
			data_list.insert(cursor, c);
			//print_list(data_list);
			break;
		default:
			break;

		}
	}
	print_list(data_list);




	return 0;
}