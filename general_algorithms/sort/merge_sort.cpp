#include <vector>
#include <iostream>

using namespace std;

vector<int>  v2;
int counter = 0;

void print(const vector<int> &v)
{
	for(auto i : v)
		cout << " " << i;
	cout << endl;
}

void merge(vector<int> &v, int start, int end, int mid)
{
	int i = start, j = mid + 1;
	int pos = start;
	v2 = v;
	while(i <= mid || j <= end)
	{
		if(i > mid)
			v[pos] = v2[j++];
		else if(j > end)
			v[pos] = v2[i++];
		else if(v2[i] > v2[j]){
			v[pos] = v2[j++];
			counter += mid-i+1;
		}
		else
			v[pos] = v2[i++];
		pos ++;
	}
}

void merge_sort(vector<int> &v, int start, int end)
{
	if (start >= end)
		return ;
	int mid = start + (end - start) / 2;
	merge_sort(v, start, mid);
	merge_sort(v, mid+1, end);
	merge(v, start, end, mid);
}

int main()
{
	vector<int> v = {2,4,1,3,5};
	v2 = vector<int>(v.size(), 0);
	//p = make_shared<vector<int> >(v.size(), 0); 
	merge_sort(v, 0, v.size()-1);
	print(v);
	cout << "reverse pairs: " << counter << endl;
}