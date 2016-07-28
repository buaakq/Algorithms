#include <vector>
#include <iostream>

using namespace std;

void sink(vector<int> &heap , int N, int k)
{
	int n = N;
	while(k*2 <= n)
	{
		int j = k*2;
		if (j < n && heap[j-1] < heap[j])
			j = j + 1;
		if (heap[j-1] > heap[k-1]){
			swap(heap[j-1], heap[k-1]);
			k = j;
		}
		else
			break;
	}
}

void heap_sort(vector<int> &v)
{
	int len = v.size();
	for(int i = len/2; i >=1; i --)
	{
		sink(v, len, i);
	}
	// 达到堆有序
	while(len > 1)
	{
		// 堆顶跟末尾交换
		swap(v[0], v[len-1]);
		// 总数减1
		len --;
		// 堆顶下沉，重新构造堆
		sink(v, len, 1);
	}
}

int main()
{
	vector<int> v = {4,3,4,5,2,3,4,1,1,8,7,9};
	heap_sort(v);
	for(auto i : v)
		cout << i << " ";
	cout << endl;
	return 0;
}
