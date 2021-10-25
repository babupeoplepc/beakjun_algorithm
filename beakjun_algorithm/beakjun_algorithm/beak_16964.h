#pragma once

namespace beak_16964 {
#include <iostream>
#include <vector>
#include <algorithm>
	const int MAX_NUMBER = 100000 + 1;
	std::vector<int> vec[MAX_NUMBER];
	int dfsOrder[MAX_NUMBER] = { 0, };
	int visited[MAX_NUMBER] = { 0, };
	std::vector<int> dfsInputOrder;

	bool comp(const int& a, const int& b)
	{
		return dfsOrder[a] < dfsOrder[b];
	}

	bool dfs(int node)
	{
		static int idxCount = 1;

		visited[node] = true;
		for (int i = 0; i < vec[node].size(); i++)
		{
			int postNode = vec[node][i];
			if (!visited[postNode] && dfsInputOrder[idxCount] == postNode)
			{
				idxCount++;
				visited[node] = 2;
				if (!dfs(postNode))
					return false;
			}
			else if(visited[postNode] == 2)
			{

			}
			else
				return false;
		}
		return true;
	}

	int main()
	{
		
		int numberOfNode;
		int n1, n2, n3;
		std::cin >> numberOfNode;
		dfsInputOrder.reserve(numberOfNode + 1);

		for (int i = 0; i < numberOfNode-1; i++)
		{
			std::cin >> n1 >> n2;
			vec[n1].push_back(n2);
			vec[n2].push_back(n1);
		}
		
		for (int i = 1; i <= numberOfNode; i++)
		{
			std::cin >> n3;
			dfsOrder[n3] = i;
			dfsInputOrder.push_back(n3);
		}
		for (int i = 1; i <= numberOfNode; i++)
		{
			std::sort(vec[i].begin(), vec[i].end(), comp);
		}

		if (dfsInputOrder.front() != 1)
		{
			std::cout << "0" << std::endl;
		}
		else
		{
			std::cout << dfs(1) << std::endl;
		}
		

		return 0;
	}
}