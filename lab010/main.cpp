#include "lab010.h"


int main()
{
	HeapSort<int> hsort(256);	// heap sort instance

	while(1)
	{
		cerr << "HeapSort > ";
		string command;
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("i") == 0)
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
			hsort.Init(intarr, i - 1);
			hsort.Show();

			hsort.Heapify();
			hsort.Show();
		}
	}
	cerr << endl;

	return 1;
}


