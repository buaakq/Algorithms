#include <iostream>
#include "../lib/binary_tree/binary_tree.h"

using namespace std;

bool has_sub_tree(BTreeNode *head1, BTreeNode *head2)
{
	if (head2 == nullptr)
		return true;
	if (head1 == nullptr)
		return false;

	if (head1->val == head2->val)
		return has_sub_tree(head1->left, head2->left) && has_sub_tree(head1->right, head2->right);
	else
		return false;
}

bool is_sub_tree(BTreeNode *head1, BTreeNode *head2)
{
	if (head2 == nullptr)
		return true;
	if (head1 == nullptr)
		return false;
	bool has = has_sub_tree(head1, head2);
	if (!has)
		has = is_sub_tree(head1->left, head2);
	if (!has)
		has = is_sub_tree(head1->right, head2);
	return has;
}

int main(int argc, char const *argv[])
{
	BTree parent, child;
	parent.add(1);
	parent.add(2);
	parent.add(3);
	parent.add(4);
	parent.add(5);
	parent.add(6);
	parent.add(7);

	child.add(2);
	child.add(4);
	child.add(1);

	cout << is_sub_tree(parent.get_root(), child.get_root()) << endl;

	return 0;
}