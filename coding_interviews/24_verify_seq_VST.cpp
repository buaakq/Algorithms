#include <iostream>
#include <vector>

using namespace std;

bool verify_post_core(const vector<int> &v, int lo, int hi)
{
	if (hi - lo <= 1)
		return true;
	//bool ret = false;
	int last = v[hi];
	int i = lo; 
	for (; i <= hi - 1; i ++){
		if (v[i] > last)
			break;
	}
	for (int j = i; j <= hi - 1; j ++){
		if (v[j] < last)
			return false;
	}
	return verify_post_core(v, lo, i-1) && verify_post_core(v, i,hi-1);
}

bool verify_post(const vector<int> &v)
{
	int len = v.size();
	if (len == 0)
		return false;
	return verify_post_core(v, 0, len - 1);
}

bool verify_pre_core(const vector<int> &v, int lo, int hi)
{
	if (hi - lo <= 1)
		return true;
	//bool ret = false;
	int last = v[lo];
	int i = lo + 1; 
	for (; i <= hi; i ++){
		if (v[i] > last)
			break;
	}
	for (int j = i; j <= hi; j ++){
		if (v[j] < last)
			return false;
	}
	return verify_pre_core(v, lo+1, i-1) && verify_post_core(v, i,hi);
}

bool verify_pre(const vector<int> &v)
{
	int len = v.size();
	if (len == 0)
		return false;
	return verify_pre_core(v, 0, len - 1);
}

int main()
{
	vector<int> post_seq = {1,4,3,8,5,11,13,12,10};
	bool is = verify_post(post_seq);
	cout << is << endl;
	
	vector<int> pre_seq = {10,5,3,1,4,8,12,11,13};
	is = verify_pre(pre_seq);
	cout << is << endl;
}