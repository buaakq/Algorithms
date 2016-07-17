#include "../lib/binary_tree/binary_tree.h"
#include <iostream>
#include <vector>

using namespace std;

int find_val(const vector<int> &v, int val, int l, int r)
{
	for (int i = l; i <= r; i ++){
		if (v[i] == val){
			return i;
		}
	}
	return -1;
}

BTreeNode * helper(const vector<int> &pre, const vector<int> &in, int pre_l, int pre_r, int in_l, int in_r)
{
	if (pre.size() == 0 || in.size() == 0)
		return nullptr;

	BTreeNode * curr;
	curr = new BTreeNode(pre[pre_l]);
	if(pre_l == pre_r)
		return curr;

	int in_pos = find_val(in, pre[pre_l], in_l, in_r);

	int left_len = in_pos - in_l;
	int right_len = in_r - in_pos;

	if (left_len > 0)
		curr->left = helper(pre, in, pre_l + 1, pre_l + left_len, 0, left_len - 1);
	if (right_len > 0)
		curr->right = helper(pre, in, pre_r - right_len + 1, pre_r, in_pos + 1, in_r);

	return curr;
}

BTreeNode * build_tree(const vector<int> &pre, const vector<int> &in)
{
	return helper(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
}

int main()
{
	std::vector<int> pre = {1,2,4,7,3,5,6,8};
	std::vector<int> in = {4,7,2,1,5,3,8,6};

	BTreeNode * root = build_tree(pre, in);

	BTree tree(root);
	tree.preorder(1);
	cout << endl;

	tree.inorder(1);
	cout << endl;

	tree.level();
	cout << endl;

	return 0;
}