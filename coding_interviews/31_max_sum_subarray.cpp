#include <iostream>
#include <vector>

using namespace std;

int max_sum_subarray(const vector<int> v)
{
	int ret = 0x80000000;
	int curr = 0;
	int len = v.size();
	if (len == 0)
		return 0;
	for (int i = 0; i < len ; i ++)
	{
		if (curr < 0)
		{
			curr = 0;
			curr += v[i];
		}
		else
		{
			curr += v[i];
		}
		ret = max(ret, curr);
	}
	return ret;
}

int main()
{
	vector<int> v = {1, -2, 3, 10, -4, 7, 2, -5};
	cout << max_sum_subarray(v) << endl;
}