
#include<iostream>
#include<string>
using namespace std;

// ---------- MaxLoserTree class -------------
template <class T>
class MaxLoserTree
{
public :
	MaxLoserTree(int theCapacity = 256);	// constructor

	void Show();

	void  BuildLoserTree(const T *, int);	// build the loser tree
private :
	T* lt; // array
	int numofelements;	// number of external elements in MaxLoserTree

	int capacity;	// size of the array lt
};

template<class T>
MaxLoserTree<T>::MaxLoserTree(int theCapacity)
{ // MaxLoserTree constructor. 
	capacity = theCapacity;
	lt = new T[capacity + 1];	// lt[0] is the winner
	numofelements = 0;
}


template <class T>
void MaxLoserTree<T>::Show()
{ // Show all the element in sequence
	cout << "MaxLoserTree : ";

	// print all the nodes in the array
	for(int i = 0; i < numofelements * 2; i++)
		cout << lt[i] << "  ";
	cout << endl;
}



