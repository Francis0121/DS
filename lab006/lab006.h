
#include<iostream>
#include<string>
using namespace std;

// ---------- Heap class -------------
template <class T>
class MinHeap
{
public :
	MinHeap(int theCapacity = 10);	// constructor

	void Init(const T *, int);
	void PreOrder(const int node);
	void Show();
	void Pop();
private :
	T* heap; // array
	int heapSize;	// number of elements in heap
	int capacity;	// size of the array heap
};

template<class T>
MinHeap<T>::MinHeap(int theCapacity)
{ // MinHeap constructor. 
	capacity = theCapacity;
	heap = new T[capacity + 1];	// heap[0] is not used
	heapSize = 0;
}


template <class T>
void MinHeap<T>::Show()
{ // Show all the element in sequence
	cout << "Heap : - ";

	// print all the nodes in the heap
	for(int i = 1; i <= heapSize; i++)
		cout << heap[i] << "  ";
	cout << endl;
}

template <class T>
void  MinHeap<T>::Init(const T *es, int n)
{	// initialize the heap by using the input
	heapSize = n;
	for(int i = 1; i <= n; i++)
		heap[i] = es[i];
}


