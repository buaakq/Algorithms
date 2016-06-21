#include <iostream>
#include <vector>

using namespace std;

int helper(const std::vector<int> v, int start, int end, int val);

int binary_search(const vector<int> v, int val)
{
	return helper(v, 0, v.size() - 1, val);
}

int helper(const std::vector<int> v, int start, int end, int val)
{
	if (start > end)
		return -1;
	int mid = start + (end - start) / 2;
	if (v[mid] == val)
		return mid;
	else if(v[mid] > val)
		return helper(v, start, mid-1, val);
	else
		return helper(v, mid+1, end, val);
}

int main()
{
	vector<int> v = {1,2,3,4,7,9,10,15,18,22};
	cout << binary_search(v, 3) << endl;
	cout << binary_search(v, 8) << endl;
	return 0;
}