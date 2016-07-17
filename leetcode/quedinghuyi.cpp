#include <string>
#include <iostream>
using namespace std;

    bool is_huyi(string iniString) {
        // write code here
        int len = iniString.size();
        if (len <= 1)
            return true;
        bool table[256];
        for(int i = 0; i < 256;i++)
        {
            table[i] = 0;
        }
        for (int i = 0; i < len; i++)
        {
            int index = iniString[i];
            if (table[index] == false)
                table[index] = true;
            else{
            	cout << i << endl;
            	cout << index << endl;
            	cout << "will return false here!" << endl;
                return false;
            }
        }
        return true;
    }

int main()
{
	string s = "D-5H0F6T%Z?QM9,72:[A8X! ;YJ#";
	cout << is_huyi(s) << endl;
	cout << "\72" << endl;
}