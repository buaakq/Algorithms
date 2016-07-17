#include <iostream>
#include <vector>

using namespace std;

void update(int &ret1, int &ret2, int temp)
{
	if (temp > ret1){
		ret2 = ret1;
		ret1 = temp;
		return ;
	}
	if (temp > ret2){
		ret2 = temp;
		return;
	}
}

int maxProfit(vector<int>& v) {
    int len = v.size();
	if (len <= 1)
		return 0;
	int lo = 0;
	int hi = 0;
	int ret1 = 0;
	int ret2 = 0;

	while(1)
	{
		int temp = 0;
		if (hi == len-1)
		{
			temp = v[hi] - v[lo];
			update(ret1, ret2, temp);
			break;
		}
		if (v[hi + 1] >= v[hi])
		{
			hi ++;
		}
		else
		{
			temp = v[hi] - v[lo];
			update(ret1, ret2, temp);
			hi ++;
			lo = hi;
		}
	}
	return ret1 + ret2;
 }

int main()
{
	vector<int> v = {2,4,5,8,6};
	cout << maxProfit(v) << endl;
}