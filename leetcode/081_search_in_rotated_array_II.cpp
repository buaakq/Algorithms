#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& v, int target) {
    int len = v.size();
    int lo =0, hi = len - 1;
    int mid = 0;
    while(lo <= hi){
        int mid = lo + (hi-lo) / 2;
        if (v[mid] == target)
            return true;
        if (v[mid] > v[lo])
        {
            if (target >= v[lo] && target < v[mid])
               hi = mid - 1;
            else
               lo = mid + 1;
        }
        else if (v[mid] < v[lo])
        {
            if (target > v[mid] && target <= v[hi])
               lo = mid + 1;
             else
                hi = mid - 1;
        }
        else
        {
            lo ++;
        }
    }
    return false;
}

int main()
{
	vector<int> v1 = {1,2,3,4,5,6,7,8};
	vector<int> v2 = {5,5,5,1,5,5,5};
	cout << search(v1, 4) << endl;
	cout << search(v1, 10) << endl;
	cout << search(v2, 5) << endl;
	cout << search(v2, 4) << endl;
}