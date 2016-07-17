#include <iostream>
#include <vector>
#include "../lib/binary_tree/binary_tree.h"
#include <deque>

void print(std::vector<int> v)
{
	for(int i : v)
		cout << i << " ";
	cout << endl;
}

vector<int> level_display(BTreeNode * root)
{
	std::vector<int> ret;
	if (root == nullptr)
		return ret;
	deque<BTreeNode *> dq;
	dq.push_back(root);
	while(!dq.empty())
	{
		BTreeNode * curr = dq.front();
		dq.pop_front();
		ret.push_back(curr->val);
		if (curr->left)
			dq.push_back(curr->left);
		if (curr->right)
			dq.push_back(curr->right);
	}
	return ret;
}

int main()
{
	BTree tree;
	tree.add_vector({1,2,3,4,5,6,7,8,9,10});
	vector<int> ret = level_display(tree.get_root());
	print(ret);
}