#include <iostream>

using namespace std;


class Date
{
    int Day;
    int Month;
    int Year;

public:
    void setDay(int d);

    void setMonth(int m);

    void setYear(int y);

    int getDay();

    int getMonth();

    int getYear();

    Date(const Date &Dt);

    Date(int d, int m, int y);

    Date();

    ~Date();

    int operator - (Date Dt);

    Date operator + (int);

    Date operator ++ ();

    Date operator ++ (int);

    void operator = (const Date &Dt);

    bool operator == (Date Dt);

    operator int();

    int operator [] (char ch);


};


void printDate( Date &Dt);


int main()
{
    Date Dt1(25, 11, 2024);
    Date Dt2(5, 11, 2024);
    Date Dt3;

    int Diff;

    Diff = Dt1 - Dt2;
    cout << "Dt1 - Dt2  = "<< Diff << endl;

    Dt3 = Dt2 + 10;
    cout << "Dt2 + 10   = ";    printDate(Dt3);

    Dt2 = ++Dt1;
    cout << "Dt2 = ++Dt1 = ";   printDate(Dt2);

    Dt2 = Dt1++;
    cout << "Dt2 = Dt1++ = ";   printDate(Dt2);

    Dt1 = Dt2;
    cout << "Dt1 = Dt2 = ";     printDate(Dt1);

    int res;
    res = Dt1 == Dt2;
    cout << "Dt1 == Dt2 = " << (Dt1 == Dt2) << endl;

    int Dt;
    printDate(Dt1);
    Dt = (int) Dt1;
    cout << "Date Casting to int: " << Dt << endl;

    int x;
    x = Dt1['D'];
    cout << "Day of Dt1: " << x << endl;
    x = Dt1['M'];
    cout << "Month of Dt1: " << x << endl;
    x = Dt1['Y'];
    cout << "Year of Dt1: " << x << endl;

    return 0;
}



/// Setters
void Date :: setDay(int d)
{
    Day = d;
}

void Date :: setMonth(int m)
{
    Month = m;
}

void Date :: setYear(int y)
{
    Year = y;
}

/// Getters
int Date :: getDay()
{
    return Day;
}

int Date :: getMonth()
{
    return Month;
}

int Date :: getYear()
{
    return Year;
}

/// Constructors
Date :: Date(const Date &Dt)
{
    this -> Day = Dt.Day;
    this -> Month = Dt.Month;
    this -> Year = Dt.Year;
    cout << "Copy Constructor " << endl;
}

Date :: Date(int d, int m, int y)
{
    this -> Day = d;
    this -> Month = m;
    this -> Year = y;
    cout << "The Constructor with 3 parameters " << endl;
}

Date :: Date()
{
    this -> Day = 1;
    this -> Month = 1;
    this -> Year = 2000;
    cout << "The Constructor with parameterless " << endl;
}

/// Destructor
Date :: ~Date()
{
    cout << "The Destructor" << endl;
}

/// Operators
int Date :: operator - (Date Dt)
{
    int diff;

    diff = (this -> Day + (this -> Month * 30) + (this -> Year * 365)) - (Dt.Day + (Dt.Month * 30) + (Dt.Year * 365));

    if (diff < 0)
        diff = 0 - diff;

    return diff;
}

Date Date :: operator + (int num)                       /// d1 = d2 + 10;
{
    Date DtRes;

    int DRes = this -> Day + num;

    if(DRes > 30)
    {
       this -> Day = DRes - 30;
       this -> Month ++;
    }
    else
        this -> Day = DRes;

    DtRes.setDay(this -> Day);
    DtRes.setMonth(this -> Month);
    DtRes.setYear(this -> Year);

    return DtRes;
}

Date Date :: operator ++ ()                             /// d1 = ++d2;
{
    Date DtRes;

    DtRes.setDay(++this -> Day);
    DtRes.setMonth(this -> Month);
    DtRes.setYear(this -> Year);

    return DtRes;
}

Date Date :: operator ++ (int)                          /// d1 = d2++;
{
    Date temp(*this);

    this -> Day++;

    return temp;
}

void Date :: operator = (const Date &Dt)                /// d1 = d2;
{
    this -> Day = Dt.Day;
    this -> Month = Dt.Month;
    this -> Year = Dt.Year;
}

bool Date :: operator == (Date Dt)		                        /// if(d1 == d2);
{
    if(this -> Day == Dt.Day && this -> Month == Dt.Month && this -> Year == Dt.Year)
        return 1;
    else
        return 0;
}

Date :: operator int()
{
    return(this -> Day + (this -> Month * 30) + (this -> Year * 365));
}

int Date :: operator [] (char ch)
{
    if(ch == 'D')
        return this -> Day;
    else if(ch == 'M')
        return this -> Month;
    else if(ch == 'Y')
        return this -> Year;
    else
        return -1;
}

void printDate(Date &Dt)
{
    cout << Dt.getDay() << "-" << Dt.getMonth() << "-" << Dt.getYear() << endl;
}
