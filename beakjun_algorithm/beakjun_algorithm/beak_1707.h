#pragma once
#include <iostream>
#include <vector>
#include <queue>

const int NOT_VISITED = 0;
const int BLUE_1707 = 1;
const int RED_1707 = 2;
const int MAX_VALUE_1707 = 20001;
std::vector<int> vec_1707[MAX_VALUE_1707];
int visited_1707[MAX_VALUE_1707] = { NOT_VISITED, };


bool bfs_1707(int node)
{


	int color = BLUE_1707;
	std::queue<int> q;
	q.push(node);
	visited_1707[node] = color;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();


		color = (visited_1707[x] == BLUE_1707) ? RED_1707 : BLUE_1707;

		for (int i = 0; i < vec_1707[x].size(); i++)
		{
			int y = vec_1707[x][i];
			if (visited_1707[y] == NOT_VISITED)
			{
				q.push(y);
				visited_1707[y] = color;
			}
			else
			{
				/*for (int j = 0; j < vec_1707[y].size(); j++)
				{
					int z = vec_1707[y][j];
					
					if (visited_1707[z] == color)
					{
						return false;
					}
				}*/
			}
				
		}
	}
	return true;

}
bool is_bipartite(int n)
{
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 0; j < vec_1707[i].size(); j++)
		{
			int next = vec_1707[i][j];
			if (visited_1707[i] == visited_1707[next])
				return false;
		}
	}
	return true;
}

int sol_1707_main()
{
	int NumberOfCase = 0;
	int NumberOfNode = 0;
	int NumberOfLink = 0;
	std::cin >> NumberOfCase;
	for (int i = 0; i < NumberOfCase; i++)
	{
		bool rtn = false;
		std::cin >> NumberOfNode >> NumberOfLink;
		for (int j = 0; j < NumberOfLink; j++)
		{
			int n1 = 0, n2 = 0;
			std::cin >> n1 >> n2;
			vec_1707[n1].push_back(n2);
			vec_1707[n2].push_back(n1);
		}
		for (int j = 1; j < NumberOfNode+1; j++)
		{
			if (visited_1707[j] == NOT_VISITED)
			{
				rtn = bfs_1707(j);
				if (rtn == false)
				{
					break;
				}
			}
		}

		if (is_bipartite(NumberOfNode))
			std::cout << "YES" << "\n";
		else
			std::cout << "NO" << "\n";

		std::fill(visited_1707, visited_1707 + MAX_VALUE_1707, NOT_VISITED);
		for (int j = 1; j < NumberOfNode + 1; j++)
		{
			vec_1707[j].clear();
		}
		
	}
	return 0;
}