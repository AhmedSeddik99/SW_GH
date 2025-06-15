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

};


void printComplex(Complex C);



int main()
{
    Complex C1(3,4), C2(5), C3;
    C3 = C1.Add(C2);



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
    cout << "Copy Constructor " << endl;
}

Complex :: Complex(int r, int i)
{
    this -> Real = r;
    this -> Img = i;
    cout << "First Constructor with 2 parameters " << endl;
}

Complex :: Complex(int n)
{
    this -> Real = Img = n;
    cout << "Second Constructor with 1 parameter " << endl;
}

Complex :: Complex()
{
    this -> Real = Img = 0;
    cout << "Third Constructor with no parameter " << endl;
}

Complex :: ~Complex()
{
    cout << "The Destructor" << endl;
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


void printComplex(Complex C)
{
    if (C.getImg() < 0)
        cout << "Complex C = " << C.getReal() << "" << C.getImg() << "i" << endl;
    else
        cout << "Complex C = " << C.getReal() << "+" << C.getImg() << "i" << endl;
}
