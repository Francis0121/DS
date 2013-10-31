

#include "lab007.h"

int main()
{
	MaxLoserTree<int> ltree(256);	// Max Loser Tree with 256 elements

	while(1)
	{
		cerr << "MLT > ";
		string command;
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("mlt") == 0)
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
			ltree.BuildLoserTree(intarr, i);
		}

		// show the current loser tree array
		ltree.Show();
	}
	cerr << endl;

	return 1;
}

