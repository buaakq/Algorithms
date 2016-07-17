#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool is_pop_order(const vector<int> &v1, const std::vector<int> &v2)
{
	if (v1.size() != v2.size())
		return false;
	if (v1.size() == 0)
		return true;
	int len = v1.size();
	stack<int> s;
	int i = 0, j = 0;
	while(i < len && j < len)
	{
		if (i < len){
			s.push(v1[i]);
			i ++;
		}
		while(s.empty() == false && j < len && s.top() == v2[j])
		{
			s.pop();
			j ++;
		}
	}
	return i == j;
}

int main()
{
	vector<int> v1 = {1};
	vector<int> v2 = {2};
	cout << is_pop_order(v1, v2) << endl;
}