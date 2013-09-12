// Lab 002
// Name : Sunggeun Kim
// ID : 20093267

#include <iostream>
using namespace::std;

int Fib(int n)
{
	if(n == 0) return 0;

	if(n == 1 || n == 2){
		return 1;
	}else{
		return Fib(n-1) + Fib(n-2);
	}
}
	
int main(){
	int n;
	while(true){
		cerr << "Enter the number n : " << endl;
		cin >> n;
		if( n == -1 )
			break;
		cout << "Fib (" << n <<") = " << Fib(n) << endl;
	}
}
