#include <iostream>
#include <vector>

using namespace std;

double helper(vector<int>::iterator a, int m, vector<int>::iterator b, int n, int num)
{
	if (m > n)
		return helper(b, n, a, m, num);
	if (m == 0)
		return *(b + num - 1);
	if (num == 1)
		return min(a[0], b[0]);
	int p = min(num / 2, m);
	int q = num - p;

	if (*(a+p-1) == *(b+q-1))
		return *(a+p-1);
	else if(*(a+p-1) > *(b+q-1))
		return helper(a, m, b+q, n-q, num-q);
	else
		return helper(a+p, m-p, b, q, num-p);
}

double findMedianSortedArrays(vector<int>& a, vector<int>& b)
{
	int m = a.size();
	int n = b.size();
	if (m + n == 0)
		return 0;
	int k = (m + n) / 2;
	if ((m + n) % 2 == 0)
		return (helper(a.begin(),m,b.begin(),n,k+1) + helper(a.begin(),m,b.begin(),n,k)) / 2;
	else
		return helper(a.begin(),m,b.begin(),n,k+1);
}

int main()
{
	vector<int> a = {1,2,3,4,5};
	vector<int> b = {3,4,5,6,10};
	cout << findMedianSortedArrays(a,b) << endl;
	return 0;
}