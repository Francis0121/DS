// Lab 008

#include "lab008.h"


Graph::Graph()
{ // Graph constructor. 
	numofnodes = 0;
	Cost = NULL;
	visited = NULL;
}

void Graph::Init(int n)
{ 
	// initialize the Cost Adjacency Matrix Cost
	if(Cost)	
	{	// when there is old Cost, delete it
		for(int i = 0; i < numofnodes; i++)
			delete [] Cost[i];	
		delete Cost;
	}
	numofnodes = n;

	// now create 2 dimensional array of numofnodes * numofnodes
	Cost = new int*[numofnodes];
	for(int i = 0; i < numofnodes; i++)
	{
		Cost[i] = new int[numofnodes];
		// initialize all entries to 0
		for(int j = 0; j < numofnodes; j++)
			Cost[i][j] = 0;	// initialize the adjacency matrix
	}
}

void Graph::Show()
{ 
	for(int i = 0; i < numofnodes; i++)
	{
		for(int j = 0; j < numofnodes; j++)
			cout << Cost[i][j] << " ";
		cout << endl;
	}
}

void Graph::InitVisited()
{ // initialize the visited array
	if(visited)
		delete visited;
	visited = new int[numofnodes];
	for(int i = 0; i < numofnodes; i++)
		visited[i] = 0;	// initialize the visited vector
	
}



int main()
{
	Graph g;	// graph 

	while(1)
	{
		cerr << "Graph > ";
		string command;
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("vertices") == 0)
		{
			int nn;
			cin >> nn;
			g.Init(nn);
			cout << "New graph : " << nn << " nodes" << endl;
		}
		else if(command.compare("edge") == 0)
		{
			int e1, e2, cost;
			cin >> e1 >> e2 >> cost;
			g.Edge(e1, e2, cost);
		}
		else if(command.compare("dfs") == 0)
		{
			g.InitVisited();
			int nid;
			cin >> nid;
			cout << "Cost Adjacency Matrix" << endl;
			g.Show();
			cout << "Dfs Started : " << nid << endl;
			g.Dfs(nid);
		}
	}
	cerr << endl;

	return 1;
}


