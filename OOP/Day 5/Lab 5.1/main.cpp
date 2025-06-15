#include <iostream>

using namespace std;

template <typename T>
void Swap(T& x, T& y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}

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
        //cout << "First Constructor with 2 parameters " << endl;
    }

    Complex(int n)
    {
        Real = Img = n;
        //cout << "Second Constructor with 1 parameter " << endl;
    }

    Complex()
    {
        Real = Img = 0;
        //cout << "Third Constructor with no parameter " << endl;
    }


    ~Complex()
    {
        //cout << "The Destructor" << endl;
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

template <typename T>
class Stack
{
	T* StackArr;
	int Tos = 0;
	int Size;

public:
    Stack(int n)
    {
        Size = n;
        StackArr = new T [Size];
        //cout << "The Constructor\n" << endl;
        Tos = 0;
    }

    ~Stack()
    {
        delete[] StackArr;
        //cout << "The Destructor\n" << endl;
    }

    bool IsFull()
    {
        return (Tos == Size);
    }

    bool IsEmpty()
    {
        return (Tos == 0);
    }


    void Push(T element)
    {
        if(IsFull() == false)
        {
            StackArr[Tos] = element;
            Tos ++;
        }
        else
            cout << "Stack is Full\n" << endl;
    }



    T Pop()
    {
        if(IsEmpty() == false)
        {
            Tos --;
            return StackArr[Tos];
        }
        else
        {
            cout << "Stack is Empty\n" << endl;
            return -1;
        }
    }


	T Peak()
	{
        return StackArr[Tos-1];
	}


	Stack Reverse()             //return new stack "with reversed internal array of original stack"
	{
	    Stack Rvr(5);
	    int i;
	    int cnt = 0;

        for (i = Tos-1; i >= 0; i--)
        {
            Rvr.Push(StackArr[i]);
        }

        return Rvr;
	};

};


void printComplex(Complex C)
    {
        if (C.getImg() < 0)
            cout << "Complex C = " << C.getReal() << "" << C.getImg() << "i" << endl;
        else
            cout << "Complex C = " << C.getReal() << "+" << C.getImg() << "i" << endl;
    }


int main()
{
    int a = 3, b = 5;
    Swap <int> (a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1 = 'Z', Ch2 = 'O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;

    Complex C1(5), C2(2,7);


    cout<<"\nComplex1 Before Swap: "<<endl;
    printComplex(C1);

    cout<<"\nComplex2 Before Swap: "<<endl;
    printComplex(C2);

    Swap<Complex>(C1, C2);

    cout<<"\nComplex1 After Swap: "<<endl;
    printComplex(C1);

    cout<<"\nComplex2 After Swap: "<<endl;
    printComplex(C2);


    cout<< endl;

    Stack<int> S(5);
    S.Push(10);
    S.Push(20);
    cout<< S.Pop();
    cout<< endl;


    Stack<char> S2(3);
    S2.Push('A');
    S2.Push('B');
    S2.Push('C');
    cout<< S2.Pop();
    cout<< endl;

    Stack<Complex> S3(4);
    S3.Push(C1);
    S3.Push(C2);
    Complex C = S3.Pop();
    printComplex(C);


    return 0;
}


