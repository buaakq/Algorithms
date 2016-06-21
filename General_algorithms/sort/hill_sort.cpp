#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int> &v)
{
	for(auto i : v)
		cout << " " << i;
	cout << endl;
}

void swap(vector<int> &v, const int i, const int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void hill_sort(vector<int> &v, const int h)
{
	int len = v.size();
	for (int i = h; i < len; i ++)
	{
		for (int j = i; j >= h; j -= h)
		{
			if (v[j] < v[j-h])
				swap(v, j, j-h);
			else
				break;
		}
	}
}

int main()
{
	vector<int> v = {2,4,1,3,5,8,3,10,11,50,23,43,19,0,7,49,28};
	int len = v.size();
	int h = 1;
	while(h < len / 3)
		h = h * 3 + 1;
	while(h >= 1)
	{
		hill_sort(v, h);
		h /= 3;
	}
	
	print(v);
}