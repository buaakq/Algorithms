#include <iostream>
#include <vector>

using namespace std;

int maxProfit(const vector<int> &v)
{
	int len = v.size();
	if (len <= 1)
		return 0;
	int lo = 0;
	int hi = 0;
	int ret = 0;

	while(1)
	{
		if (hi == len-1)
		{
			ret += v[hi] - v[lo];
			break;
		}
		if (v[hi + 1] >= v[hi])
		{
			hi ++;
		}
		else
		{
			ret += v[hi] - v[lo];
			hi ++;
			lo = hi;
		}
	}
	return ret;

}

int main()
{
	vector<int> v = {2,4,5,8,10,3,5,9,2};
	cout << maxProfit(v) << endl;
}