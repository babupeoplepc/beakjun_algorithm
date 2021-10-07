#pragma once
#include <iostream>
#include <vector>
#include <queue>

const int MAX_NUMBER_11724 = 1001;
std::vector<int> graph_11724[MAX_NUMBER_11724];
bool visited_11724[MAX_NUMBER_11724] = { false, };
int ConnectedComp = 0;

void dfs_11724(int node)
{
	visited_11724[node] = true;
	for (int i = 0; i < graph_11724[node].size(); i++)
	{
		int n = graph_11724[node][i];
		if (!visited_11724[n])
			dfs_11724(n);
	}
}

int sol_11724_main()
{
	int NumberOfNode = 0;
	int NumberOfLink = 0;
	std::cin >> NumberOfNode >> NumberOfLink;
	for (int i = 0; i < NumberOfLink; i++)
	{
		int n1 = 0, n2 = 0;
		std::cin >> n1 >> n2;
		graph_11724[n1].push_back(n2);
		graph_11724[n2].push_back(n1);
	}

	for (int i = 0; i < NumberOfNode; i++)
	{
		if (!visited_11724[i + 1])
		{
			ConnectedComp++;
			dfs_11724(i + 1);
		}
	}
	std::cout << ConnectedComp << std::endl;

	return 0;
}