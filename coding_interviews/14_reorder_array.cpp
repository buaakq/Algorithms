#include <iostream>
#include <vector>

using namespace std;

void swap1(vector<int> &v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void reorder(vector<int> &v)
{
	int len = v.size();
	if (len <= 1)
		return;
	int i = -1, j = len;
	while(1)
	{
		while(v[++i] % 2 == 1) if(i == len - 1) break;
		while(v[--j] % 2 == 0) if(j == 0) break;
		if (i < j){
			swap1(v, i, j);
		}
		else
			break;
	}
}

int main()
{
	vector<int> v = {1,0};
	reorder(v);
	for (int item : v)
		cout << item << " ";
	cout << endl;
}