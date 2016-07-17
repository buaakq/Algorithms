#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(const vector<vector<int>>& v)
{ 
	int len = v.size();
	vector<int> ret = v.back();
	for (int level = len - 2; level >= 0; level --)
	{
		for (int col = 0; col <= level; col ++)
		{
			int target = min(ret[col], ret[col+1]);
			ret[col] = v[level][col] + target;
		}
	}
	return ret[0];
}

int main()
{
	vector<vector<int>>	t = {{2},{3,4},{6,5,7},{4,1,8,3}};
	cout << minimumTotal(t) << endl;
}