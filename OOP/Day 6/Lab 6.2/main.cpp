#include <iostream>
#include <graphics.h>

using namespace std;


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


class Line
{
    Point Start;
    Point End;

public:
    Line(int n1, int n2, int n3, int n4) : Start(n1, n2), End(n3, n4)
    {
//        Start.setX(n1);
//        Start.setY(n2);
//        End.setX(n3);
//        End.setY(n4);
        cout << "Line Constructor with 4 Parameters";
    }

    Line()
    {
        Start.setX(0);
        Start.setY(0);
        End.setX(0);
        End.setY(0);
        cout << "Line Constructor without Parameters";
    }

    ~Line()
    {
        cout << "\nLine Destructor";
    }

    void Draw()
    {
        setcolor(CYAN);
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};



class Rect
{
    Point UL;
    Point LR;

public:
    Rect(int n1, int n2, int n3, int n4)
    {
        UL.setX(n1);
        UL.setY(n2);
        LR.setX(n3);
        LR.setY(n4);
        cout << "Rectangle Constructor with 4 Parameters";
    }

    Rect()
    {
        UL.setX(0);
        UL.setY(0);
        LR.setX(0);
        LR.setY(0);
        cout << "Rectangle Constructor without Parameters";
    }

    ~Rect()
    {
        cout << "\nRectangle Destructor";
    }

    void Draw()
    {
        setcolor(RED);
        rectangle(UL.getX(), UL.getY(), LR.getX(), LR.getY());
    }
};



class Circ
{
    Point Center;
    int radius;

public:
    Circ(int n1, int n2, int r)
    {
        Center.setX(n1);
        Center.setY(n2);
        radius = r;
        cout << "Circle Constructor with 3 Parameters";
    }

    Circ()
    {
        Center.setX(0);
        Center.setY(0);
        radius = 1;
        cout << "Circle Constructor without Parameters";
    }

    ~Circ()
    {
        cout << "\nCircle Destructor";
    }

    void Draw()
    {
        setcolor(GREEN);
        circle(Center.getX(), Center.getY(), radius);
    }
};



int main()
{
    initwindow(400, 500);


    Line L(10, 20, 50, 100);
    L.Draw();


    Rect R(50, 100, 200, 300);
    R.Draw();

    Circ C(100, 200, 50);
    C.Draw();


    getch();
    closegraph();


    return 0;
}
