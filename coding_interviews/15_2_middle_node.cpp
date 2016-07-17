#include <iostream>
#include <vector>
#include "../lib/linked_list/linked_list.h"

using namespace std;

ListNode * middle_node(ListNode * head)
{
	if (head == nullptr)
		return nullptr;
	ListNode * fast = head;
	ListNode * slow = head;

	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

int main()
{
	vector<int> vals = {0,1};
	LinkedList list1 = LinkedList(vals);
	cout << (middle_node(list1.head))->val << endl;
}