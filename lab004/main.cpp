// Lab 004


#include "lab004.h"
template class Queue<char>;

int main()
{
	Queue<char> q(7);

	while(1)
	{
		cerr << "Que > " << endl;
		string command;
		cin >> command;
		if(command.compare("quit") == 0)
			break;

		cout << endl << command << " ";
		try {
			if(command.compare("push") == 0)
			{
				char item;
				cin >> item;
				cout << item << endl;
				if(q.IsFull())
					throw "Queue is Full";

				q.Push(item);
			}
			else if(command.compare("pop") == 0)
			{
				cout << endl;
				if(q.IsEmpty()) throw "Queue is empty. Cannot delete";
				q.Pop();
			}
		} catch (const char *e) {
			cout << "Error " << e << endl;
		}
		q.Show();
		q.Internal();

	}

	return 1;
}


