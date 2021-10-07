#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>
const int MAX_NUMBER_1260 = 1001;

bool visited_1260[MAX_NUMBER_1260] = { false, };
std::list<int> graph_1260[MAX_NUMBER_1260];
std::vector<int> result_bfs_1260;
std::vector<int> result_dfs_1260;


int sorting_1260(std::list<int>& sl, int number)
{
	if (sl.size() == 0)
	{
		sl.push_front(number);
	}
	else
	{
		auto it = sl.begin();
		while (true)
		{
			if (it == sl.end())
			{
				sl.insert(it, number);
				break;
			}
			if (*it < number)
			{
				*it++;
			}
			else
			{
				sl.insert(it,number);
				break;
			}
		}
	}
	return 0;

}



void bfs_1260(int node)
{
	std::queue<int> q;
	q.push(node);
	visited_1260[node] = true;

	while (!q.empty())
	{
		int n1 = q.front();
		result_bfs_1260.push_back(n1);
		q.pop();
		for (auto it = graph_1260[n1].begin(); it != graph_1260[n1].end(); ++it)
		{
			int n2 = *it;
			if (!visited_1260[n2])
			{
				q.push(n2);
				visited_1260[n2] = true;

			}
		}
	}

}

void dfs_1260(int node)
{
	result_dfs_1260.push_back(node);
	visited_1260[node] = true;
	for(auto it = graph_1260[node].begin(); it != graph_1260[node].end(); ++it)
	{
		int n = *it;
		if (!visited_1260[n])
			dfs_1260(n);
	}
}


int sol_1260_main()
{
	int NumberOfNode = 0;
	int NumberOfLink = 0;
	int StartNode = 0;

	std::cin >> NumberOfNode >> NumberOfLink >> StartNode;
	for (int i = 0; i < NumberOfLink; i++)
	{
		int n1 = 0, n2 = 0;
		std::cin >> n1 >> n2;

		sorting_1260(graph_1260[n1], n2);
		sorting_1260(graph_1260[n2], n1);
	}

	dfs_1260(StartNode);
	
	for (int i : result_dfs_1260)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::fill(visited_1260, visited_1260 + MAX_NUMBER_1260, false);
	bfs_1260(StartNode);
	for (int i : result_bfs_1260)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}