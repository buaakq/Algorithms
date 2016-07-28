#include <iostream>
#include <vector>

using namespace std;

int times(const vector<int> &v, const int k)
{
	int len = v.size();
	if (len == 0)
		return 0;
	int lo = 0; int hi = len-1;
	int mid;

	int left = -1, right = -1;

	while(lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		int var = v[mid];
		if (var < k)
		{
			lo = mid + 1;
		}
		else if(var > k)
		{
			hi = mid - 1;
		}
		else
		{
			if (mid == 0 || v[mid-1] != k)
			{
				left = mid;
				break;
			}
			else
			{
				hi = mid - 1;
			}
		}
	}

	if (left == -1)
		return 0;

	lo = 0;
	hi = len - 1;
	while(lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		int var = v[mid];
		if (var < k)
		{
			lo = mid + 1;
		}
		else if(var > k)
		{
			hi = mid - 1;
		}
		else
		{
			if (mid == len-1 || v[mid+1] != k)
			{
				right = mid;
				break;
			}
			else
			{
				lo = mid + 1;
			}
		}
	}
	return right - left + 1;
}

int main()
{
	vector<int> v = {1,3,3,4,5,6,7,8,9,9,11,15};
	cout << times(v, 3) << endl;
	cout << times(v,9) << endl;
	cout << times(v, 10) << endl;

	return 0; 
}