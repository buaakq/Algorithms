#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int p = 1;
	while(a % 2 == 0 && b % 2 == 0)
	{
		p *= 2;
		a /= 2;
		b /= 2;
	}

	while(a != b)
	{
		int t = (a > b)? (a - b) : (b - a);
		while(t % 2 == 0)
			t /= 2;
		if (a >= b)
			a = t;
		else
			b = t;
	}
	return a * p;
}

int main()
{
	cout << gcd(32, 100) << endl;
}