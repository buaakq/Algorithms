#include <vector>
using namespace std;


class MaxHeap
{
public:
	MaxHeap(int max_nums){
		heap = new int[max_nums]; 
	}

	~MaxHeap(){
		delete heap;
	}

	int size(){
		return n;
	}

	bool empty(){
		return n==0;
	}

	int getMax(){
		return heap[1];
	}

	void delMax(){
		heap[1] = heap[n--];
		sink(1);
	}

	void insert(int data){
		heap[++n] = data;
		swim(n);
	}

	void swim(int k){
		while(k>1 && heap[k] > heap[k/2])
		{
			swap(heap[k], heap[k/2]);
			k = k / 2;
		}
	}

	void sink(int k)
	{
		while(k*2 <= n)
		{
			int j = k*2;
			if (j < n && heap[j] < heap[j+1])
				j = j + 1;
			if (heap[j] > heap[k]){
				swap(heap[j], heap[k]);
				k = j;
			}
			else
				break;
		}
	}

private:
	int * heap = nullptr;   //
	int n = 0;  // using [1,n], 0 is not used
};






