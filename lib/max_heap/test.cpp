#include "max_heap.h"
#include <iostream>

using namespace std;

int main()
{
	MaxHeap h(100);
	h.insert(1);
	h.insert(3);
	h.insert(5);
	h.insert(4);
	cout << h.getMax() << endl;
	h.delMax();
	cout << h.getMax() << endl;

	return 0;
}