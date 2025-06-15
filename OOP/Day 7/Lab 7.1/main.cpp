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

class Picture
{
    int rNum;
    int cNum;
    int lNum;
    Rect* pRects;
    Circ* pCircles;
    Line* pLines;

public:
    Picture()
    {
        rNum = 0;
        cNum = 0;
        lNum = 0;
        pRects = NULL;
        pCircles = NULL;
        pLines = NULL;
        cout << "Picture Constructor without Parameters";
    }

    Picture(int rn, int cn, int ln, Rect* rPtr, Circ* cPtr, Line* lPtr)
    {
        rNum = rn;
        cNum = cn;
        lNum = ln;
        pRects = rPtr;
        pCircles = cPtr;
        pLines = lPtr;
        cout << "Picture Constructor with 6 Parameters";
    }


    ~Picture()
    {
        pRects = NULL;
        pCircles = NULL;
        pLines = NULL;
        cout << "\nPicture Destructor";
    }


    void setCircles(int cn, Circ* cPtr)
    {
        cNum = cn;
        pCircles = cPtr;
    }

    void setRects(int rn, Rect* rPtr)
    {
        rNum = rn;
        pRects = rPtr;
    }

    void setLines(int ln, Line* lPtr)
    {
        lNum = ln;
        pLines = lPtr;
    }


    void Paint()
    {
        for(int i = 0; i < cNum; i++)
        {
            pCircles[i].Draw();
        }

        for(int i = 0; i < rNum; i++)
        {
            pRects[i].Draw();
        }

        for(int i = 0; i < lNum; i++)
        {
            pLines[i].Draw();
        }
    }
};


int main()
{
    initwindow(400, 500);


    Picture myPic;
    myPic.Paint();

    Circ cArr[3] = {Circ(50, 50, 50), Circ(100, 100, 100), Circ(200, 200, 200)};
    myPic.setCircles(3, cArr);
    myPic.Paint();



    getch();
    closegraph();


    return 0;
}
