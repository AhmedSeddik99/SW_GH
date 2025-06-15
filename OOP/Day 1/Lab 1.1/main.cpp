#include <iostream>

using namespace std;


void swapVal(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}



void swapAddr(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void swapRef(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}


int main()
{
    int a = 5;
    int b = 9;

    cout << "Before Swapping by Value: a = " << a << " , b = " << b << endl;
    swapVal(a, b);
    cout << "After  Swapping by Value: a = " << a << " , b = " << b << endl;

    cout << endl;
    cout << "Before Swapping by Address: a = " << a << " , b = " << b << endl;
    swapAddr(&a, &b);
    cout << "After  Swapping by Address: a = " << a << " , b = " << b << endl;

    cout << endl;
    cout << "Before Swapping by Reference: a = " << a << " , b = " << b << endl;
    swapRef(a, b);
    cout << "After  Swapping by Reference: a = " << a << " , b = " << b << endl;


    return 0;
}
