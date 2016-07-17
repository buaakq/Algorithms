#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(string &s, int lo, int hi)
{
	char tmp = s[lo];
	s[lo] = s[hi];
	s[hi] = tmp;
}

void helper(string s, int lo, int hi, vector<string> &v)
{
	string s2 = s;
	if (lo == hi)
		v.push_back(s2);
	
	for (int i = lo; i <= hi; i ++)
	{
		swap(s, lo, i);
		helper(s, lo + 1, hi, v);
		swap(s, lo, i);
	}
}

void permutation(string s, vector<string> &v)
{
	int lo = 0;
	int hi = s.size() - 1;
	helper(s, lo, hi, v);
}

int main()
{
	string s = "abc";
	vector<string> v;
	permutation(s, v);
	for (auto i:v)
		cout << i << endl;
	return 0;
}