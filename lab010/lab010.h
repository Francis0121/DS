#include<iostream>
#include<string>
using namespace std;




// ---------- HeapSort class -------------
template <class T>
class HeapSort
{
public :
	HeapSort(int theCapacity = 10);	// constructor

	void Init(const T *, int);
	void Show();


	void Adjust(const int root, const int n);
	void Heapify();


private :
	T* heapArr; // array
	int hSize;	// number of elements in heapArr
	int capacity;	// size of the array heapArr
};



template<class T>
HeapSort<T>::HeapSort(int theCapacity)
{ // HeapSort constructor. 
	capacity = theCapacity;
	heapArr = new T[capacity + 1];	// heapArr[0] is not used
	hSize = 0;
}


template <class T>
void HeapSort<T>::Show()
{ // Show all the element in heapArr
	cout << "Heap : - ";

	// print all the nodes in heapArr
	for(int i = 1; i <= hSize; i++)
		cout << heapArr[i] << "  ";
	cout << endl;
}



template <class T>
void  HeapSort<T>::Init(const T *es, int n)
{	// fill the heapArr array by the input
	// we need to create heap structure when we call hSort()
	hSize = n;
	for(int i = 1; i <= n; i++)
		heapArr[i] = es[i];
}


