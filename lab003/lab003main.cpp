// Lab 003
// Name : 김성근
// Student ID : 20093267

#include "lab003.h"

int main()
{
	while(1)
	{
		Polynomial a;
		Polynomial b;

		// form the Polynomial a
		a.InitPolynomial("a");
		cout << "a(0.5) = " << a.Eval(0.5) << endl;
		b.InitPolynomial("b");
		cout << "b(0.5) = " << b.Eval(0.5) << endl;
	
		Polynomial c;
		cout << "c = a + b" << endl;
		c = a.Add(b);
		cout << "c(2) = " << c.Eval(2) << endl;
	
		cout << endl;
		if(a == b)
			cout << "a and b ARE the same!" << endl;
		else
			cout << "a and b are NOT the same!" << endl;

		cerr << "Continue (y/n) " << endl;
		char ans;
		cin >> ans;
		if(ans == 'n')
			break;
	}

	return 1;
}


