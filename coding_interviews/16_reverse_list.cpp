#include <iostream>
#include <vector>
#include "../lib/linked_list/linked_list.h"

using namespace std;

ListNode* reverse(ListNode * head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode * prev = nullptr, *curr = head, *next;
	ListNode *new_head;
	while(curr)
	{
		next = curr->next;
		if (next == nullptr)
			new_head = curr;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return new_head;
}

int main()
{
	vector<int> vals = {0,1};
	LinkedList list1 = LinkedList(vals);
	//list1.make_cycle(2);
	ListNode * new_head = reverse(list1.head);
	print_list(new_head);
}