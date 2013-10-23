#include "hw2.h"

int main()
{
	BSTree<Item> bst;	
	// a binary search tree of type Item

	while(1)
	{
		cerr << "BSTree > ";
		string command;
		cin >> command;

		cout << command << " ";
		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("ins") == 0)
		{
			int key, val;
			cin >> key >> val;
			cout << key << " " << val;
			if(bst.Insert(Item(key, val)) == false)
				cout << endl << "Existing Key";
		}
		else if(command.compare("del") == 0)
		{
			int key;
			cin >> key;
			cout << key ;
			if(bst.Delete(Item(key)) == false)
				cout << endl << "Cannot Delete, Non Existing Key";
		}
		else if(command.compare("get") == 0)
		{
			int key;
			cin >> key;
			cout << key ;
			Item p = bst.Get(Item(key));
			if(p.key == -1)
				cout << "Cannot Get, Non Existing Key" << endl;
			else
				cout << endl << "Item " << p.key << " " << p.value;
		}
		cout << endl;

		// show the current binary search tree
		bst.Show();
		cout << endl;
	}
	cerr << endl;

	return 1;
}

