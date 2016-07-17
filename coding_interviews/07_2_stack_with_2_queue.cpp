#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void pop(){
        queue<int> *from;
        queue<int> *to;
        if (q1.size()){
            from = &q1;
            to = &q2;
        }
        else if(q2.size()){
            from = &q2;
            to = &q1;
        }
        else{
            cout << "Emtpy Stack!" << endl;
            return ;
        }
        while(from->size() - 1)
        {
            int tmp = from->front();
            to->push(tmp);
            from->pop();
        }
        from->pop();
    }

    void push(int a){
        if (q1.size())
            q1.push(a);
        else
            q2.push(a);
    }

    int top(){
        queue<int> *from;
        queue<int> *to;
        if (q1.size()){
            from = &q1;
        }
        else if(q2.size()){
            from = &q2;
        }
        else{
            cout << "Emtpy Stack!" << endl;
            return 0;
        }

        return from->back();
    }
};

int main()
{
    MyStack s1;
    s1.push(1);
    s1.push(2);
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();
    s1.push(5);
    cout << s1.top() << endl;
}
