#include <iostream>
#include <vector>
#include <stack>
#include "../lib/linked_list/linked_list.h"

using namespace std;

void reverse_print(ListNode * head)
{
	if (head == NULL)
		return;
	stack<ListNode *> stack1;
	ListNode * curr = head;
	while(curr){
		stack1.push(curr);
		curr = curr->next;
	}
	while(stack1.size()){
		cout << stack1.top()->val << "->";
		stack1.pop();
	}
	cout << "NULL" << endl;
}

void reverse_print_recursive(ListNode *head)
{
	if (head == NULL){
		//cout << "NULL" << endl;
		return;
	}
	reverse_print_recursive(head->next);
	cout << head->val << "->";
}

int main()
{
	vector<int> v1 = {1,2,3,4,5,6};
	LinkedList list1(v1);
	print_list(list1.head);
	reverse_print(list1.head);
	reverse_print_recursive(list1.head);

	cout << endl;

	return 0;
}