// Lab 007 
// Name : 
// Student ID : 20093267

#include "lab007.h"


template <class T>
void  MaxLoserTree<T>::BuildLoserTree(const T *externalnode, int n)
{   	
	// initialize the array by using the input
	// Then, compute the internal nodes
	
	numofelements = n;

	for(int i=0; i < n; i++){
		lt[n+i] = externalnode[i];
		lt[i]=-1;
	}

	for(int i=n; i<2*n; i++){
		int parent = i/2;
		int value = lt[i];
		while(true){
		
			if(lt[parent] == -1){
				lt[parent] = value; 
				break;
			}else{
				if(lt[parent] >= value){
					int temp = lt[parent];
					lt[parent] = value;
					value = temp;
				}
			}
			parent = parent/2;
		}
	}

}


// DO NOT REMOVE THE FOLLOWING
template class MaxLoserTree<int>;


