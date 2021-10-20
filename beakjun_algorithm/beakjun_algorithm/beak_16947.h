#pragma once


namespace beak_16947 
{
#include <queue>
#include <iostream>
#include <vector>
#include <memory.h>

	const int MAX_NUMBER = 3000+1;
	std::vector<int> subway[MAX_NUMBER];
	int subway_depth[MAX_NUMBER] = {0, };
	bool visited[MAX_NUMBER] = { false, };

	void printDepth(int number)
	{

		for (int i = 0; i < number; i++)
		{
			std::cout << subway_depth[i + 1] << " ";
		}
		std::cout << std::endl;
	}
	void printVisited(int number)
	{
		for (int i = 0; i < number; i++)
		{
			std::cout << visited[i + 1] << "  ";
		}
		std::cout << std::endl;
	}

	int dfs_c(int node, int depth)
	{
		static int startNode = 0;
		static bool cross_subway = false;
		if (depth == 0)
		{
			startNode = node;
			cross_subway = false;
		}

		visited[node] = true;
		subway_depth[node] = depth;

		for (int i = 0; i < subway[node].size(); i++)
		{
			int nextNode = subway[node][i];
			
			if (cross_subway) continue;

			if (nextNode == startNode && depth >=2)
			{
				cross_subway = true;
			}

			if (!visited[nextNode])
			{
				dfs_c(nextNode, depth + 1);
			}
		}
		if (cross_subway)
		{
			subway_depth[node] = -1;	// 순환라인
		}
		else
		{
			visited[node] = false;

		}	
		return cross_subway;
	}

	void bfs(int node)
	{
		std::queue<int> q;
		q.push(node);
		while (!q.empty())
		{
			int curtNode = q.front();
			q.pop();
			for (int i = 0; i < subway[curtNode].size(); i++)
			{
				int nextNode = subway[curtNode][i];
				if (!visited[nextNode])
				{
					visited[nextNode] = true;;
					q.push(nextNode);
					subway_depth[nextNode] = subway_depth[curtNode] + 1;
				}
			}
		}
	}


	int sol_16947_main()
	{
		int numberOfStation = 0;
		std::cin >> numberOfStation;
		for (int i = 0; i < numberOfStation; i++)
		{
			int n1, n2;
			std::cin >> n1 >> n2;
			subway[n1].push_back(n2);
			subway[n2].push_back(n1);
		}
		std::vector<int> crossSubway;
		
		
		for (int i = 0; i < numberOfStation; i++)
		{
			if (subway[i+1].size() >= 3)
			{
				crossSubway.push_back(i+1);
				std::cout << i+1 << " ";
			}			
		}
		std::cout << std::endl;
		if (crossSubway.empty()) 
		{
			
		}
		else
		{
			for (int i : crossSubway)
			{
				if (dfs_c(i, 0))
					break;
				else
				{
					memset(visited, 0x00, sizeof(visited));
					memset(subway_depth, 0x00, sizeof(subway_depth));
				}
			}
			printVisited(numberOfStation);
			printDepth(numberOfStation);
			for (int i=0; i< numberOfStation; i++)
			{
				if (subway_depth[i+1] == -1)
				{
					subway_depth[i+1] = 0;
					bfs(i+1);
				}

			}
		}
		

		
		printDepth(numberOfStation);

		return 0;
	}
}

