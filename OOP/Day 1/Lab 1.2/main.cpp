#include <iostream>
using namespace std;


struct Complex
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

};



Complex Add_SA(Complex C1, Complex C2);


Complex Subtract_SA(Complex C1, Complex C2);


void printComplex(Complex C);



int main()
{
    Complex C1, C2, C;

    int r1, r2, i1, i2;

    cout << "Enter the first real value"  << endl;
    cin  >> r1;

    cout << "Enter the first img  value"  << endl;
    cin  >> i1;

    cout << "Enter the second real value" << endl;
    cin  >> r2;

    cout << "Enter the second img  value" << endl;
    cin  >> i2;

    C1.setReal(r1);
    C1.setImg(i1);

    C2.setReal(r2);
    C2.setImg(i2);


    C = Add_SA(C1, C2);
    cout << "Addition by Standalone function" << endl;
    printComplex(C);


    C = Subtract_SA(C1, C2);
    cout << "Subtraction by Standalone function" << endl;
    printComplex(C);


    cout << "" << endl;


    C1 = C1.Add_MEM(C2);
    cout << "Addition by Member function" << endl;
    printComplex(C1);

    C1.setReal(r1);
    C1.setImg(i1);

    C1 = C1.Subtract_MEM(C2);
    cout << "Subtraction by Member function" << endl;
    printComplex(C1);



    return 0;
}



Complex Add_SA(Complex C1, Complex C2)
{
    Complex CAdd;

    int RealAdd, ImgAdd;

    RealAdd = C1.getReal() + C2.getReal();
    ImgAdd  = C1.getImg()  + C2.getImg() ;

    CAdd.setReal(RealAdd);
    CAdd.setImg(ImgAdd);

    return CAdd;
};



Complex Subtract_SA(Complex C1, Complex C2)
{
    Complex CSub;

    int RealSub, ImgSub;

    RealSub = C1.getReal() - C2.getReal();
    ImgSub  = C1.getImg()  - C2.getImg() ;

    CSub.setReal(RealSub);
    CSub.setImg(ImgSub);

    return CSub;
}



void printComplex(Complex C)
{
    if (C.getImg() < 0)
        cout << "Complex C = " << C.getReal() << "" << C.getImg() << "i" << endl;
    else
        cout << "Complex C = " << C.getReal() << "+" << C.getImg() << "i" << endl;
}
