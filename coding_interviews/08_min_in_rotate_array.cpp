#include <iostream>
#include <vector>

using namespace std;

int find_in_order(const vector<int> &a, int left, int right){
    int ret = a[left];
    for(int i = left; i <= right; i ++){
        if (a[i] < ret)
            ret = a[i];
    }
    return ret;
}

int helper(const vector<int> &a, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (right == left + 1)
        return a[right];
    if (a[mid] == a[left] && a[mid] == a[right])
        return find_in_order(a, left, right);
    else if(a[mid] >= a[left])
        return helper(a, mid, right);
    else
        return helper(a, left, mid);
}

int min_rotate(const vector<int> &a)
{
    if (a.size() == 1)
        return a[0];
    int ret = helper(a, 0, a.size() - 1);
    return ret;
}

int main()
{
    vector<int> tmp1 = {3,4,5,6,7,0,1,2};
    vector<int> tmp2 = {1,1,1,1,1,1,2,3,4,5,-4,1,1};
    int min1 = min_rotate(tmp1);
    int min2 = min_rotate(tmp2);

    cout << min1 << " " << min2 << endl;
}
