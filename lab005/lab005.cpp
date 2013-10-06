// Lab 005
// Name : ±è¼º±Ù	
// Student ID : 20093267

#include "lab005.h"

template <class T>
void CircularList<T>::InsertFront(const T & e){
// Insert the element e at the front position
	head->link = new ChainNode<T>(e, head->link);
}


template <class T>
bool CircularList<T>::Delete(const T & e){ // delete an element from the position theIndex
	ChainNode<T>* currentNode = head->link;

	int index = 0;
	while(currentNode != head && currentNode->data != e){
		currentNode = currentNode->link;
		index++;
	}

	if(currentNode == NULL){
		return false;
	}else{
		if(head->link == NULL){
			return false;
		}
		ChainNode<T>* deleteNode;
		if(index == 0){
			deleteNode = head->link;
			head->link = head->link->link;
		}else{
			ChainNode<T>* p = head->link;
			for(int i=0; i<index-1;i++){
				if(p == head)
					return false;
				p = p->link;
			}
			if( (p == head) || (p->link == head) )
				return false;
			deleteNode = p->link;
			p->link = p->link->link;
		}
		delete deleteNode;
		return true;
	}
}

template <class T>
int  CircularList<T>::Size() const {
	int cnt = 0;

	ChainNode<T>* currentNode = head->link;
	while(currentNode != head){
		currentNode = currentNode->link;
		cnt++;
	}

	return cnt;
}

// DO NOT REMOVE THE FOLLOWINGS. 
template class CircularList<int>;