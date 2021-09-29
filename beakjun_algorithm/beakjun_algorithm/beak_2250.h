#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

#define abs_value(a) (a < 0) ? a*-1 : a

struct node_2250
{
	short parent;
	short left;
	short right;
	short row_number;
	short level;
	node_2250() : parent(-1), left(-1), right(-1) {}
};

std::vector<node_2250> vec_2250(10001);
int max_value(int a, int b) { return (a > b) ? a : b; }
int cal_max_width(std::vector<int>& vec)
{
	if (vec.size() == 1) return 1;
	int max = 1;
	
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i+1; j < vec.size(); j++)
		{			
			int cal = (vec[i] - vec[j]);
			cal = abs_value(cal);
			cal += 1;
			max = max_value(max, cal);
		}
	}
	return max;
}

int inOrder_counting(int node)
{
	static int column_conter = 0;
	static int level_counter = 0;
	static int max_level = 0;
	level_counter++;

	if (node == -1)
	{
		level_counter--;
		max_level = max_value(max_level, level_counter);
		return max_level;
	}
	inOrder_counting(vec_2250[node].left);
	vec_2250[node].row_number = ++column_conter;
	vec_2250[node].level = level_counter;
	inOrder_counting(vec_2250[node].right);
	level_counter--;
	return max_level;
}



int sol_2250_main()
{

	/*int number;
	int max_number = 0;
	std::cin >> number;
	if(number < 3) {std::cout << "1 1" << std::endl; return 0;}
	char rt, l, r;
	for (int i = 0; i < number; i++)
	{
		std::cin >> rt >> l >> r;
		vec[rt].left = l;
		if(l != -1) vec[l].parent = rt;
		vec[rt].right = r;
		if (r != -1) vec[r].parent = rt;
		max_number = max_value(max_number, max_value(rt, (max_value(r, l))));
	}*/

	std::ifstream fin;
	fin.open("beak_2250.txt");
	int number;
	int max_number = 0;
	fin >> number;
	while (!fin.eof())
	{
		int rt, r, l;
		fin >> rt >> l >> r;
		vec_2250[rt].left = l;
		if(l != -1) vec_2250[l].parent = rt;
		vec_2250[rt].right = r;
		if (r != -1) vec_2250[r].parent = rt;

		max_number = max_value(max_number, max_value(rt, (max_value(r, l))));
	}
	int root = 0;
	for (int i = 0; i < max_number; i++)
	{
		if (vec_2250[i + 1].parent == -1)
		{
			root = i + 1;
			break;
		}

	}
	int max_level = inOrder_counting(root);

	

	std::vector<int>* level_vec = new std::vector<int>[max_level +1];
	for (int i = 1; i <= number; i++)
	{
		
		level_vec[vec_2250[i].level].push_back(vec_2250[i].row_number);
		//std::cout << i << " : " << vec[i].level << " " << vec[i].row_number << std::endl;
		
	}
	int max_width = 1;
	int max_width_level = 1;
	for (int i = 1; i < max_level + 1; i++)
	{
		int width = cal_max_width(level_vec[i]);
		//std::cout << i << " : " << width << std::endl;
		max_width_level = (max_width < width) ? i : max_width_level;
		max_width = max_value(max_width, width);
		
	}

	std::cout << max_width_level << " " << max_width << std::endl;
	
	delete[] level_vec;
	return 0;
}

