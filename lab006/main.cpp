
#include "lab006.h"

int main()
{
	MinHeap<int> mheap(256);	// sorted list one

	while(1)
	{
		cerr << "MinHeap > ";
		string command;
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("pop") == 0)
		{
			mheap.Pop();
		}
		else if(command.compare("init") == 0)
		{
			int intarr[1024];
			int i = 1;
			int item;
			while(1)
			{
				cin >> item;
				if(item == -1)
					break;
				intarr[i++] = item;
			}
			mheap.Init(intarr, i - 1);
		}
		else if(command.compare("preorder") == 0)
		{
			int index;
			cin >> index;
			mheap.PreOrder(index);
			cout << endl;
		}

		// show the current list
		mheap.Show();
	}
	cerr << endl;

	return 1;
}

