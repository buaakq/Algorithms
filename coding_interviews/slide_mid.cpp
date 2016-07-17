#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

void print(const vector<int> &num)
{
    for (int a : num)
        cout << a << " ";
    cout << endl;
}

vector<int> medianSlidingWindow(vector<int> &nums, int k) 
{
	vector<int> ret;
	deque<int> k_quque;

	if (k <= 0 || nums.size() < k || nums.size() <= 0)
		return ret;
	int size = 0;
	if (k % 2 == 1)
		size = k / 2 + 1;
	else
		size = k / 2;

	//cout << size << endl;

	multiset<int> half_set;

	for(int i = 0; i < size; i ++){
		half_set.insert(nums[i]);
	}

	for(int i = 0; i < k; i ++){
		k_quque.push_back(nums[i]);
	}

	for (int i = 0; i <= nums.size() - k; i ++){
		if (i == 0){
			ret.push_back(*half_set.rbegin());
		}
		else{
			int pop = k_quque.front();
			k_quque.pop_front();
			half_set.erase(half_set.find(pop));

			k_quque.push_back(nums[k + i - 1]);
			half_set.insert(nums[k + i - 1]);

			ret.push_back(*half_set.rbegin());
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> v = {1,2,7,8,5};
	vector<int> ret = medianSlidingWindow(v, 3);
	print(ret);
	return 0;
}