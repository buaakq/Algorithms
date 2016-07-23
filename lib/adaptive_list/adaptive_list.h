#include <vector>
#include <iostream>

class ListNode
{
public:
	ListNode(int data){val = data; next = nullptr;}

	int val;
	ListNode * next;
};

class LinkedList
{
public:
	LinkedList(){};
	~LinkedList(){};
	LinkedList(std::vector<int> v);

	int at(int a);
	void add(int a);

	ListNode * head = nullptr;
private:
	void move_to_head(ListNode *&head, ListNode *node);
};

int LinkedList::at(int a)
{
	int i = a;
	ListNode * curr = head;
	while(i && curr)
	{
		curr = curr->next;
		i --;
	}
	if (curr == nullptr)
	{
		std::cout << "Invalid Index, will return -1" << std::endl;
		return -1;
	}
	if (a != 0)
		move_to_head(head, curr);
	return curr->val;
}

void LinkedList::move_to_head(ListNode *&head, ListNode * node)
{
	ListNode * prev_head = head;
	//head = node;
	ListNode * index = prev_head;
	ListNode * prev = nullptr;
	while(index != node)
	{
		prev = index;
		index = index->next;
	}
	prev->next = prev->next->next;
	head = node;
	node->next = prev_head;
}

void LinkedList::add(int a)
{
	ListNode * prev_head = head;
	this->head = new ListNode(a);
	head->next = prev_head;
}

LinkedList::LinkedList(std::vector<int> v){
	ListNode *prev = nullptr;
	ListNode * curr;
	for (int i = 0; i < v.size(); i ++)
	{
		curr = new ListNode(v[i]);
		if (i == 0)
			head = curr;
		if (prev)
			prev->next = curr;
		prev = curr;
	}
	curr->next = nullptr;
};

void print_list(ListNode * head){
	while(head != nullptr){
		std::cout << head->val << "->";
		head = head->next;
	}
	std::cout << "NULL" << std::endl;
}


