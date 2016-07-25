#include <iostream>
#include <vector>

using namespace std;

char first_once(string s)
{
	int table[256];
	for (auto c : table)
		c = 0;
	unsigned int index = 0;
	for (auto c : s)
	{
		unsigned char uchar = (unsigned char) c;
		index = (unsigned int) uchar;

		table[index] ++;
	}
	for (auto c : s)
	{
		unsigned char uchar = (unsigned char) c;
		index = (unsigned int) uchar;

		if (table[index] == 1)
			return c;
	}
	return '\0';
}

int main(int argc, char const *argv[])
{
	string s = "abcdabcdeabcd";
	cout << first_once(s) << endl;
	return 0;
}