#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(std::vector<int> v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}

vector<vector<int>> for_sum(vector<int> &v, int tar)
{
	vector<vector<int>> ret;
	int len = v.size();
	if (len < 4)
		return ret;
	sort(v.begin(), v.end());
	print(v);
	for(int i = 0; i <= len - 4; i ++)
	{
		cout << "out loop i = " << i << endl;
		if (i > 0 && v[i] == v[i-1])
			continue;
		int max_sum = v[i] + v[len-1] + v[len-2] + v[len-3];
		int min_sum = v[i] + v[i+1] + v[i+2] + v[i+3];
		if (max_sum < tar)
			continue;
		if (min_sum > tar)
			break;
		for(int j = i+1; j <= len-3; j ++)
		{
			cout << "	2nd loop, j = " << j << endl;
			if (j > i + 1 && v[j] == v[j-1])
				continue;
			if (v[i] + v[j] + v[len-1] + v[len-2] < tar)
				continue;
			if (v[i] + v[j] + v[j+1] + v[j+2] > tar)
				break;
			int lo = j + 1;
			int hi = len - 1;
			while(lo < hi)
			{
				cout << "		lo = " << lo <<"    hi = " << hi << endl;
				int sum = v[i] + v[j] + v[lo] + v[hi];
				if (sum == tar)
				{
					ret.push_back({v[i], v[j], v[lo], v[hi]});
					while(lo < hi - 1 && v[lo] == v[lo+1]) lo++;
					while(lo < hi - 1 && v[hi] == v[hi-1]) hi--;
					lo++;
					hi--;
				}
				else if(sum < tar){
					lo ++;
				}
				else{
					hi --;
				}
			}

		}
	}
	return ret;
}

int main()
{
	vector<int> num = {-3,-2,-1,0,0,1,2,3};
	vector<vector<int>> ret = for_sum(num, 0);
	for (auto i : ret)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
}