#include <iostream>
#include <vector>
#include "../lib/binary_tree/binary_tree.h"

using namespace std;

void helper(BTreeNode * root, int val, vector<vector<int>> &ret, vector<int> &path)
{
	if (!root->left && !root->right)
		if (root->val == val){
			path.push_back(val);
			ret.push_back(path);
			path.pop_back();
			return ;
		}
		else{
			return ;
		}
	path.push_back(root->val);
	if (root->left)
		helper(root->left, val - root->val, ret, path);
	if (root->right)
		helper(root->right, val - root->val, ret, path);
	path.pop_back();
}

vector<vector<int>> find_all_path(BTreeNode * root, int val)
{
	vector<vector<int>> ret;
	vector<int> path;
	if (root == nullptr)
		return ret;
	helper(root, val, ret, path);
	return ret;
}

int main()
{
	int target = 121;

	BTree mytree;
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	mytree.add_vector(v);
	mytree.display();
	cout << endl;

	vector<vector<int>> paths = find_all_path(mytree.get_root(), target);
	for(auto i:paths)
		for(auto j:i)
			cout << j << " ";
		cout << endl;
	return 0;
}