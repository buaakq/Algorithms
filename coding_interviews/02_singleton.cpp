#include <iostream>

using namespace std;

class S
{
 private:
    S() {}  ;                          // 把构造函数声明为私有的，需要加上花括号
    S(const S &);                      // 把拷贝构造函数声明为私有，避免程序员调用
    S & operator = (const S &);        // 把赋值运算符=声明为私有，避免程序员用类似 S s = S::getInstance()的方式调用

  public:
    static S & getInstance()
    {    
        static S instance;
        return instance; 
    }
    int data = 5;
};

int main()
{
	S &s1 = S::getInstance();
	S &s2 = S::getInstance();
	// they have the same address, so they are the same instance.
	cout << &s1 << "  "<< &s2 << endl;
}