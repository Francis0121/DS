
#include<iostream>
#include<string>
using namespace std;

// ---------- Graph class -------------
class Graph
{
public :
	Graph();	// constructor

	void Init(int);
	void InitVisited();
	void Edge(int, int, int);
	void Dfs(int);
	void Show();	// show the adjacent matrix
private :
	int **Cost; // matrix : 2 dimensional array
	int numofnodes;
	int *visited;
};

