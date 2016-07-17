#include <iostream>
#include <vector>


using namespace std;

void print(std::vector<int> v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}
vector<int> hailstone(int n)
{
	std::vector<int> ret;
	while(n != 1)
	{
		if (n % 2 == 0)
		{
			ret.push_back(n);
			n = n / 2;
		}
		else
		{
			ret.push_back(n);
			n = 3 * n + 1;
		}
	}
	ret.push_back(1);
	return ret;
}

int main()
{
	vector<int> a = hailstone(7);
	print(a);
}