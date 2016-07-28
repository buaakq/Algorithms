#include "../lib/binary_tree/binary_tree.h"
#include <vector>
#include <iostream>

using namespace std;

int btree_depth(BTreeNode * node)
{
	if(node == nullptr)
		return 0;
	int left = btree_depth(node->left);
	int right = btree_depth(node->right);

	return max(left, right) + 1;
}


int main(int argc, char const *argv[])
{
	BTree tree1;
	tree1.add_vector({1,2,3,4,5,6,7,8,9});
	tree1.display();
	cout << endl;

	cout << tree1.height() << endl;
	//cout << endl;

	cout << btree_depth(tree1.get_root());
	cout << endl;

	return 0;
}