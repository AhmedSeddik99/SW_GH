#include <iostream>

# define pi 3.14


using namespace std;


class Shape
{
protected:
    float dim1;
    float dim2;

public:
    Shape(float num1, float num2)
    {
        dim1 = num1;
        dim2  = num2;
        cout << "Shape Constructor with 2 Parameters" << endl;
    }

    Shape(float num)
    {
        dim1 = dim2 = num;
        cout << "Shape Constructor with 1 Parameter" << endl;
    }

    Shape()
    {
        dim1 = dim2 = 0;
        cout << "Shape Constructor Parameterless" << endl;
    }

    ~Shape()
    {

        cout << "\nShape Destructor" << endl;
    }


    void setDim1(float d1)
    {
        dim1 = d1;
    }

    void setDim2(float d2)
    {
        dim2 = d2;
    }

    float getDim1()
    {
        return dim1;
    }

    float getDim2()
    {
        return dim2;
    }

    virtual float CalcArea() = 0;

};



class Rect  : public Shape
{
public:
    Rect() : Shape()
    {cout << "Rectangle Constructor Parameterless" << endl;}

    Rect(float num1, float num2) : Shape(num1, num2)
    {cout << "Rectangle Constructor with 2 Parameters" << endl;}

    ~Rect()
    {
        cout << "Rectangle Destructor" << endl;
    }

    float CalcArea()
    {
        ///cout << "Area of Rectangle = ";
        return (getDim1() * getDim2());
    }
};


class Sqr  : public Shape
{
public:
    Sqr() : Shape()
    {cout << "Square Constructor Parameterless" << endl;}

    Sqr(float num) : Shape(num)
    {cout << "Square Constructor with 1 Parameter" << endl;}

    ~Sqr()
    {
        cout << "Square Destructor" << endl;
    }

    void setDim(float d)
    {
        dim1 = dim2 = d;
    }

    float CalcArea()
    {
        ///cout << "Area of Square = ";
        return (getDim1() * getDim2());
    }
};


class Circ  : public Shape
{
public:
    Circ() : Shape()
    {cout << "Circle Constructor Parameterless" << endl;}

    Circ(float num) : Shape(num)
    {cout << "Circle Constructor with 1 Parameter" << endl;}

    ~Circ()
    {
        cout << "Circle Destructor" << endl;
    }

    void setDim(float r)
    {
        dim1 = dim2 = r;
    }

    float CalcArea()
    {
        ///cout << "Area of Circle = ";
        return (getDim1() * getDim2() * pi);
    }
};



class Tri  : public Shape
{
public:
    Tri() : Shape()
    {cout << "Triangle Constructor Parameterless" << endl;}

    Tri(float num1, float num2) : Shape(num1, num2)                     /// base != height
    {cout << "Triangle Constructor with 2 Parameter" << endl;}

    Tri(float num) : Shape(num)                                         /// base = height
    {cout << "Triangle Constructor with 1 Parameter" << endl;}

    ~Tri()
    {
        cout << "Triangle Destructor" << endl;
    }

    float CalcArea()
    {
        ///cout << "Area of Triangle = ";
        return (getDim1() * getDim2() * 0.5);
    }
};




float sumOfAllShapesArea(Shape* ShapeArr[], int n)
{
    float sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += ShapeArr[i] -> CalcArea();
    }

    return sum;
}




int main()
{
    ///Shape Sh(2);


    Rect R(5, 6);
    Sqr S(5);
    Circ C(4);
    Tri T(3, 4);


    ///Shape* Sh = &R;
    ///cout << "Area of Rectangle = " << Sh -> CalcArea() << endl;


    Shape* ShArr[4];

    ShArr[0] = &R;
    ShArr[1] = &S;
    ShArr[2] = &C;
    ShArr[3] = &T;

    cout << "\n-----------------------------------------------------" << endl;
    cout << "sumOfAllShapesArea = " << sumOfAllShapesArea(ShArr, 4) <<endl;
    cout << "-----------------------------------------------------" << endl;

    return 0;
}
