#include <iostream>


using namespace std;


struct Complex
{
private:
    int Real;
    int Img;


public:
    void setReal(int r);

    void setImg(int i);

    int getReal();

    int getImg();

    Complex(const Complex &Cx);

    Complex(int r, int i);

    Complex(int n);

    Complex();

    ~Complex();

    Complex Add(Complex C2);

    Complex operator - (Complex C);

    Complex operator - (int num);

    Complex operator -= (Complex C);

    Complex operator -- ();

    Complex operator -- (int);

    int operator == (Complex C);

    int operator != (Complex C);

    int operator > (Complex C);

    int operator >= (Complex C);

    int operator < (Complex C);

    int operator <= (Complex C);

    operator int ();

    int operator [] (char ch);

};

Complex operator - (int num, Complex C);

void printComplex(Complex C);



int main()
{
    Complex C1(3,4), C2(5), C3;
    //C3 = C1.Add(C2);

    C3 = C1 - C2;
    cout << "C1 - C2  = ";  printComplex(C3);

    C3 = 7 - C2;
    cout << "7 - C2   = ";  printComplex(C3);

    C3 = C1 - 7;
    cout << "C1 - 7   = ";  printComplex(C3);

    C1 -= C2;
    cout << "C1 -= C2 = ";  printComplex(C1);

    C2 = --C1;
    cout << "C2 = --C1 = ";  printComplex(C2);

    C2 = C1--;
    cout << "C2 = C1-- = ";  printComplex(C2);

    int res;
    res = C1 == C2;
    cout << "C1 == C2 = " << res << endl;

    res = C1 != C2;
    cout << "C1 != C2 = " << res << endl;

    res = C1 > C2;
    cout << "C1 > C2 = " << res << endl;

    res = C1 >= C2;
    cout << "C1 >= C2 = " << res << endl;

    res = C1 < C2;
    cout << "C1 < C2 = " << res << endl;

    res = C1 <= C2;
    cout << "C1 <= C2 = " << res << endl;

    int C;
    printComplex(C1);
    C = (int) C1;
    cout << "Casting to int: " << C << endl;

    int x;
    x = C1['R'];
    cout << "Real part of C1: " << x << endl;

    return 0;
}




void Complex :: setReal(int r)
{
    Real = r;
}

void Complex :: setImg(int i)
{
    Img = i;
}

int Complex :: getReal()
{
    return Real;
}

int Complex :: getImg()
{
    return Img;
}


Complex :: Complex(const Complex &Cx)
{
    this -> Real = Cx.Real;
    this -> Img = Cx.Img;
    //cout << "Copy Constructor " << endl;
}

Complex :: Complex(int r, int i)
{
    this -> Real = r;
    this -> Img = i;
    //cout << "First Constructor with 2 parameters " << endl;
}

Complex :: Complex(int n)
{
    this -> Real = Img = n;
    //cout << "Second Constructor with 1 parameter " << endl;
}

Complex :: Complex()
{
    this -> Real = Img = 0;
    //cout << "Third Constructor with no parameter " << endl;
}

Complex :: ~Complex()
{
    //cout << "The Destructor" << endl;
}


Complex Complex :: Add(Complex C2)
{
    Complex C1;

    int RealAdd, ImgAdd;

    RealAdd = this -> Real + C2.getReal();
    ImgAdd  = this -> Img  + C2.getImg() ;

    C1.setReal(RealAdd);
    C1.setImg(ImgAdd);

    return C1;
}


Complex Complex :: operator - (Complex C)                   /// CRes = C1 - C2
{
    Complex CRes;

    int RealSub, ImgSub;

    RealSub = this -> Real - C.getReal();
    ImgSub  = this -> Img  - C.getImg() ;

    CRes.setReal(RealSub);
    CRes.setImg(ImgSub);

    return CRes;
}


Complex operator - (int num, Complex C)                     /// CRes = 7 - C2 {StandAlone Function}
{
    Complex CRes(num - C.getReal(), C.getImg());
    return CRes;
}


Complex Complex :: operator - (int num)                     /// CRes = C1 - 7
{
    Complex CRes;

    int RealSub, ImgSub;

    RealSub = this -> Real - num;
    ImgSub  = this -> Img;

    CRes.setReal(RealSub);
    CRes.setImg(ImgSub);

    return CRes;
}


Complex Complex :: operator -= (Complex C)                  /// CRes -= C --> CRes = CRes - C
{
    int RealSub, ImgSub;

    RealSub = this -> Real - C.getReal();
    ImgSub  = this -> Img  - C.getImg();

    this -> Real = RealSub;
    this -> Img  = ImgSub;

    return *this;
}


Complex Complex :: operator -- ()                           /// CRes = --C
{
    Complex CRes;
    CRes.setReal(--this -> Real);
    CRes.setImg(this -> Img);

    return CRes;
}


Complex Complex :: operator -- (int)                        /// CRes = C--
{
    Complex temp(*this);
    this -> Real--;
    return temp;
}


int Complex :: operator == (Complex C)
{
    if(this -> Real == C.Real && this -> Img == C.Img)
        return 1;
    else
        return 0;
}


int Complex :: operator != (Complex C)
{
    if(this -> Real == C.Real && this -> Img == C.Img)
        return 0;
    else
        return 1;
}


int Complex :: operator > (Complex C)
{
    if(this -> Real > C.Real && this -> Img > C.Img)
        return 1;
    else
        return 0;
}

int Complex :: operator >= (Complex C)
{
    if(this -> Real >= C.Real && this -> Img >= C.Img)
        return 1;
    else
        return 0;
}


int Complex :: operator < (Complex C)
{
    if(this -> Real < C.Real && this -> Img < C.Img)
        return 0;
    else
        return 1;
}

int Complex :: operator <= (Complex C)
{
    if(this -> Real <= C.Real && this -> Img <= C.Img)
        return 0;
    else
        return 1;
}

Complex :: operator int ()
{
    return(this -> Real + this -> Img);
}


int Complex :: operator [] (char ch)
{
    if(ch == 'R')
        return this -> Real;
    else if(ch == 'I')
        return this -> Img;
    else
        return -1;
}



void printComplex(Complex C)
{
    if (C.getImg() < 0)
        cout << C.getReal() << "" << C.getImg() << "i" << endl;
    else
        cout << C.getReal() << "+" << C.getImg() << "i" << endl;
}
