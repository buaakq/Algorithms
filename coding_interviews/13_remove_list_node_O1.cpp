#include "../lib/linked_list/linked_list.h"
#include <iostream>

using namespace std;

void remove_node(ListNode ** head, ListNode * node)
{
	if (head == nullptr || *head == nullptr || node == nullptr)
		return ;
	if (node->next){
		ListNode * to_be_delete = node->next;
		node->val = node->next->val;
		node->next = node->next->next;
		//cout << node->val << endl;
		//cout << node->next->val << endl;
		delete to_be_delete;
	}
	else if(*head == node){
		delete node;
		node = nullptr;
		*head = nullptr;
	}
	else{
		ListNode * prev = *head;
		while(prev->next != node)
			prev = prev->next;
		prev->next = nullptr;
		delete node;
	}
}

int main()
{
	LinkedList list1({1,2});
	print_list(list1.head);
	remove_node(&(list1.head), (list1.head)->next);
	print_list(list1.head);
	return 0;
}