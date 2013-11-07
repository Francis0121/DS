// Lab 008 
// Name :
// Student ID :

#include "lab008.h"


void Graph::Edge(int e1, int e2, int cost){ 
	Cost[e1][e2] = cost;
	Cost[e2][e1] = cost;
}

void Graph::Dfs(int v){ 
	if(visited[v] == 1){
		return;
	}else{
		visited[v] = 1;
	}

	for(int i=v; i<numofnodes; i++){
		if(Cost[v][i] != 0){
			if(visited[i] == 0){
				cout << v << "-" << i << " : " << Cost[v][i] << endl;
			}
			Dfs(i);
		}
	}
}


