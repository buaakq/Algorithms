#include "adaptive_list.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	LinkedList list1({0,1,2,3,4,5,6,7,8});

	list1.add(9);
	cout << list1.at(3) << " "<<list1.at(4) << endl;
	cout << list1.at(10) << endl;
	cout <<list1.at(20) << endl;

	print_list(list1.head);

	return 0;
}