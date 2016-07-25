#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int ugly_number(int k)
{
	vector<int> v = {1};
	int p2, p3, p5;
	p2 = p3 = p5 = 0;
	while(v.size() < k)
	{
		while(v[p2] * 2 <= v.back()) p2++;
		while(v[p3] * 3 <= v.back()) p3++;
		while(v[p5] * 5 <= v.back()) p5++;
		
		assert(p2 < v.size());
		assert(p3 < v.size());
		assert(p5 < v.size());

		int next = min(min(v[p2] * 2, v[p3] * 3), v[p5] * 5);
		v.push_back(next);
	}
	assert(v.size() >= k);
	return v[k-1];
}

int main()
{
	cout << ugly_number(1) << endl;
	cout << ugly_number(100) << endl;
	cout << ugly_number(1500) << endl;
	return 0;
}