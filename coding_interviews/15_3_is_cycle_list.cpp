#include <iostream>
#include <vector>
#include "../lib/linked_list/linked_list.h"

using namespace std;

bool is_cycle(ListNode * head)
{
	if (head == nullptr || head->next == nullptr)
		return false;
	ListNode * fast = head;
	ListNode * slow = head;

	fast = fast->next->next;
	slow = slow->next;

	while(fast)
	{
		if (fast == slow)
			return true;
		if (fast->next == nullptr)
			return false;
		else{
			fast = fast->next->next;
			slow = slow->next;
		}
	}
	return false;
}

int main()
{
	vector<int> vals = {0,1,2,3,4,5,6,7};
	LinkedList list1 = LinkedList(vals);
	//list1.make_cycle(2);
	cout << (is_cycle(list1.head)) << endl;
}