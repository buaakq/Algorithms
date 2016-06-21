#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int> &v)
{
	for(auto i : v)
		cout << " " << i;
	cout << endl;
}

void swap(std::vector<int> &v, const int i, const int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void choose_sort(std::vector<int> &v)
{
	int len = v.size();
	for (int i = 0; i <= len - 2; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (v[min] > v[j])
				min = j;
		}
		swap(v, i, min);
	}
}

int main()
{
	vector<int> v = {2,4,1,3,5};
	choose_sort(v);
	print(v);
}