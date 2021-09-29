#pragma once
#include <iostream>
#include <fstream>
#include <vector>

const int MAX = 100001;
std::vector<int> vec_11725[MAX];
bool visited_11725[MAX];
int parent_11725[MAX];

void dfs(int node)
{
	visited_11725[node] = true;

	for (int i = 0; i < vec_11725[node].size(); i++)
	{
		int next = vec_11725[node][i];
		if (!visited_11725[next])
		{
			parent_11725[next] = node;
			dfs(next);
		}
	}
}

int so_11725_main()
{
	/*int number;
	std::cin >> number;
	for (int i = 0; i < number-1; i++)
	{
		int f, s;
		std::cin >> f >> s;
		vec[f].push_back(s);
		vec[s].push_back(f);
	}*/

	std::ifstream fin;
	fin.open("beak_11725.txt");
	int number;	
	fin >> number;
	while (!fin.eof())
	{
		int f, s;
		fin >> f >> s;
		vec_11725[f].push_back(s);
		vec_11725[s].push_back(f);
	}
	dfs(1);
	for (int i = 2; i <= number; i++)
		std::cout << parent_11725[i] << '\n';

	return 0;

}