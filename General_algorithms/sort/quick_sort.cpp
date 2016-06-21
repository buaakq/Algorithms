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

int partition(std::vector<int> &v, int start, int end)
{
	int val = v[start];
	int i = start;
	int j = end + 1;
	while(1)
	{
		while(v[++i] < val)
		{
			if ( i == end)
				break;
		}
		while(v[--j] >= val)
		{
			if (j == start)
				break;
		}
		
		if(i >= j)
			break;
		swap(v, i, j);
		//i ++;
		//j --;
	}
	swap(v, start, j);
	return j;
}

void quick_sort(std::vector<int> &v, int start, int end)
{
	if(start >= end)
	{
		return;
	}
	int j = partition(v, start, end);
	quick_sort(v, start, j-1);
	quick_sort(v, j+1, end);
}

int main()
{
	vector<int> v = {2,4,1,3,5,8,3,10,11,50,23,43,19,0,7,49,28};
	quick_sort(v, 0, v.size() - 1);
	print(v);
}