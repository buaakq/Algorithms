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

void insert_sort(vector<int> &v)
{
	int len = v.size();
	for (int i = 1; i < len; i ++)
	{
		for (int j = i; j > 0; j --)
		{
			if (v[j] < v[j-1])
				swap(v, j, j-1);
			else
				break;
		}
	}
}

int main()
{
	vector<int> v = {2,4,1,3,5};
	insert_sort(v);
	print(v);
}