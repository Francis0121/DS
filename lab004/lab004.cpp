// Lab 004 
// Name : 김성근 
// Student ID : 20093267

#include "lab004.h"

template <class T> 
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity){
	if(capacity < 1) 
		throw "Queue capacity must be > 0";
    	queue = new T[capacity];
	front = rear = 0;
}


// IMPLEMENT THE FUNCTIONS HERE
template <class T>
bool Queue<T>::IsEmpty() const{
	return front == rear;
}

template <class T>
bool Queue<T>::IsFull() const{
	return (rear + 1) % capacity == front;
}

template <class T>
void Queue<T>::Push(const T& item){
	if(IsFull()){
		//TODO Extended Capacity
		throw "Queue is Full";
	}

	rear = (rear+1) == capacity ? 0 : (rear+1);	
	queue[rear] = item;

}

template <class T>
void Queue<T>::Pop(){
	if(IsEmpty()){
		throw "Queue is empty. Cannot delete";
	}
	
	front = (front+1) == capacity ? 0 : (front+1);
}

template <class T>
void Queue<T>::Show(){
	cout << "Queue : ";
	if(IsEmpty()){

	}else if(front < rear){
		for(int i=front+1; i <=rear; i++){
			cout << queue[i] << " ";
		}	
	}else{
		for(int i=front+1; i < capacity; i++){
			cout << queue[i] << " ";
		}
		for(int i=0; i<rear+1; i++){
			cout << queue[i] << " ";
		}
	}
	cout << endl;
}


// Do Not Remove the followings
// This is for template instantiation
template class Queue<char>;


