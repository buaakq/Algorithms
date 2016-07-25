#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> v, int lo, int hi)
{
	int var = v[lo];
	int i = lo;
	int j = hi+1;
	while(1)
	{
		while(v[++i] <= var) if (i==hi) break;
		while(v[--j] >= var) if (j==lo) break;
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
	}
	swap(v[lo], v[j]);
	return j;
}

vector<int> small_k_nums(std::vector<int> v, int k)
{
	vector<int> ret;
	if (v.size()==0 || k > v.size() || k <= 0)
		return ret;
	int j = 0;
	int lo = 0;
	int hi = v.size() - 1;
	while(j != k-1)
	{
		 j = partition(v, lo, hi);
		 if (j > k - 1)
		 {
		 	hi = j - 1;
		 }
		 else if(j < k - 1)
		 {
		 	lo = j + 1;
		 }
	}
	ret.insert(ret.end(), v.begin(), v.begin()+k);
	return ret;
}

int max_k(std::vector<int> v, int k)
{
	if (v.size()==0 || k > v.size() || k <= 0)
		return 0;
	int lo = 0;
	int hi = v.size() - 1;
	int j = partition(v, lo, hi);
	while(j != v.size() - k)
	{
		j = partition(v, lo, hi);
		if (j > v.size() - k)
		{
			hi = j - 1;
		}
		else if (j < v.size() - k)
		{
			lo = j + 1;
		}
	}
	return v[j];
}

int main()
{
	int k = 3;
	vector<int> v = {-1,2,-10, 4, 5, 10};
	vector<int> ret = small_k_nums(v, 3);
	cout << max_k(v, 3) << endl;
	for (auto i:ret)
	{
			cout << i <<" ";
	}
	cout << endl;
}