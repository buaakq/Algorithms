#include <iostream>
#include <vector>

using namespace std;

int searchForLeft(const vector<int>& v, int target, int lo, int hi)
{
	if (lo > hi)
		return -1;
	if (lo == hi)
		return v[lo] == target ? lo : -1;
	int mid = lo + (hi - lo) / 2;
	if (v[mid] == target)
	{
		if (mid == 0)
			return 0;
		if (v[mid-1] == target)
			return searchForLeft(v, target, lo, mid-1);
		if (v[mid-1] < target || mid == 0)
			return mid;
	}
	else if (v[mid] > target)
	{
		return searchForLeft(v, target, lo, mid-1);
	}
	else
	{
		return searchForLeft(v, target, mid+1, hi);
	}
}

int searchForRight(const vector<int>& v, int target, int lo, int hi)
{
	if (lo > hi){
		return -1;
	}
	if (lo == hi){
		return v[lo] == target ? lo : -1;
	}
	int mid = lo + (hi - lo) / 2;
	if (v[mid] == target)
	{
		if (mid == v.size()-1)
			return mid;
		if (v[mid+1] == target){
			return searchForRight(v, target, mid+1, hi);
		}
		if (v[mid+1] > target)
			return mid;
	}
	else if (v[mid] > target)
	{
		return searchForRight(v, target, lo, mid-1);
	}
	else
	{
		return searchForRight(v, target, mid+1, hi);
	}
}

vector<int> searchRange(vector<int>& v, int target)
{
	int len = v.size();
	if (len == 0)
		return {-1,-1};
	int right, left;
	left = searchForLeft(v, target, 0, len - 1);
	if (left != -1)
		right = searchForRight(v, target, left, len - 1);
	else 
		right = -1;
	return {left, right};
} 

int main()
{
	std::vector<int> v = {0,0,0,1,2,3};
	std::vector<int> ret = searchRange(v, 0);
	cout << ret[0] << " " << ret[1] << endl;
	return 0;
}