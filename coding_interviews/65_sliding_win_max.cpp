#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;

void print(const vector<int> &num)
{
    for (int a : num)
        cout << a << " ";
    cout << endl;
}

vector<int> slide_max(const vector<int> &num, const int k)
{
    deque<int> q;
    multiset<int> s;
    vector<int> ret;
    if (num.size() <= 0 || k > num.size() || k <= 0)
        return ret;
    for (int i = 0; i < k; i ++){
        q.push_back(num[i]);
        s.insert(num[i]);
    }
    //cout << q.size()<< endl;

    for (int i = 0; i <= num.size() - k; i ++){
        if (i > 0){
            q.push_back(num[k + i - 1]);
            s.insert(num[k + i - 1]);
        }
        cout << s.size() << endl;
        ret.push_back(*s.rbegin());
        int last = q.front();
        q.pop_front();
        s.erase(s.find(last));
        //cout << q.size() << endl;
    }

    return ret;
}


int main()
{
    vector<int> nums = {1,2,7,7,2,10,3,4,5};
    vector<int> mid = slide_max(nums, 2);
    //cout << mid.size() << endl;
    print(mid);
}
