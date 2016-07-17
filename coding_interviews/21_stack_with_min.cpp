#include <iostream>
#include <stack>
using namespace std;

class MyStack
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	int min(){
		return s2.top();
	}
	int top(){
		return s1.top();
	}
	void pop(){
		s1.pop();
		s2.pop();
	}
	void push(int val){
		if (s1.empty()){
			s1.push(val);
			s2.push(val);
		}
		else if(val <= s2.top())
		{
			s1.push(val);
			s2.push(val);
		}
		else{
			s1.push(val);
			s2.push(s2.top());
		}
	}
};

int main()
{
	MyStack s1;
	s1.push(1);
	s1.push(2);
	s1.push(0);
	cout << s1.min() << endl;
	s1.pop();
	cout << s1.min() << endl;
}