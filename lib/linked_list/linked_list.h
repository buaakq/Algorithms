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
	void make_cycle(int entry);
	ListNode * head = nullptr;
};

void LinkedList::make_cycle(int e)
{
	ListNode *entry = this->head;
	ListNode *tail = this->head;
	while(tail->next)
	{
		tail = tail->next;
	}
	for (int i = 1; i <= e; i ++)
	{
		entry = entry->next;
	}

	tail->next = entry;
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