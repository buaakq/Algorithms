#include <iostream>
#include <string.h>

using namespace std;

class Mystring
{

    public:
        char * data;

    Mystring(char * str = NULL)
    {
  		if (str == NULL)
  		{
     		data = new char[1];
     		data = '\0';
  		}
  		else 
  		{
      		int len = strlen(str);
      		data = new char[len+1];
      		strcpy (data, str);
 		}
 	}

    Mystring(const Mystring & str);
    ~Mystring(){};

    //private:

	Mystring & operator =(const Mystring &str)
	{
    	if (&str == this)
        	return *this;
    //delete [] data;
    // data = NULL;
    	char * temp = new char[ strlen(str.data) + 1];
    	if (temp)
        	 delete [] data;
         	data = temp;
         	strcpy(data, str.data);

    return *this;
	}
};

int main()
{
	Mystring str1("hello_world");
	Mystring str2;
	str2 = str1;
	cout << str2.data << endl;

	return 0;
}