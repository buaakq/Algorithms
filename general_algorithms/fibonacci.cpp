#include <iostream>

using namespace std;
class Fib{
public:
	Fib(int n)
	{
		while(1)
		{
			if (curr >= n)
				break;
			next();
		}
	}
	void next()
	{curr = curr + prev; prev = curr - prev;}
	int get()
	{return curr;}
	void last()
	{prev = curr - prev; curr = curr - prev;}
private:
	int prev = 1;  // fib(-1) = 1
	int curr = 0;  // fib(0) = 0
};

long long fib(int n){
	long long prev = 1;
	long long now = 0;
	while(n)
	{
		now = prev + now;
		prev = now - prev;
		n --;
	}
	return now;
}


int main()
{
	cout << fib(0) << endl;
	cout << fib(1) << endl;
	cout << fib(2) << endl;
	cout << fib(3) << endl;
	cout << fib(4) << endl;
	cout << fib(5) << endl;
	cout << fib(100) << endl;

	Fib f(13);
	f.next();
	f.next();
	cout << f.get() << endl;
	f.last();
	cout << f.get() << endl;
}