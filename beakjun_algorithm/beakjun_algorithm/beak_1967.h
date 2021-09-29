#pragma once
#include <iostream>
#include <fstream>
#include <vector>

struct node_1967 {
	int number;
	int weight;
	node_1967(int n, int w) : number(n), weight(w) {}
	friend std::ostream& operator<<(std::ostream& os, const node_1967& c)
	{
		os << "( " << c.number << ", " << c.weight << " )";
		return os;
	}

};

const int max_1967 = 10001;
std::vector<node_1967> vec_1967[max_1967];
bool visited_1967[max_1967];


node_1967 dfs_1967(int node, int weight, bool init)
{
	static node_1967 max_node(0,0);
	if (init)
	{
		max_node.number = 0;
		max_node.weight = 0;
	}
	if (visited_1967[node]) return max_node;

	visited_1967[node] = true;
	if (max_node.weight < weight)
	{
		max_node.weight = weight;
		max_node.number = node;
	}

	for (int i = 0; i < vec_1967[node].size(); i++)
	{
		dfs_1967(vec_1967[node][i].number, vec_1967[node][i].weight + weight, false);
	}
	return max_node;

}

int sol_1967_main()
{

	int number = 0;
	int n1 = 0, n2 =0;
	int weight = 0;	
	int first_node = 0;
	
	std::cin >> number;
	for (int i = 0; i < number - 1; i++)
	{

		std::cin >> n1 >> n2 >> weight;
		if (first_node == 0) first_node = n1;
		vec_1967[n1].push_back(node_1967(n2, weight));
		vec_1967[n2].push_back(node_1967(n1, weight));
	}
	/*
	std::ifstream fin;
	fin.open("beak_1967.txt");
	fin >> number;
	for (int i = 0; i < number-1; i++)
	{
		
		fin >> n1 >> n2 >> weight;
		if (first_node == 0) first_node = n1;
		vec_1967[n1].push_back(node_1967(n2, weight));
		vec_1967[n2].push_back(node_1967(n1, weight));
	}*/

	std::fill(visited_1967, visited_1967 + max_1967, false);
	node_1967 f_node = dfs_1967(first_node, 0, true);
	//std::cout << f_node << std::endl;

	std::fill(visited_1967, visited_1967 + max_1967, false);
	node_1967 s_node = dfs_1967(f_node.number, 0, true);

	std::cout << s_node.weight << std::endl;

	return 0;
}