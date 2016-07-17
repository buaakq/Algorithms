#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> subsets(vector<int> v)
{
	vector<vector<int>> ret = {{}};
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i ++)
	{
		int count = 1;
		while(i < v.size() - 1 && v[i+1] == v[i])
		{
				i ++;
				count ++;
		}
		int curr_len = ret.size();
		for (int j = 1; j <= count; j ++)
		{
			for (int k = 0; k < curr_len; k ++)
			{
				int times = j;
				vector<int> tmp = ret[k];
				while(times--)
				{
					tmp.push_back(v[i]);
				}
				ret.push_back(tmp);
			}
		}
	}
	return ret;
}

int main()
{
	vector<int> v = {0};
	vector<vector<int>> all = subsets(v);
	for (auto i:all)
	{
		for(auto j:i)
			cout << j << " ";
		cout << endl;
	}
}