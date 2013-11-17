#include<iostream>
#include<string.h>
using namespace std;

// ---------- QuickSort class -------------
template <class T>
class QuickSort
{
public :
	QuickSort();	// constructor

	void Init(const T *, int);
	void Show(int s, int e);
	void Sort();	// An interface to the users 
private :
	void  QSort(int s, int e);	// internal quick sort algorithm
	void  Swap(int i, int j);	// swap two elements
	T arr[1024]; // array for elements
	int arrSize;	// number of elements in array
};

template<class T>
QuickSort<T>::QuickSort()
{ // QuickSort constructor. 
	arrSize = 0;
}


template <class T>
void QuickSort<T>::Show(int s, int e)
{ // Show all the element in the arr
	if(s > e)
		return;
	cout << "arr : ";

	// print all the nodes in the arr
	for(int i = 0; i < arrSize; i++)
	{
		if(i == s)
			cout << "[";
		else
			cout << " ";
		cout << arr[i];
		if(i == e)
			cout << "]";
		else
			cout << " ";
	}
	cout << endl;
}

template <class T>
void  QuickSort<T>::Init(const T *es, int n)
{	// fill the arr array by the input
	arrSize = n;
	for(int i = 0; i < n; i++)
		arr[i] = es[i];
}


template <class T>
void  QuickSort<T>::Sort()
{
	// sort arr[0:arrSize-1] into nonincreasing order
	// This is an invoking method to the Partition() and QSort() 
	QSort(0, arrSize - 1);	// quick sort from 0 to n-1
}


