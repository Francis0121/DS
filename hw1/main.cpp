// HW1
// Name :
// Student ID :

#include "hw1.h"

int main()
{
	Stack<double> result;	
	while(1)
	{
		cerr << "Enter an infix expression" << endl;

		char infix[1024];
		int i = 0;
		while(1)
		{
			char c;
			cin >> c;
			if(c == '#')
				break;
			if(isspace(c))
				continue;
			infix[i++] = c;
		}
		infix[i] = 0;

		char postfix[1024];
		ToPostFix(infix, postfix);
		int len = strlen(postfix);
		cout << "Postfix expression : ";
		for(i = 0; i < len; i++)
			cout << postfix[i] << " ";
		cout << endl;

		double val = PostfixEval(postfix);
		cout << "Evaluation : " << val << endl;

		result.Push(val);	
		cerr << "Continue (y/n) " << endl;

		char ans;
		cin >> ans;

		if(ans == 'n')
			break;
		cout << endl;
	}

	cout << "The results are ";
	while(!result.IsEmpty())
	{
		cout << result.Top() << " ";
		result.Pop();
	}
	cout << endl;

	return 1;
}

