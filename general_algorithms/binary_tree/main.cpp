#include <iostream>
#include <algorithm>

#include "../../lib/binary_tree/binary_tree.h"


using namespace std;

int main()
{
	BTree bt;
	//bt.build_tree_pre_in(vector<int> pre, vector<int> in)
	//bt.display();

	bt.add(1);
	bt.add(2);
	bt.add(3);
	bt.add(4);
	bt.add(5);
	bt.add(7);
	bt.add(11);
	bt.add(15);
	bt.add(22);
	bt.add(40);

	cout << "pre order with recursion: " << endl;
	bt.preorder(1);
	cout << endl << endl;
	
	cout << "in order with recursion: "<< endl;
	bt.inorder(1);
	cout << endl<< endl;

	cout << "pos order with recursion: "<< endl;
	bt.posorder(1);
	cout << endl<< endl;

	cout << "level with queue: "<< endl;
	bt.level();
	cout << endl<< endl;

	cout << "pre order with stack: "<< endl;
	bt.preorder(0);
	cout << endl<< endl;

	cout << "in order with stack: "<< endl;
	bt.inorder(0);
	cout << endl<< endl;

	cout << "pos order with stack: "<< endl;
	bt.posorder(0);
	cout << endl<< endl;

	cout << "tree display:" << endl;
	bt.display();
	cout << endl << endl;

	return 0;
}
