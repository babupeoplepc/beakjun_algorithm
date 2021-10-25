#pragma once
namespace beak_16940 {
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

	int const MAX_NUMBER = 100000+1;
	std::vector<int> vec[MAX_NUMBER];

	int visited[MAX_NUMBER] = {0, };
	int bfsOrder[MAX_NUMBER] = { 0, };
	std::vector<int> bfsOrderNumber;
	


	bool bfs()
	{
		auto bfsIt = bfsOrderNumber.begin();
		std::queue<int> q;
		q.push(*bfsIt);
		visited[*bfsIt] = true;
		bfsIt++;
		while (!q.empty())
		{
			int curNode = q.front();
			q.pop();
			for (int i = 0; i < vec[curNode].size(); i++)
			{
				int postNode = vec[curNode][i];
				if (postNode == *bfsIt && visited[postNode] == false)
				{
					bfsIt++;
					if (bfsIt == bfsOrderNumber.end()) return true;
					visited[curNode] = 2;
					visited[postNode] = true;
					q.push(postNode);
				}
				else if (visited[postNode] == 2)
				{

				}
				else
					return false;
			}
		}


		return true;
	}
	
	bool comp(const int& a, const int& b)
	{
		return bfsOrder[a] < bfsOrder[b];
	}
	int main()
	{
		int numberOfNode;
		std::cin >> numberOfNode;


		for (int i = 0; i < numberOfNode - 1; i++)
		{
			int n1, n2;
			std::cin >> n1 >> n2;
			vec[n1].push_back(n2);
			vec[n2].push_back(n1);
		}
		for (int i = 0; i < numberOfNode; i++)
		{
			int n1;
			std::cin >> n1;
			bfsOrder[n1] = i + 1;
			bfsOrderNumber.push_back(n1);
		}
		



		for (int i = 1; i <= numberOfNode; i++)
		{
			std::sort(vec[i].begin(), vec[i].end(), comp);
		}
		
		std::cout << bfs() << std::endl;

		return 0;
	}
}