#include <iostream>
#include "../lib/binary_tree/binary_tree.h"
#include <string>

using namespace std;

int main()
{
	BTree tree;
	tree.add(1);
	tree.add(2);
	tree.add(3);
	tree.add(4);
	tree.add(5);
	tree.add(7);
	tree.add(9);
	tree.add(11);
	tree.add(15);

	//display();
	tree.preorder(1);
	cout << endl;
	string s = tree.serialise();
	cout << s << endl;

	BTreeNode * node = deserialise(s);
	BTree tree2 = BTree(node);
	tree2.preorder(1);
	cout << endl;
	return 0;
}
