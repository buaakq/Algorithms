#include <iostream>

using namespace std;

double helper(double base, int exp);

bool equal(double a, double b)
{
	if (a - b < 0.000001 && a - b > -0.000001)
		return true;
	else
		return false;
}

double unsigned_power(double base, int exp){
	return helper(base, exp);
}

double helper(double base, int exp)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;

	double ret = helper(base, exp >> 1);
	if (exp & 1 == 1){
		ret = ret * ret * base;
	}
	else{
		ret = ret * ret;
	}
	cout << "will return " << ret << endl;
	return ret;
}

double power(double base, int exp)
{
	double ret = 0.0;
	if (equal(base, 0) && exp <= 0){
		cout << "invalid input!   ";
		return 0.0;
	}
	
	if (exp == 0)
		return 1.0;
	if (equal(base, 0))
		return 0.0;
	if (exp < 0)
	{
		int exp_abs = -exp;
		ret = unsigned_power(base, exp_abs);
		ret = 1.0 / ret;
		cout << ret << endl;
		return ret;
	}
	else
	{
		ret = unsigned_power(base, exp);
		cout << ret << endl;
		return ret;
	}
}

int main()
{
	cout << power(2,10) << endl;
	cout << power(2,-2) << endl;
	cout << power(0,1) << endl;
	cout << power(-1, 5) << endl;
	cout << power(0, -5) << endl;
}