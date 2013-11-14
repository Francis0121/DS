
#include<iostream>
#include<string>
using namespace std;

#define LARGECOST (99)

// ---------- Graph class -------------
class Graph
{
public :
	Graph();	// constructor

	void Init(int);
	void Show();

	void Edge(int, int, int);
	void BellmanFord(int);
	void OutPath(int i);
private :
	int numofnodes;
	int Cost[256][256]; // matrix : 2 dimensional array
				// Assume that the numofnodes is less than 256
	int dist[256];
	int p[256];
};

