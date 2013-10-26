// Lab 006 
// Name : ±è¼º±Ù
// Student ID : 20093267

#include "lab006.h"

template <class T>
void  MinHeap<T>::Pop()
{	// Pop the minimum element

	if(heapSize == 0)
		return;
	
	T last = heap[heapSize--];

	int currentNode = 1;
	int child = 2;
	while(child <= heapSize){

		if(child < heapSize && heap[child]>heap[child+1]) child++;

		if(last <= heap[child]) break;

		heap[currentNode] = heap[child];
		currentNode = child;
		child *= 2;
	}
	heap[currentNode] = last;
}

template <class T>
void  MinHeap<T>::PreOrder(const int idx)
{
	if(idx > heapSize)
		return;

	cout << heap[idx] << ' ';
	PreOrder(2*idx);
	PreOrder(2*idx+1);

}


// DO NOT REMOVE THE FOLLOWING LINE
template class MinHeap<int> ;
