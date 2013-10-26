// HW 2 : Binary Search Tree
// Name : ±è¼º±Ù
// Student ID : 20093267

#include "hw2.h"

template <class T>
bool  BSTree<T>::Insert(T kv)  
{
	TreeNode<T> *parent = root, *grandparent = 0;

	while(parent){
		grandparent = parent;
		if(kv.key < parent->data.key) parent = parent->left;
		else if(kv.key > parent->data.key) parent = parent->right;
		else return false;
	}

	parent = new TreeNode<T>(kv);

	if(root){
		if(kv.key < grandparent->data.key) grandparent->left = parent;
		else grandparent->right = parent;
	}else{
		root = parent;
	}

	return true;
}

template <class T>
T BSTree<T>::Get(T kv)  
{
	TreeNode<T> *ptr = root;
	
	while(ptr){
		if(kv.key < ptr->data.key)
			ptr = ptr->left;
		else if(kv.key > ptr->data.key)
			ptr = ptr->right;
		else 
			break;
	}
	return ptr ? ptr->data : T(-1);
} 


template <class T>
bool  BSTree<T>::Delete(T kv)  
{
	TreeNode<T> *parent = root, *grandparent = NULL;
	bool left = false, right = true;
	while(parent){
		if(kv.key < parent->data.key){
			grandparent = parent;
			parent = parent->left;
			left = true;
			right = false;
		}
		else if(kv.key > parent->data.key){
			grandparent = parent;
			parent = parent->right;
			left = false;
			right = true;
		}
		else
			break;
	}

	if(parent == NULL){
		return false;
	}else{	
		int degree = 0;
		bool pleft = false, pright=false;
		if(parent->left){
			degree+=1;
			pleft = true;
		}else if(parent->right){
			degree+=1;
			pright=true;
		}

		switch (degree)
		{
		case 0:
			if(left){
				grandparent->left = NULL;
			}else if(right){
				grandparent->right = NULL;
			}
			break;
		case 1:
			if(left){
				if(pleft){
					grandparent->left = parent->left;
				}else if(pright){
					grandparent->left = parent->right;
				}
			}else if(right){
				if(pleft){
					grandparent->right = parent->left;
				}else if(pright){
					grandparent->right = parent->right;
				}
			}
			break;
		case 2:	
			TreeNode<T> *change = parent->left, *grandchange = parent;
			while(change->right){
				grandchange = change;
				change=change->right;
			}
			parent->data.key = change->data.key;
		
			if(change->left){
				grandchange->right=change->left;
			}else{
				grandchange->right=NULL;
			}
			break;
		}
	}
	return true;
}

template <class T>
void  BSTree<T>::PreOrder(TreeNode<T> *ptr)  
{
	if(ptr != NULL){
		cout << "[" << ptr->data.key << "," << ptr->data.value << "] ";
		PreOrder(ptr->left);
		PreOrder(ptr->right);
	}
}

template <class T>
void  BSTree<T>::InOrder(TreeNode<T> *ptr)  
{
	if(ptr != NULL){
		InOrder(ptr->left);
		cout << "[" << ptr->data.key << "," << ptr->data.value << "] ";
		InOrder(ptr->right);
	}
}

template <class T>
void  BSTree<T>::PostOrder(TreeNode<T> *ptr)  
{
	if(ptr != NULL){
		PostOrder(ptr->left);
		PostOrder(ptr->right);
		cout << "[" << ptr->data.key << "," << ptr->data.value << "] ";
	}
}

template <class T>
int  BSTree<T>::Count(TreeNode<T> *ptr)  
{
	if(ptr == NULL){
		return 0;
	}
	return Count(ptr->left) + 1 + Count(ptr->right);
}

template <class T>
int  BSTree<T>::Height(TreeNode<T> *ptr)  
{
	if(ptr == NULL){
		return 0;
	}
	int height = (ptr->left == NULL && ptr->right == NULL) || ptr->left != NULL || ptr->right != NULL ? 1 : 0;
	int left = Height(ptr->left);
	int right = Height(ptr->right);
	return left >= right ? left + height : right + height; 
}



// DO NOT REMOVE THE FOLLOWINGS
template class BSTree<Item>;

