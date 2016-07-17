#include <iostream>
#include <vector>
#include "../lib/linked_list/linked_list.h"

using namespace std;

ListNode* merge(ListNode * head1, ListNode * head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;

	ListNode *new_head;
	if (head1->val < head2->val){
		new_head = head1;
		new_head->next = merge(head1->next, head2);
	}
	else{
		new_head = head2;
		new_head->next = merge(head1, head2->next);
	}
	return new_head;
}

int main()
{
	LinkedList list1 = LinkedList({1,2,4,6,7,9});
	LinkedList list2 = LinkedList({3,4,8,11,15});
	//list1.make_cycle(2);
	ListNode * new_head = merge(list1.head, list2.head);
	print_list(new_head);
}