// HW1 
// Name : 김성근
// Student ID : 20093267

#include "hw1.h"

class Priority{
private :
public:
	int ICP(const char &ch){
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

	int ISP(const char &ch){
		int number = -1;
		switch(ch){
		case '*':
		case '/':
			number = 2;
			break;
		case '+':
		case '-':
			number = 3;
			break;
			case '(':
			number = 4;
			break;
		}
		return number;
	}
};

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



double PostfixEval(char *postfix)
{
	double val = 0;
	int len = strlen(postfix);

	Stack<double> stack = Stack<double>();

	Priority p = Priority();
	for(int i = 0; i < len; i++){
		char token = postfix[i];	
		if( p.ICP(token) == 0 ){
			stack.Push(atoi(&token));
		}else{
			double operand1 = stack.Top();
			stack.Pop();
			double operand2 = stack.Top();
			stack.Pop();

			double calculate = 0;
			switch(token){
			case '+':
				calculate = operand2 + operand1;
				break;
			case '-':
				calculate = operand2 - operand1;
				break;
			case '/':
				calculate = operand2 / operand1;
				break;
			case '*':
				calculate = operand2 * operand1;
				break;
			}

			stack.Push(calculate);
		}
	}

	val = stack.Top();
	stack.Pop();

	return val;
}

// 0 ~ 9, '(' ')' * / + i 만 사용
void ToPostFix(char *indata, char *postfix)
{
	int len = strlen(indata);

	// now transform the infix into postfix
	Stack<char> stack = Stack<char>();

	int out = 0;
	for(int i = 0; i < len; i++)
	{
		char token = indata[i];
		cout << "Token " << token << endl;
		Priority p = Priority();
		if(token == '#'){
			// '#' 인 경우는 마침
			break;
		}else if(token == ')'){
			// ')' 인 경우는 ( 이 나올 때 까지 postfix에 입력후 pop
			while(true){
				char top = stack.Top();
				if(top != '('){
					postfix[out++] = top;
					stack.Pop();
				}else{
					stack.Pop();
					break;
				}
			}
		}else{
			// '#', ')' 이 아닌 모든 경우
			int icp = p.ICP(token);
			// 숫자인 경우 postfix 입력
			if(icp == 0){
				postfix[out++] = token;
			}else{
				// 연산자 우선순위에 따라서 push 하거나 같은 순위일경우는 pop
				while(1){
					if(stack.IsEmpty()) break;

					char top = stack.Top();
					int isp = p.ISP(top);
					if(icp >= isp){
						postfix[out++] = top;
						stack.Pop();
					}else
						break;
				}
				stack.Push(token);
			}
		}
		stack.Show();
	}

	while(!stack.IsEmpty()){
		char top = stack.Top();
		postfix[out++] = top;
		stack.Pop();
	}

	postfix[out] = 0;
}



// Template Class int, double Type Use
template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
