#include <iostream>

using namespace std;

int fib(int n)
{
    int prev = 1;
    int curr = 0;
    for (int i = 0; i <= n; i ++){
        curr = prev + curr;
        prev = curr - prev;
    }
    return curr;
}

int main()
{
    cout << fib(1) << endl;
    cout << fib(2) << endl;
    cout << fib(11) << endl;
    cout << fib(15) << endl;
    cout << fib(22) << endl;
    cout << fib(30) << endl;
}
