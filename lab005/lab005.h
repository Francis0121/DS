#include<iostream>
#include<string>
using namespace std;

// forward declaration
template <class T> class CircularList;

// ---------- ChaninNode class -------------

template <class T>
class ChainNode 
{
friend class CircularList<T>;

private :
	T data;	// storage for data
	ChainNode<T> *link;	// link to the next node

public :
	// constructors come here
	ChainNode();
	ChainNode(const T& data, ChainNode<T>* link);
};

template <class T>
ChainNode<T>::ChainNode()
{
	this->link = this;
	// the link field contains the ChainNode itself
}

template <class T>
ChainNode<T>::ChainNode(const T& data, ChainNode<T>* link)
{
	// set the data field and link field
	this->data = data;
	this->link = link;
}

// ---------- CircularList class -------------
template <class T>
class CircularList
{
public :
	CircularList();	// constructor
	~CircularList(); // destructor

	int Size() const;
	// Return the number of element in the list

	void InsertFront(const T & e);
	// insert an element into the first position

	bool Delete(const T & e);
	// delete an element of the given element e
	// if the element exists, return true
	// else return false

	void Show();
	// show all the elements
private :
      ChainNode<T>* head; // pointer to the dummy head node
};

template<class T>
CircularList<T>::CircularList()
{ // CircularList constructor. Create a dummy head node
	head = new ChainNode<T>(); 
}


template<class T>
CircularList<T>::~CircularList()
{ // CircularList destructor. Delete all nodes 
  // in the circular list.

	ChainNode<T>* end = head;

	// remove all the nodes
	while (head != end)
	{	// delete head
		ChainNode<T>* next = head->link;
		delete head;
		head = next;
	}
}

template <class T>
void CircularList<T>::Show()
{ // Show all the elements in sequence
	ChainNode<T>* p = head->link;

	cout << "List : ";

	// show all the nodes
	while (p != head)
	{
		cout << p->data << " ";
		p = p->link;
	}
	cout << endl;
}



