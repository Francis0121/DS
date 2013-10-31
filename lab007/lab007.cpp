// Lab 007 
// Name : 김성근
// Student ID : 20093267

#include "lab007.h"


template <class T>
void  MaxLoserTree<T>::BuildLoserTree(const T *externalnode, int n)
{   	
	// initialize the array by using the input
	// Then, compute the internal nodes
	for(int i=0; i<=2n; i++){
		li[i] = -1;
	}
    	
	numofelements = n;
	
	for(int i=2*n-1; i>=0; i--){
		if(n <= i){
			li[i] = externalnode[i];
		}else{
			int left = li[2*i];
			int right = li[2*i+1];
			
			li[i] = left >= right ? left : right;
		}
	}

}


// DO NOT REMOVE THE FOLLOWING
template class MaxLoserTree<int>;


