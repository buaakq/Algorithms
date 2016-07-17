#include <iostream>
#include "../lib/binary_tree/binary_tree.h"
#include <queue>

using namespace std;

void mirror(BTreeNode * root)
{
	if(root == nullptr)
		return;
	BTreeNode * tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	mirror(root->left);
	mirror(root->right);
}

// do not use recursion
void mirror2(BTreeNode * root)
{
	if (!root)
		return;
	queue<BTreeNode *> q;
	q.push(root);
	BTreeNode * tmp = nullptr;
	while(!q.empty())
	{
		BTreeNode * node = q.front();
		q.pop();
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
		BTreeNode * tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}
}


int main()
{
	BTree tree;
	
	tree.add_vector({1,2,3,4,5,6,7,8});
	tree.display();
	cout << endl;
	
	mirror2(tree.get_root());
	tree.display();
	cout << endl;
	return 0;

}