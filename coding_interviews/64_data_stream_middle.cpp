#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> stream_middle(const vector<int> &num)
{
    vector<int> ret;
    if (num.size() == 0)
        return ret;
    ret.push_back(num[0]);
    if (num.size() == 1)
        return ret;

    multiset<int> left, right;
    left.insert(min(num[0], num[1]));
    right.insert(max(num[0], num[1]));

    ret.push_back(*left.begin());

    bool flag = true;

    for (int i = 2; i < num.size(); i ++){
        int tmp = num[i];
        if (flag){
            int right_min = *right.begin();
            if (tmp > right_min){
                left.insert(right_min);
                right.erase(right.begin());
                right.insert(tmp);
            }
            else
                left.insert(tmp);
        }
        else{
            int left_max = *left.rbegin();
            if (tmp < left_max){
                right.insert(left_max);
                left.erase(left.find(left_max));
                left.insert(tmp);
            }
            else
                right.insert(tmp);
        }
        flag = !flag;
        ret.push_back(*left.rbegin());
    }
    return ret;
}

void print(const vector<int> &num)
{
    for (int a : num)
        cout << a << "";
    cout << endl;
}

int main()
{
    vector<int> nums = {1,6,7,8,9,3,2,11,15,4};
    vector<int> mid = stream_middle(nums);
    print(mid);
}
