#pragma once
#include <iostream>
#include <fstream>
#include <vector>

struct node_1167 {
	int number;
	int distance;
	node_1167(int n, int d) : number(n), distance(d) {}
};
const int max_1167 = 100001;
std::vector<node_1167> vec_1167[max_1167];
bool visited[max_1167];


node_1167 dfs_1167(int node, int dis, bool init)
{
	
	static node_1167 max_node(0,0);
	if (init) 
	{
		max_node.distance = 0;
		max_node.number = 0;
	}
	if (visited[node]) return max_node;

	if (max_node.distance < dis)
	{
		max_node.distance = dis;
		max_node.number = node;
	}
	visited[node] = true;
	for (int i = 0; i < vec_1167[node].size(); i++)
	{
		dfs_1167(vec_1167[node][i].number, vec_1167[node][i].distance + dis, false);
	}



	
	return max_node;
}


int beak_1167_main()
{

	int number;
	std::cin >> number;
	int first_node = 0;
	for (int i = 0; i < number; i++)
	{
		int p;
		std::cin >> p;
		while (true)
		{
			int idx, distance;
			std::cin >> idx;
			if (idx == -1) break;
			if (first_node == 0) first_node = p;

			std::cin >> distance;
			node_1167 new_node(idx, distance);
			vec_1167[p].push_back(new_node);
		}
	}
	/*
	std::ifstream fin;
	fin.open("beak_1167.txt");
	int number;
	fin >> number;
	int first_node = 0;
	while (!fin.eof())
	{
		int p;
		fin >> p;
		if (first_node == 0) first_node = p;
		while (true)
		{
			int idx, distance;
			fin >> idx;
			if (idx == -1) break;

			fin >> distance;
			node_1167 new_node(idx, distance);
			vec_1167[p].push_back(new_node);
			
		}
	}*/
	
	/*for (int i = 1; i <= 5; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < vec_1167[i].size(); j++)
		{
			std::cout << "( " << vec_1167[i][j].number << ", " << vec_1167[i][j].distance << " ), ";
		}
		std::cout << std::endl;
	}*/
	


	node_1167 f_node = dfs_1167(first_node, 0, true);
	std::fill(visited, visited + max_1167, false);
	node_1167 s_node = dfs_1167(f_node.number, 0, true);
	
	
	std::cout << s_node.distance << std::endl;


	return 0;
}