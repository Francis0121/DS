// HW 3
// Name :
// Student ID : 20093267

#include "hw3.h"

template <class T>
void  QuickSort<T>::Swap(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template <class T>
void  QuickSort<T>::QSort(int s, int e){	
	// sort arr[s:e] into nonincreasing order
	cout << "Sort in [" << s << "," << e << "]" << endl;
	Show(s, e);

	if(s >= e)
		return;

	// Implement at the following....
	int m = ( s + e ) / 2;
	int leftmost = arr[s], middle = arr[m], rightmost = arr[e];
	int p;

	if( (leftmost <= middle && leftmost >= rightmost ) || (leftmost <= rightmost && leftmost >= middle ) ){
		p = s;
	}

	if( (rightmost <= middle && rightmost >= leftmost ) || (rightmost <= leftmost && rightmost >= middle ) ){
		p = e;
	}

	if( (middle <= leftmost && middle >= rightmost ) || (middle <= rightmost && middle >= leftmost ) ){
		p = m;
	}
	
	Swap(s, p);

	if(s < e){
		int i = s, j = e+1, pivot = arr[s];
		do{
			do i++; while(arr[i] > pivot);
			do j--; while(arr[j] < pivot);
			if(i<j) Swap(i, j);
		}while(i<j);
		Swap(s, j);

		QSort(s, j-1);
		QSort(j+1, e);
	}

}

// DO NOT REMOVE THE FOLLOWING LINE
template class QuickSort<int>;


