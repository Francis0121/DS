// HW1 
// Name : 김성근
// Student ID : 20093267

#include "hw1.h"

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity (stackCapacity){
	if(capacity < 1) throw "Stack Capacity must be > 0";
	stack = new T[capacity];
	top = -1;//(원소가 없는 경우 -1 부터 시작)
}

template <class T>
inline bool Stack<T>::IsEmpty() const
{
	return top == -1;
}
	// If number of elements in the stack is 0, return true else return false

template <class T>
inline T & Stack<T>::Top () const
{
	if(IsEmpty()){ 
		throw "Stack is Empty";
	}
	return stack[top];	
}


// Return top element of stack

template <class T>
void Stack<T>::Push (const T & item){ 
	if(top == (capacity - 1)){
		//TODO Make Change Size
		throw "Not Enough Array";
		//ChangeSize(stack, capactiy, capacity * 2);
		//capacity *=2;
	}
	stack[++top] = item;
}

template <class T>
void Stack<T>::Pop(){
	if(IsEmpty()){
		throw "Stack is empty. Cannot delete";
	}
	stack[top].~T(); // destructor for T
	top--;
}



double PostfixEval(char *ps)
{
	double val = 0;
	int len = strlen(ps);

	Stack<double> est;

	for(int i = 0; i < len; i++)
	{



	}

	return val;
}

// 0 ~ 9, '(' ')' * / + i 만 사용
void ToPostFix(char *indata, char *postfix)
{
	int len = strlen(indata);

	// now transform the infix into postfix
	Stack<char> pst;

	for(int i = 0; i < len; i++)
	{
		char token = indata[i];
		cout << "Token " << token << endl;
		cout << "Priority "<< priority(token);

		pst.Show();
	}
}
	
int priorirty(const char &ch){
	int number = -1;
	switch(ch){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		number = 0;
		break;
	case '(':
		number = 1;
		break;
	case '*':
	case '/':
		number = 2;
		break;
	case '+':
	case '-':
		number = 3;
		break;
	}
	return number;
}

// Template Class int, double Type Use
template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
