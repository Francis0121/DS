#include "lab005.h"

int main()
{
	CircularList<int> cirl;	// a circular list object with int data type

	while(1)
	{
		cerr << "CirL > " << endl;
		string command;
		cin >> command;
		if(command.compare("quit") == 0)
			break;	// stop the program
		if(command.compare("ins") == 0)
		{	// insert command
			int item;
			cin >> item;
			cout << "CMD : ins " << item << endl;

			cirl.InsertFront(item);
		}
		else if(command.compare("del") == 0)
		{
			int item;
			cin >> item;
			cout << "CMD : del " << item << endl;
			if(cirl.Delete(item) == false)
				cout << "Cannot delete item " << item << endl;
		}


		// show the current list
		cirl.Show();

		// show the number of elements in the list
		cout << "List has " << cirl.Size() << " elements" << endl << endl;
	}

	return 1;
}
