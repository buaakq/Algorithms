#include <iostream>
#include <vector>

using namespace std;

int bsearch(vector<int>& v, int target, int lo, int hi)
{
	while(lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (v[mid] == target)
			return mid;
		else if(v[mid] > target)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return -1;
}

int helper(const vector<int> &a, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (right == left + 1)
        return right;

    if(a[mid] > a[left])
        return helper(a, mid, right);
    else
        return helper(a, left, mid);
}

int min_rotate(const vector<int> &a)
{
    if (a.size() == 1)
        return 0;
    int ret = helper(a, 0, a.size() - 1);
    return ret;
}

int search(vector<int>& v, int target)
{
	int len = v.size();
	if (len == 0)
		return -1;
	int min_pos;
	if (v[0] <= v[len-1])
		return bsearch(v, target, 0, len-1);
	else{
		min_pos = min_rotate(v);
		if (target <= v[len-1])
			return bsearch(v, target, min_pos, len-1);
		else 
			return bsearch(v, target, 0, min_pos - 1);
	}
}

int search2(vector<int>& v, int target)
{
	int len = v.size();
	int lo = 0;
	int hi = len - 1;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (v[mid] == target)
			return mid;
		if (v[mid] >= v[lo])
		{
			if(target >= v[lo] && target < v[mid])
				hi = mid - 1;
			else
				lo = mid + 1;
			continue;
		}
		else if (v[mid] <= v[hi])
		{
			if (target < v[mid] || target >= v[lo])
				hi = mid - 1;
			else
				lo = mid + 1;
		}
	}
	return -1;
}


int main()
{
	vector<int> v1 = {1,2,3,4,5,6,7,8};
	vector<int> v2 = {5,1,3};
	cout << search2(v1, 1) << endl;
	cout << search2(v1, 2) << endl;
	cout << search2(v1, 3) << endl;
	cout << search2(v1, 4) << endl;
	cout << search2(v1, 5) << endl;
	cout << search2(v1, 6) << endl;

	cout << search2(v1, 10) << endl;

	cout << search2(v2, 5) << endl;
	cout << search2(v2, 2) << endl;
}








