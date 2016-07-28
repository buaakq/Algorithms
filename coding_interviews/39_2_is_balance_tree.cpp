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

int helper(BTreeNode *node, bool &flag)
{
	if(node == nullptr)
		return 0;
	int left = helper(node->left, flag);
	int right = helper(node->right, flag);

	int diff = left - right;
	if (diff > 1 || diff < -1)
		flag = 0;

	return max(left, right) + 1;
}

bool is_balance_tree(BTreeNode *node)
{
	bool dep = 1;
	int ret = helper(node, dep);
	return dep;
}

int main(int argc, char const *argv[])
{
	BTree tree1;
	tree1.add_vector({1,2,3,4,5,6,7,8,9});

	cout << is_balance_tree(tree1.get_root()) << endl;

	return 0;
}