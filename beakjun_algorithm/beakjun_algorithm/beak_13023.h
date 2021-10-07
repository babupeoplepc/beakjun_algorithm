#pragma once

#include <iostream>
#include <vector>
const int MAX_NUMBER = 2001;
bool visited_13023[MAX_NUMBER];
std::vector<int> friends[MAX_NUMBER];
bool result_13023 = false;



bool dfs_13023(int node, int depth)
{
	
	if (depth == 4)
	{	
		return true;
	}

	visited_13023[node] = true;
	bool rtn = false;
	if(node == 4)
	{
		int a;
		a = 4;
	}
	
	for (int i = 0; i < friends[node].size(); i++)
	{
		int n = friends[node][i];
		
		if(visited_13023[n] == false)
			rtn = dfs_13023(n, depth+1);

		if (rtn)
			return true;
	}
	visited_13023[node] = false;
	return false;

}

int sol_13023_main()
{
	int NumberOfHuman = 0;
	int RelationShip = 0;
	
	std::cin >> NumberOfHuman >> RelationShip;
	
	

	for (int i = 0; i < RelationShip; i++)
	{
		int n1 = 0, n2 = 0;
		std::cin >> n1 >> n2;
		friends[n1].push_back(n2);
		friends[n2].push_back(n1);
	}

	bool rtn = false;
	
	for (int i = 0; i < NumberOfHuman; i++)
	{
		std::fill(visited_13023, visited_13023 + MAX_NUMBER, false);
		rtn = dfs_13023(i, 0);
		
		if (rtn) break;
	}
	std::cout << rtn << std::endl;

	return 0;
}