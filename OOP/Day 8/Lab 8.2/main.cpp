#include <iostream>
#include <graphics.h>

using namespace std;


class Shape         /// Abstract Class
{
protected:
    int Color;

public:
    Shape(int num)
    {
        Color = num;
        cout << "Shape Constructor with 1 Parameter" << endl;
    }

    Shape()
    {
        Color = 0;
        cout << "Shape Constructor Parameterless" << endl;
    }

    ~Shape()
    {

        cout << "\nShape Destructor" << endl;
    }

    virtual void Draw() = 0;                /// pure virtual function
};



class Point
{
    int x, y;

public:
    Point(int num1, int num2)
    {
        x = num1;
        y = num2;
        cout << "Point Constructor with 2 Parameters" << endl;
    }

    Point(int num)
    {
        x = y = num;
        cout << "Point Constructor with 1 Parameter" << endl;
    }

    Point()
    {
        x = y = 0;
        cout << "Point Constructor without Parameters" << endl;
    }

    void setX(int num)
    {
        x = num;
    }

    void setY(int num)
    {
        y = num;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    ~Point()
    {
        cout << "\nPoint Destructor" << endl;
    }
};


class Line : public Shape
{
    Point Start;
    Point End;

public:
    Line(int n1, int n2, int n3, int n4, int c) : Start(n1, n2), End(n3, n4), Shape(c)
    {
        cout << "Line Constructor with 5 Parameters";
    }

    Line() : Start(), End(), Shape()
    {
        cout << "Line Constructor without Parameters";
    }

    ~Line()
    {
        cout << "\nLine Destructor";
    }

    void Draw()
    {
        setcolor(Color);
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};


class Rect : public Shape
{
    Point UL;
    Point LR;

public:
    Rect(int n1, int n2, int n3, int n4, int c)
    {
        UL.setX(n1);
        UL.setY(n2);
        LR.setX(n3);
        LR.setY(n4);
        Color = c;
        cout << "Rectangle Constructor with 5 Parameters";
    }

    Rect()
    {
        UL.setX(0);
        UL.setY(0);
        LR.setX(0);
        LR.setY(0);
        Color = 15;
        cout << "Rectangle Constructor without Parameters";
    }

    ~Rect()
    {
        cout << "\nRectangle Destructor";
    }

    void Draw()
    {
        setcolor(Color);
        rectangle(UL.getX(), UL.getY(), LR.getX(), LR.getY());
    }
};


class Circle : public Shape
{
    Point Center;
    int radius;

public:
    Circle(int n1, int n2, int r, int c)
    {
        Center.setX(n1);
        Center.setY(n2);
        radius = r;
        Color = c;
        cout << "Circle Constructor with 4 Parameters";
    }

    Circle()
    {
        Center.setX(0);
        Center.setY(0);
        radius = 1;
        Color = 15;
        cout << "Circle Constructor without Parameters";
    }

    ~Circle()
    {
        cout << "\nCircle Destructor";
    }

    void Draw()
    {
        setcolor(Color);
        circle(Center.getX(), Center.getY(), radius);
    }
};


class Picture
{
    Shape** ShapePtr;
    int ShNum;

public:
    Picture()
    {
        ShapePtr = NULL;
        ShNum = 0;
        cout << "Picture Constructor without Parameters";
    }

    Picture(Shape** Shptr, int n)
    {
        ShapePtr = Shptr;
        ShNum = n;
        cout << "Picture Constructor with Parameters";
    }


    ~Picture()
    {
        ShapePtr = NULL;
        cout << "\nPicture Destructor";
    }


    void setShapes(Shape** Shptr, int n)
    {
        ShapePtr = Shptr;
        ShNum = n;
    }


    void Paint()
    {
        for(int i = 0; i < ShNum; i++)
        {
            ShapePtr[i] -> Draw();
        }
    }
};





int main()
{

    initwindow(400, 500);


    Picture myPic;
    ///myPic.Paint();

    Circle C(50, 50, 50, 4);
    Line L (100, 100, 200, 200, 13);
    Rect R (100, 100, 200, 200, 3);


    Shape* ShArr[3];
    ShArr[0] = &C;
    ShArr[1] = &L;
    ShArr[2] = &R;

    myPic.setShapes(ShArr, 3);
    myPic.Paint();


    getch();
    closegraph();
    return 0;
}
