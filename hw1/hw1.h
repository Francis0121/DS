// HW1

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

template <class T>
class Stack {
	T *stack;
	int capacity;	// size of termArray
	int top;	// number of nonzero terms

public:
	Stack(int stackCapacity = 100);
	// Create an empty stack whose initial capacity is stackCapacity

	bool IsEmpty() const;
	// If number of elements in the stack is 0, return true else return false

	T & Top () const;
	// Return top element of stack

	void Push (const T & item);
	// Insert item into the top of the stack

	void Pop();
	// Delete the top element of the stack

	void Show()
	{
		cout << "  Stack : ";
		for(int i = 0; i <= top; i++)
			cout << stack[i] << " ";
		cout << endl;
	};

	// Show the stack elements
}; 


extern double PostfixEval(char *ps);
extern void ToPostFix(char *indata, char *postfix);


