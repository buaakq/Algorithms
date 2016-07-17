#include "../lib/binary_tree/binary_tree.h"
#include <iostream>
#include <vector>

using namespace std;

int find_val(const vector<int> &v, int val, int l, int r)
{
	cout << "searching for " << val << endl;
	for (int i = l; i <= r; i ++){
		if (v[i] == val){
			return i;
		}
	}
	cout << "cannot find val" << endl;
	return -1;
}

BTreeNode * helper
(const vector<int> &in, const vector<int> &post, int in_l, int in_r, int post_l, int post_r)
{
	if (in.size() == 0 || post.size() == 0)
		return nullptr;

	BTreeNode * curr;
	curr = new BTreeNode(post[post_r]);
	if(post_r == post_l)
		return curr;

	int in_pos = find_val(in, post[post_r], in_l, in_r);

	int left_len = in_pos - in_l - 1;
	int right_len = in_r - in_pos - 1;

	if (left_len >= 0)
		curr->left = helper(in, post, in_l, in_l + left_len, post_l, post_l + left_len);
	if (right_len >= 0)
		curr->right = helper(in, post, in_r - right_len, in_r, post_r - right_len - 1, post_r - 1);

	return curr;
}

BTreeNode * build_tree(const vector<int> &in, const vector<int> &post)
{
	return helper(in, post, 0, in.size() - 1, 0, post.size() - 1);
}

int main()
{
	std::vector<int> in = {7,4,2,6,1,5,3,8};
	std::vector<int> post = {7,4,6,2,5,8,3,1};

	BTreeNode * root = build_tree(in, post);

	BTree tree(root);
	tree.preorder(1);
	cout << endl;

	tree.inorder(1);
	cout << endl;

	tree.level();
	cout << endl;

	tree.display();
	cout << endl;

	return 0;
}