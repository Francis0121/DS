// Lab 009 
// Name : Kim Sung geun 
// Student ID : 20093267

#include "lab009.h"

void Graph::Edge(int e1, int e2, int cost){ 
	Cost[e1][e2] = cost;
}

void Graph::OutPath(int i){	
	if(p[i] == -1){
		cout << i << " ";
		return;
	}

	OutPath(p[i]);
	cout << i << " ";
}

void Graph::BellmanFord(int v){ 
	// Initialize d(*)
	dist[v] = 0;
	for(int i=0; i < numofnodes; i++){
		if(i != v) dist[i] = LARGECOST;
		p[i] = -1;
	}
	
	for(int k=1; k < numofnodes; k++){

		for(int n=0; n < numofnodes; n++){

			for(int w=0; w < numofnodes; w++){
				int cost = Cost[w][n];
				if(dist[n] > dist[w] + cost){
					dist[n] = dist[w]+cost;
					p[n] = w;
				}
			}

		}

	}

}


