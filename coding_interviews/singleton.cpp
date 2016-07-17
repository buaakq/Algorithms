#include <iostream>

using namespace std;

class CSingleton{

private:
	CSingleton(){};
	static CSingleton * p_instance;

	int val = 3;

public:
	static CSingleton * get_instance()
	{
		if(p_instance == nullptr)
		{
			//lock();
			if (p_instance == nullptr)
				p_instance = new CSingleton();
		}
		return p_instance;
	}
	int get_val()
	{
		return val;
		.
	}
};

CSingleton * CSingleton::p_instance = nullptr;

int main()
{
	CSingleton * o1 = CSingleton::get_instance();
	cout << o1->get_val() << endl;
	return 0;
}