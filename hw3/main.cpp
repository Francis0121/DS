#include "hw3.h"


int main()
{
	QuickSort<int> qs;	// quick sort instance

	while(1)
	{
		cerr << "QuickSort > ";
		char command[256];
		cin >> command;

		if(strcmp (command, "quit") == 0)
			break;
		else if(strcmp (command, "i") == 0)
		{
			int intarr[1024];
			int i = 0;
			int item;
			while(1)
			{
				cin >> item;
				if(item == -1)
					break;
				intarr[i++] = item;
			}
			qs.Init(intarr, i);
			cout << "New Data Set" << endl;
			qs.Show(0, i - 1);
		}
		else if(strcmp (command, "qs") == 0)
		{
			cout << "quick sort started" << endl;
			qs.Sort();
		}
	}
	cerr << endl;

	return 1;
}
