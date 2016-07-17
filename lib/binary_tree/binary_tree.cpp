#include "binary_tree.h"
#include <memory>
#include <iostream>
#include <deque>
#include <stack>
#include <stdlib.h>

using namespace std;


void BTree::add(int val){
	add_helper(root, val);
}

void BTree::level()
{
	level_helper(root);
}

void BTree::level_helper(BTreeNode * node)
{
	deque<BTreeNode *> nodes_dq;
	if (node == nullptr)
		return;
	nodes_dq.push_back(node);
	
	while(nodes_dq.size())
	{
		auto begin = nodes_dq.front();
		nodes_dq.pop_front();

		cout << begin->val << " ";
		
		if (begin->left)
			nodes_dq.push_back(begin->left);
		if (begin->right)
			nodes_dq.push_back(begin->right);
	}
}

void BTree::preorder(bool re)
{
	if(re)
		preorder_helper(root);
	else
		preorder_helper_nonin(root);
}

void BTree::preorder_helper(BTreeNode * node)
{
	if (node == nullptr)
		return;
	cout << node->val << " ";
	preorder_helper(node->left);
	preorder_helper(node->right);
}

void BTree::inorder(bool re)
{
	if(re)
		inorder_helper(root);
	else
		inorder_helper_nonin(root);
}

void BTree::inorder_helper(BTreeNode * node)
{
	if (node == nullptr)
		return;
	inorder_helper(node->left);
	cout << node->val << " ";
	inorder_helper(node->right);
}

void BTree::posorder(bool re)
{
	if (re)
		posorder_helper(root);
	else
		posorder_helper_nonin(root);
}

void BTree::posorder_helper(BTreeNode * node)
{
	if (node == nullptr)
		return;
	posorder_helper(node->left);
	posorder_helper(node->right);
	cout << node->val << " ";
}

void BTree::add_helper(BTreeNode *&sub_root, int val)
{
	if(sub_root == nullptr)
	{
		BTreeNode * node = new BTreeNode(val);
		sub_root = node;
		return;
	}
	else
	{
		if (height_helper(sub_root->left) > height_helper(sub_root->right))
			add_helper(sub_root->right, val);
		else 
			add_helper(sub_root->left, val);
	}
}

int BTree::height_helper(BTreeNode * node)
{
	if(node == nullptr)  
        return 0;  
    else  
        return 1 + max(height_helper(node->left), height_helper(node->right));
}

void BTree::preorder_helper_nonin(BTreeNode * node)
{
	stack<BTreeNode *> nodes_stack;
	if(node == nullptr)
		return ;
	nodes_stack.push(node);
	while(nodes_stack.empty() != true)
	{
		BTreeNode * top = nodes_stack.top();
		cout << top->val << " ";
		nodes_stack.pop();
		if (top->right) nodes_stack.push(top->right);
		if (top->left) nodes_stack.push(top->left);
	}
}

void BTree::inorder_helper_nonin(BTreeNode * node)
{
	stack<BTreeNode *> nodes_stack;
	if(node == nullptr)
		return;
	//nodes_stack.push(node);

	while(node || nodes_stack.empty() != 1)
	{
		while(node)
		{
			nodes_stack.push(node);
			node = node->left;
		}
		if(!nodes_stack.empty())
		{
			node = nodes_stack.top();
			cout << node->val << " ";
			nodes_stack.pop();
			node = node->right;
		}
	}
}

void BTree::posorder_helper_nonin(BTreeNode * node)
{
	if(!node) 
		return;
	stack<pair<BTreeNode *, bool> > s;
	BTreeNode *cur;
	bool unUsed;

	s.push(make_pair(node, 1));

	while(!s.empty())
	{
		cur = s.top().first;
		unUsed=s.top().second;
		s.pop();
		if(unUsed)
		{
			s.push(make_pair(cur, 0));
			if(cur->right)
				s.push(make_pair(cur->right, 1));
			if(cur->left)
				s.push(make_pair(cur->left, 1));
		}
		else 
			cout << cur->val << " ";
	}
}

void BTree::display()
{
	display_helper(root);
}

void BTree::display_helper(BTreeNode * node)
{
	if (node)
	{
		cout << node->val;
		if (node->left || node->right){
			cout << '(';
			display_helper(node->left);
			cout << ',';
			display_helper(node->right);
			cout << ')';
		}
		
	}
	else
		cout << "#";
}

string BTree::serialise(){
	return serialise_helper2(root);
}


string BTree::serialise_helper(BTreeNode * node){
	if (node == nullptr)
		return "#";
	char str[10];
	sprintf(str, "%d", node->val);
	string node_val(str);

	string ret = node_val + "{" + serialise_helper(node->left) + "," + serialise_helper(node->right) + "}";
	return ret;
}

string BTree::serialise_helper2(BTreeNode * node){
	if (node == nullptr)
		return "#";
	char str[10];
	sprintf(str, "%d", node->val);
	string node_val(str);

	string ret = node_val + "," + serialise_helper2(node->left) + "," + serialise_helper2(node->right);
	//ret += ",";
	return ret;
}

BTreeNode * deserialise(string &str)
{
	if (str[0] == '#'){
		if (str.size() > 1)
			str = str.substr(2);
		return nullptr;
	}
	//cout << str[0] << endl;
	
	int pos = str.find(',');
	string tmp;
	if (pos != string::npos)
		tmp = str.substr(0, pos);
	else
		tmp = str;
	
	const char *cs = tmp.c_str();
	int node_val = atoi(cs);
	
	string temp = str.substr(pos+1);
	str = temp;

	BTreeNode * node = new BTreeNode(node_val);
	node->left = deserialise(str);
	node->right = deserialise(str);

	return node;
}