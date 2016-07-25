#include <iostream>
#include <vector>

using namespace std;

int *help; 

int rev_pair2(vector<int> &v)
{
	int ret = 0;
	int len = v.size();
	for (int i = 1; i < len; i ++)
	{
		for (int j = i; j > 0; j --)
		{
			if (v[j] < v[j-1]){
				swap(v[j], v[j-1]);
				ret ++;
			}
		}
	}
	return ret;
}

void merge(vector<int> &v, int lo, int mid, int hi, int &ret)
{
	for(int i = lo; i <= hi; i ++)
		help[i] = v[i];
	int i = lo; 
	int j = mid+1;
	for (int k = lo; k <= hi; k ++)
	{
		if (i > mid) v[k] = help[j++];
		else if (j > hi)  v[k] = help[i++];
		else if (help[i] <= help[j]) v[k] = help[i++];
		else{
			v[k] = help[j++];
			ret += mid - i + 1;
		}
	}
}

void merge_sort(vector<int> &v, int lo, int hi, int &ret)
{
	if (lo >= hi)
		return ;
	int mid = lo + (hi-lo)/2;
	merge_sort(v, lo, mid, ret);
	merge_sort(v, mid+1, hi, ret);
	merge(v, lo, mid, hi, ret);
}

int rev_pair1(vector<int> &v)
{
	help = new int[v.size()];
	int ret = 0;
	merge_sort(v, 0, v.size()-1, ret);
	return ret;
}

int main()
{
	vector<int> v = {1,2,3,1,7,4,2,3,10,6,5,6};
	cout << rev_pair1(v) << endl;
	vector<int> v2 = {1,2,3,1,7,4,2,3,10,6,5,6};
	cout << rev_pair2(v2) << endl;

	return 0;
}