#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str1 = "Ahmed";
    string str2 = "Mohamed";
    string str;


    cout << "Length of Str1 = " << str1.length() << endl;
    cout << "Length of Str2 = " << str2.length() << endl;
    cout << "------------------------------" << endl;


    cout << "Size of Str1 = " << str1.size() << endl;
    cout << "Size of Str2 = " << str2.size() << endl;
    cout << "------------------------------" << endl;


    str = str1 + str2;
    cout << "str1 + str2: " << str << endl;
    cout << "------------------------------" << endl;


    str1 += str2;
    cout << "str1 += str2: " << str1 << endl;
    cout << "------------------------------" << endl;


    str1 = str2;
    cout << "str1 = str2: " << str1 << endl;
    cout << "------------------------------" << endl;


    cout << "Enter Full Name" << endl;
    getline(cin, str);
    cout << "Full Name: " << str << endl;



    return 0;
}
