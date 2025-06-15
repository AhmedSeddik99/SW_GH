#include <iostream>
#include <string.h>

using namespace std;


class myTestClass
{
public:

	/// Function Add: Add 2 integer numbers:
	int Add(int x, int y)
	{
	    int res;

        res = x + y;

        return res;
	}


	/// Function Add: Add 3 integer numbers:
	int Add(int x, int y, int z)
	{
	    int res;

        res = x + y + z;

        return res;
	}



    /// Function Add: Add 3 characters
    void Add(char ch1, char ch2, char ch3)
    {
        cout << "Concatenation of 3 char: " << ch1 << ch2 << ch3 << endl;
    }



	/// Function Add: Add 2 Strings
    void Add(char* str1, char* str2)
	{
        cout << "Concatenation of 2 str: "<< strcat(str1, str2);
	}
};



int main()
{

    myTestClass C1;

    char str1[6] = "Ahmed";
    char str2[7] = "Seddik";





    cout << "Addition of 2 integer numbers: " << C1.Add(3, 5) << endl;
    cout << endl;

    cout << "Addition of 3 integer numbers: " << C1.Add(3, 5, 10) << endl;
    cout << endl;

    C1.Add('a', 'b', 'c');
    cout << endl;

    C1.Add(str1, str2);
    cout << endl;

    return 0;
}
