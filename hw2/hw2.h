// HW 2 : Binary Search Tree

#include<iostream>
#include<string>
using namespace std;

// Item Class
// this is the key-value pair
// We are going to put this pair into each node of the BST
struct Item {
	int key;
	int value;
	Item(int k, int v = 0) {key = k; value = v;};	
	Item() {};	
};

// forward declaration
template <class T> class BSTree;

// ---------- TreeNode class -------------

template <class T>
class TreeNode 
{
friend class BSTree<T>;

private :
	T data;	// storage for data : in HW 3, T will be Item
	TreeNode<T> *left;	// link to the left Child
	TreeNode<T> *right;	// link to the right Child

public :
	// constructors come here
	TreeNode(T d);
};

template <class T>
TreeNode<T>::TreeNode(T d)
{
	// data is given
	data = d;

	// the left and right field are NULL
	left = right = NULL;
}

// ---------- BSTree class -------------
template <class T>
class BSTree
{
public :
	BSTree();	// constructor
	~BSTree(); // destructor

	bool  Insert(T kv); 
	T  Get(T kv); 
	bool  Delete(T kv);
	void  PreOrder(TreeNode<T> *ptr);
	void  InOrder(TreeNode<T> *ptr);
	void  PostOrder(TreeNode<T> *ptr);
	int  Count(TreeNode<T> *ptr);
	int  Height(TreeNode<T> *ptr);

	void  Show();	// Show the nodes in the Binary Search Tree  
private :
      TreeNode<T>* root; // pointer to the root node
};

template<class T>
BSTree<T>::BSTree()
{ // BSTree constructor. Initialize root variable
	root = NULL; // root is NULL, an empty binary search tree
}


template<class T>
BSTree<T>::~BSTree()
{ // BSTree destructor. Delete all nodes 
  // in the binary search tree

	// ignore this in HW 3

}


template <class T>
void  BSTree<T>::Show()  
{
	cout << "Pre  Order : ";
	PreOrder(root);
	cout << endl << "In   Order : ";
	InOrder(root);
	cout << endl << "Post Order : ";
	PostOrder(root);
	cout << endl;
	cout << "Number of Nodes : " << Count(root) << endl;
	cout << "Height : " << Height(root) << endl;
}

