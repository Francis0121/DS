/**********
* 20093267
***********/
#include <iostream>
#include <cstring>

using namespace::std;

int main()
{
	while(1)
	{
		char command[256];
		cerr << "echo >";
		cin >> command;	
		if(strcmp(command, "quit") == 0) break;
		cout << command << " !!" <<endl;
	}	
}
