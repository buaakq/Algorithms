#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> v, int lo, int hi)
{
	int i = lo;
	int j = hi + 1;
	int var = v[i];
	while(1)
	{
		while(v[++i] <= var) if (i == hi) break;
		while(v[--j] >= var) if (j == lo) break;
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
	}
	swap(v[lo], v[j]);
	return j;
}

int more_than_half(vector<int> v)
{
	int len = v.size();
	if (len <= 0)
	{
		cout << "Invalid Input" << endl;
		return 0;
	}
	int lo = 0;
	int hi = len - 1;
	int mid = len / 2;
	int j = 0;
	while(j != mid)
	{
		j = partition(v, lo, hi);
		if (j > mid)
		{
			hi = j-1;
		}
		else if(j < mid)
		{
			lo = j + 1;
		}
	}
	// check?
	return v[j];
}

int main()
{
	vector<int> v = {1,3,3,3,3,3,3,3,4,5,6};
	cout << more_than_half(v) << endl;
	return 0;
}