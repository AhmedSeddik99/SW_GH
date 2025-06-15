#include <iostream>

using namespace std;

class Parent
{
    int X;

protected:
    int Y;

public:
    Parent(int num1, int num2)
    {
        X = num1;
        Y = num2;
        cout << "Parent Constructor with 2 Parameters" << endl;
    }

    Parent(int num)
    {
        X = Y = num;
        cout << "Parent Constructor with 1 Parameters" << endl;
    }

    Parent()
    {
        X = Y = 0;
        cout << "Parent Constructor Parameterless" << endl;
    }

    ~Parent()
    {

        cout << "Parent Destructor" << endl;
    }

    void setX(int x)
    {
        X = x;
    }

    void setY(int y)
    {
        Y = y;
    }

    int getX()
    {
        return X;
    }

    int getY()
    {
        return Y;
    }

    int Sum()
    {
        return X + Y;
    }
};



class Child : public Parent
{
    int Z;

public:
    Child(int num1, int num2, int num3) : Parent (num1, num2)
    {
        setX(num1);
        Y = num2;
        Z = num3;
        cout << "Child Constructor with 3 Parameters" << endl;
    }

    Child()
    {
        Z = 0;
        cout << "Child Constructor Parameterless" << endl;
    }

    ~Child()
    {

        cout << "Child Destructor" << endl;
    }

    void setZ(int z)
    {
        Z = z;
    }

    int getZ()
    {
        return Z;
    }

    int Sum()
    {
        return Parent :: Sum() + Z;
    }
};



class GrandChild : public Child
{
    int M;

public:
    GrandChild(int num1, int num2, int num3, int num4) : Child (num1, num2, num3)
    {
        setX(num1);
        Y = num2;
        setZ(num3);
        M = num4;
        cout << "Grand Child Constructor with 4 Parameters" << endl;
    }

    GrandChild()
    {
        M = 0;
        cout << "Grand Child Constructor Parameterless" << endl;
    }

    ~GrandChild()
    {

        cout << "Grand Child Destructor" << endl;
    }

    void setM(int m)
    {
        M = m;
    }

    int getM()
    {
        return M;
    }

    int Sum()
    {
        return Child :: Sum() + M;
    }
};



int main()
{
    int x = 1;
    int y = 2;
    int z = 3;
    int m = 4;

    Parent Pnt(3, 4);                       /// = 7

    Child  Chd(4, 5, 6);                    /// = 15

    GrandChild GChd(x, y, z, m);            /// = 10

    cout << "Parent Sum = " << Pnt.Sum() << endl;
    cout << "Child Sum = " << Chd.Sum() << endl;
    cout << "Grand Child Sum = " << GChd.Sum() << endl;

    return 0;
}
