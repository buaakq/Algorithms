#include <memory.h>
#include <iostream>
using namespace std;

class Bitmap
{
private:
	char * map;
	int size;
public:
	Bitmap(int n = 1);
	void set(int i);
	void clear(int i);
	bool test(int i) const;
	void print();
};

Bitmap::Bitmap(int n)
{
	size = (n + 7) / 8;
	map = new char[size];
	memset(map, 0, size);
}

void Bitmap::set(int i)
{
	int pos = i >> 3;
	int num = i - pos * 8;
	map[pos] |= 1 << (7-num);
}

void Bitmap::clear(int i)
{
	int pos = i >> 3;
	int num = i - pos * 8;
	map[pos] &= ~(1 << (7-num));
}

bool Bitmap::test(int i) const
{
	int pos = i >> 3;
	int num = i - pos * 8;
	return map[pos] & (1 << (7-num));
}

void Bitmap::print()
{
	for (int i = 0; i < size ; i ++)
		for(int j = 0; j < 8; j ++){
			bool ret = 0;
			ret = map[i] & (0x80 >> j);
			cout << ret;
		}
	cout << endl;
}