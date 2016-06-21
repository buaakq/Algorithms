#include <iostream>
#include <vector>
#include <set>

using namespace std;

int min(int a, int b, int c)
{
	int m = (a < b)? a : b;
	return (m < c)? m : c;
}
int main()
{
	vector<int> u = {1};
	int p2, p3, p5;
	p2 = p3 = p5 = 0;
	while(u.size() < 1500)
	{
		int m = min(u[p2] * 2, u[p3] * 3, u[p5] * 5);
		u.push_back(m);
		while(u[p2] * 2 <= u.back())
			p2 ++;
		while(u[p3] * 3 <= u.back())
			p3 ++;
		while(u[p5] * 5 <= u.back())
			p5 ++;
	}
	cout << u[1499] << endl;
}