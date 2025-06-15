#include <iostream>
using namespace std;


class Complex
{
private:
    int Real;
    int Img;


public:
    void setReal(int r)
    {
        Real = r;
    }

    void setImg(int i)
    {
        Img = i;
    }

    int getReal()
    {
        return Real;
    }

    int getImg()
    {
        return Img;
    }



    Complex(int r, int i)
    {
        Real = r;
        Img = i;
        cout << "First Constructor with 2 parameters " << endl;
    }

    Complex(int n)
    {
        Real = Img = n;
        cout << "Second Constructor with 1 parameter " << endl;
    }

    Complex()
    {
        Real = Img = 0;
        cout << "Third Constructor with no parameter " << endl;
    }


    ~Complex()
    {
        cout << "The Destructor" << endl;
    }



    Complex Add_MEM(Complex C2)
    {
        Complex C1;

        int RealAdd, ImgAdd;

        RealAdd = getReal() + C2.getReal();
        ImgAdd  = getImg() + C2.getImg() ;

        C1.setReal(RealAdd);
        C1.setImg(ImgAdd);

        return C1;
    }


    Complex Subtract_MEM(Complex C2)
    {
        Complex C1;

        int RealSub, ImgSub;

        RealSub = getReal() - C2.getReal();
        ImgSub  = getImg()  - C2.getImg() ;

        C1.setReal(RealSub);
        C1.setImg(ImgSub);

        return C1;
    }


    void printComplex(Complex C)
    {
        if (C.getImg() < 0)
            cout << "Complex C = " << C.getReal() << "" << C.getImg() << "i" << endl;
        else
            cout << "Complex C = " << C.getReal() << "+" << C.getImg() << "i" << endl;
    }


};





int main()
{
    Complex C1(3,4), C2(5), C3;
	C3 = C1.Add_MEM(C2);


    return 0;
}


