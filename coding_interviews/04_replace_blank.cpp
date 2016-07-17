#include <iostream>
#include <string.h>

using namespace std;

int replaceBlank(char * str, int len)
{
	int blank_counter = 0;
	for (int i = 0; i < len; i ++){
		if (str[i] == ' ')
			blank_counter ++;
	}

	int last = len + blank_counter * 2;
	int new_len = last;
	for (int i = len; i >=0; i --){
		if (str[i] != ' '){
			//cout << str[i] << endl;
			str[last --] = str[i];
		}
		else{
			str[last --] = '0';
			str[last --] = '2';
			str[last --] = '%';
		}
	}
	return new_len;
}

int main()
{
	char str[100] = "hello world";
	cout << strlen(str) << endl;
	int new_len = replaceBlank(str, strlen(str));
	cout << strlen(str) << endl;
	cout << "new string is : " << str << endl;
}