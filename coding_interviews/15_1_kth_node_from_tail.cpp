#include <iostream>
#include <vector>
#include "../lib/linked_list/linked_list.h"

using namespace std;

ListNode * kth_form_tail(ListNode * head, int k)
{
	if (k <= 0)
		return nullptr;
	ListNode * fast = head;
	ListNode * slow = head;

	for (int i = 1; i <= k; i ++){
		if (fast == nullptr)
			return nullptr;
		fast = fast->next;
	}

	while(fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main()
{
	vector<int> vals = {0};
	LinkedList list1 = LinkedList(vals);
	cout << (kth_form_tail(list1.head, 2))->val << endl;
}