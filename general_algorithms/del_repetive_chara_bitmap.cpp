#include "../lib/bitmap/bitmap.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	string foo = "therearesomerepetivecharacters";
	Bitmap char_map = Bitmap(128);
	for (int i = 0; i < foo.size(); i ++)
	{
		int pos = foo[i] - '0';
		char_map.set(pos);
		//cout << i <<" " ;
	}

	char_map.print();

	int index = 0;
	int i = 0;
	for (; i < 128; i ++)
	{
		if (char_map.test(i)){
			foo[index] = i + '0';
			index ++;
		}
	}
	foo.resize(index);
	cout << foo << endl;
}