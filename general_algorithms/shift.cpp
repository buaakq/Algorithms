#include <iostream>
#include <vector>

using namespace std;
void reverse(std::vector<int> &v, int i, int j)
{
	if(i >= j)
		return;
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	reverse(v, i+1, j-1);
}

void shift(std::vector<int> &v, int n)
{
	int len = v.size();
	n = n % len;
	reverse(v, 0, len - 1);
	reverse(v, 0, len - 1 - n);
	reverse(v, len - 1 - n + 1, len - 1);
}

void print(std::vector<int> v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int> a = {1,2,3,4,5,6};
	shift(a, 2);
	print(a);
}