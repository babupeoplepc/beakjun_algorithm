#pragma once
#include <iostream>
#include <list>

int sol_1158_main()
{
	int number_of_human = 0;
	int permutation_arg = 0;
	std::list<int> output;

	std::cin >> number_of_human >> permutation_arg;
	

	std::list<int> yo_list;
	
	for (int i = 0; i < number_of_human; i++)
		yo_list.push_back(i+1);	

	auto iter = yo_list.begin();
	while (1)
	{
		if (yo_list.empty())
			break;
		for (int i = 0; i < permutation_arg-1; i++)
		{
			iter++;
			if (iter == yo_list.end())
			{
				iter = yo_list.begin();				
			}
		}
		output.push_back(*iter);
		iter = yo_list.erase(iter);		
		if (iter == yo_list.end())
		{
			iter = yo_list.begin();
		}
	}

	std::cout << '<';
	for (int it : output)
	{
		number_of_human--;
		std::cout <<  it << ((number_of_human) ? ", " : ">");
	}
	
	
	

	return 0;
}