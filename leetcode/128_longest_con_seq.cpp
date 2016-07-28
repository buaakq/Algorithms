#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>


using namespace std;

int seq(const vector<int> &v)
{
	if (v.size() == 0)
		return 0;
	int longest = 1;
	unordered_map<int, bool> used;
	for(auto i : v)
	{
		used[i] = false;
	}
	for (auto i : v)
	{
		int len = 1;
		if (used[i])
			continue;
		used[i] = true;

		for (int j = i + 1; used.find(j) != used.end(); j ++)
		{
			len ++;
			used[j] = true;
		}

		for (int j = i - 1; used.find(j) != used.end(); j --)
		{
			len ++;
			used[j] = true;
		}

		longest = max(len, longest);
	}
	return longest;
}

int main()
{
	vector<int> v = {2,3,5,4,8,10,11,15,7,1,6,6,6,6,6};
	cout << seq(v) << endl;
}