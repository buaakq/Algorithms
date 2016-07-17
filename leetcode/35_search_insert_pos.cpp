#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& v, int target)
{
	int len = v.size();
	if (len == 0)
		return 0;
	if (v[0] >= target)
		return 0;
	if (v[len-1] < target)
		return len;
	int lo = 0, hi = len-1;
	int mid;
	while(lo < hi)
	{
		mid = lo + (hi - lo) / 2;
		if (v[mid] > target){
			hi = mid - 1;
		}
		else if (v[mid] == target)
		{
			lo = mid;
			break;
		}
		else{
			lo = mid + 1;
		}
	}
	if (v[lo] == target)
		return lo;
	else if(v[lo] > target)
		return lo;
	else
		return lo + 1;
}

int main()
{
	vector<int> v = {1,2,4,6,7};
	cout << searchInsert(v, 3) << endl;
	cout << searchInsert(v, 2) << endl;
	cout << searchInsert(v, 7) << endl;
	cout << searchInsert(v, 0) << endl;
}