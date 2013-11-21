// LAB 010
// Name : Kim Sung Geun
// Student ID : 20093267

#include "lab010.h"

template <class T>
void  HeapSort<T>::Adjust(const int root, int n){	
	// adjust binary tree with root "root" to satisfy heap property.
	// The left and right subtrees of "root" already satisfy the heap
	// property. No node index is > n.

	T e = heapArr[root]; 
	int child = 2*root;

	while(child <= n){
		if( child < n ){
			if( heapArr[child] > heapArr[child+1]){
				child+=1;
			}
		}
		if( e <= heapArr[child] )
			break;
		else{
			heapArr[child/2] = heapArr[child];
			child*=2;
		}
	}
	heapArr[child/2] = e;

}

template <class T>
void  HeapSort<T>::Heapify(){	
	// reorder heapArr[1:n] into a heap

	for(int i = hSize/2 ; i > 0 ; i--)
		Adjust(i, hSize);	
}


// DO NOT REMOVE THE FOLLOWING.
template class HeapSort<int>;

