#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<vector<int>> &ret, vector<int>& v, vector<int> &path, int pos, int target);

vector<vector<int>> combinationSum(vector<int>& v, int target)
{
	vector<vector<int>> ret;
	int len = v.size();
	if (len == 0)
		return ret;
	vector<int> path = {};
	sort(v.begin(), v.end());
	helper(ret, v, path, 0, target);
	return ret;
}

void helper(vector<vector<int>> &ret, vector<int>& v, vector<int> &path, int pos, int target)
{
	if (target > 0)
	{
		for(int i = pos; i < v.size() && v[i] <= target; i ++)
		{
			path.push_back(v[i]);
			helper(ret, v, path, i + 1, target - v[i]);
			path.pop_back();
		}
	}
	else if (target == 0)
	{
		ret.push_back(path);
	}
}

int main()
{
	vector<int> v = {10, 1, 2, 7, 6, 1, 5};
	vector<vector<int>> ret = combinationSum(v, 7);
	for (auto i:ret)
	{
		for(auto j:i)
			cout << j << " ";
		cout << endl;
	}
}