#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void pop(){
        if (s2.size() == 0){
            while(s1.size()){
                int tmp = s1.top();
                s2.push(tmp);
                s1.pop();
            }
        }
        if (s2.size() == 0)
            cout << "Empty Queue!" << endl;
        else
            s2.pop();
    }

    void push(int a){
        s1.push(a);
    }
    int top(){
        if (s2.size() == 0){
            while(s1.size()){
                int tmp = s1.top();
                s2.push(tmp);
                s1.pop();
            }
        }
        if (s2.size() == 0)
            cout << "Empty Queue!" << endl;
        else
            return s2.top();
    }
};

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.top() << " ";
    q.pop();
    cout << q.top() << endl;
}
