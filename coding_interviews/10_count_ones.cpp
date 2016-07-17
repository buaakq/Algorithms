#include <iostream>
#include <stdio.h>

using namespace std;

int countOnes(int n)
{
    unsigned int flag = 1;
    int counter = 0;
    int num = 0;
    while(flag)
    {
        if (flag & n)
            counter ++;
        flag = flag << 1;
        num ++;
    }
    return counter;
}

int countOnes2(int n)
{
    int ret = 0;
    while(n)
    {
        ret ++;
        n = n & (n - 1);
    }
    return ret;
}

int main()
{
    unsigned int a = 0xffffffff;

    printf("%X\n", a);

    cout << countOnes2(a) << endl;
}
