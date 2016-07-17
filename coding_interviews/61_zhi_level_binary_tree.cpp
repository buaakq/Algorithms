#include <iostream>
#include <vector>
#include <stack>
#include "../lib/binary_tree/binary_tree.h"

using namespace std;

vector<vector<int>> zigzagLevelOrder(BTreeNode *root)
{
	vector<vector<int>> ret;
	vector<int> line;

	if(root == nullptr)
		return ret;

	stack<BTreeNode *> s[2];
	int i = 0;
	s[i].push(root);

	bool zig = true;

	while(s[0].size() || s[1].size())
	{
		BTreeNode * top = s[i].top();
		s[i].pop();
		
		line.push_back(top->val);
		BTreeNode *first = zig ? top->left : top->right;
		BTreeNode *second = zig ? top->right : top->left;

		if(first){
			s[1-i].push(first);
		}
		if (second){
			s[1-i].push(second);
		}

		if(s[i].size() ==  0){
			ret.push_back(line);
			line.clear();
			zig = !zig;
			i = 1 - i;
		}
	}
	return ret;
}

void print(const vector<vector<int>> &v)
{
	for (auto line : v)
		for(auto one : line)
			cout << one << " ";
		cout << endl;
	cout << endl;
}

int main()
{
	BTree tree = BTree();
	tree.add(1);
	tree.add(9);
	tree.add(7);
	tree.add(5);
	tree.add(2);
	tree.add(3);


	tree.level();
	cout << endl;
	vector<vector<int>> ret = zigzagLevelOrder(tree.get_root());
	print(ret);
}