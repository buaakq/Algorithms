#include "bitmap.h"
#include <iostream>

using namespace std;

int main()
{
	Bitmap map1 = Bitmap(100);
	map1.set(30);
	map1.set(50);
	map1.clear(30);
	cout << map1.test(10) << endl;
	cout << map1.test(30) << endl;
	cout << map1.test(50) << endl;

	return 0;
}