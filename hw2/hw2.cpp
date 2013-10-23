// HW 2 : Binary Search Tree
// Name :
// Student ID :

#include "hw2.h"

template <class T>
bool  BSTree<T>::Insert(T kv)  
{


	return true;
}

template <class T>
T BSTree<T>::Get(T kv)  
{
	TreeNode<T> *ptr;
	ptr = root;


	return ptr->data;
} 


template <class T>
bool  BSTree<T>::Delete(T kv)  
{
	return true;
}

template <class T>
void  BSTree<T>::PreOrder(TreeNode<T> *ptr)  
{

	cout << "[" << ptr->data.key << "," << ptr->data.value << "] ";

}

template <class T>
void  BSTree<T>::InOrder(TreeNode<T> *ptr)  
{

	cout << "[" << ptr->data.key << "," << ptr->data.value << "] ";

}

template <class T>
void  BSTree<T>::PostOrder(TreeNode<T> *ptr)  
{
	cout << "[" << ptr->data.key << "," << ptr->data.value << "] ";
}

template <class T>
int  BSTree<T>::Count(TreeNode<T> *ptr)  
{
	return 0;
}

template <class T>
int  BSTree<T>::Height(TreeNode<T> *ptr)  
{
	return 0; 
}



// DO NOT REMOVE THE FOLLOWINGS
template class BSTree<Item>;

