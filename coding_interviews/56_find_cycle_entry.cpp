#include <iostream>
#include "../lib/linked_list/linked_list.h"

using namespace std;

ListNode *detectCycle(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
		return nullptr;
	bool cycle = false;
	ListNode *fast = head->next->next, *slow = head->next;
	while(fast && slow)
	{
		if (fast == slow){
			cycle = true;
			break;
		}
		slow = slow->next;
		if(fast->next)
			fast = fast->next->next;
		else
			return nullptr;
	}

	if (cycle == false)
		return nullptr;

	while (head != slow){
		head = head->next;
		slow = slow->next;
	}
	return slow;
}

int main()
{
	LinkedList list = LinkedList({1,2,3,4,5,6,7,8});
	list.make_cycle(3);
	cout << (detectCycle(list.head))->val << endl;

	LinkedList list2 = LinkedList({1,2,3,4,5,6,7,8});
	cout << (detectCycle(list2.head)) << endl;

}
