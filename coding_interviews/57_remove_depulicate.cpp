#include <iostream>
#include "../lib/linked_list/linked_list.h"

using namespace std;

ListNode *deleteDuplicates(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* prev = nullptr;
	ListNode* node = head, *end;
	ListNode* next;

	while(node){
		next = node->next;
		bool need = false;
		if (next && next->val == node->val)
			need = true;
		if (need == false){
			prev = node;
			node = next;
		}
		else{
			end = node;
			while(end && end->val == node->val){
				end = end->next;
			}
			if(prev == nullptr)
				head = end;
			else
				prev->next = end;
			node = end;
		}
	}
	return head;
}

int main()
{
	LinkedList list = LinkedList({1,1,1,2,2,3,4,5,6,6,6,6,7,8,8,8,8});
	print_list(list.head);
	print_list(deleteDuplicates(list.head));
	return 0;
}