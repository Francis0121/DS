
#include "lab009.h"

Graph::Graph()
{ // Graph constructor. 
	numofnodes = 0;
}

void Graph::Init(int n)
{ 
	// initialize the Cost Adjacency Matrix Cost
	numofnodes = n;
	// Initialize the Cost Adjacency Matrix with LARGECOST
	for(int i = 0; i < numofnodes; i++)
	{
		// initialize all entries to 0
		for(int j = 0; j < numofnodes; j++)
			Cost[i][j] = LARGECOST;	// initialize the adjacency matrix
		Cost[i][i] = 0;	// cost 0 to itself
	}
}

void Graph::Show()
{ 
	int i = 0;
	cout << "Dist : ";
	for(i = 0; i < numofnodes; i++)
		cout << dist[i] << " ";
	cout << endl;

	cout << "P    : ";
	for( i = 0; i < numofnodes; i++)
		cout << p[i] << " ";
	cout << endl;

	// show the paths to all the destinations
	for( i = 0; i < numofnodes; i++)
	{
		cout << "Path to " << i << " : ";
		OutPath(i);	
		cout << endl;
	}
}



int main()
{
	Graph g;	// graph 

	while(1)
	{
		cerr << "BF > ";
		string command;
		cin >> command;

		if(command.compare( "quit") == 0)
		{
			break;
		}
		else if(command.compare( "init") == 0)
		{
			int nn;
			cin >> nn;
			g.Init(nn);
		}
		else if(command.compare( "edge") == 0)
		{
			int e1, e2, cost;
			cin >> e1 >> e2 >> cost;
			g.Edge(e1, e2, cost);
		}
		else if(command.compare( "bf") == 0)
		{
			int nid;
			cin >> nid;
			g.BellmanFord(nid);
			g.Show();
		}
	}
	cerr << endl;

	return 1;
}


