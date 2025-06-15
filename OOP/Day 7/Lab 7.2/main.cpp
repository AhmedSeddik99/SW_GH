#include <iostream>

using namespace std;


/*
class Stack
{
    int* stkArr;
    int StkSize;
    int tos;

public:  ///Member Functions

///Copy Constructor Cases:
    ///1- Passing obj by value to function : PrintStack( Stack S);
    ///2- Return obj from function by value:  Stack S1 = myFun();
    ///3- Create obj in terms of another object "Explicitly": Stack S1(S2);
    ///4- Create obj in terms of another object "Implicitly": Stack S1 = S2;   //Not the same as :

    ///Stack S1;
    ///S1 = S2;  //will not call Copy Ctor


    ///Copy Constructor
    Stack( const Stack &St) ///Stack &St = S1;  -- myStk = *this
    {
        this -> tos = St.tos;
        this -> StkSize = St.StkSize;
        ///stkPtr = St.stkPtr;
        stkArr = new int[StkSize];

        for(int i=0; i<tos; i++)    ///deep copying
            this -> stkArr[i] = St.stkArr[i];

        cout<<"\n Am Copy Constrctor :)))))";
    }

    Stack()
    {
        StkSize = 5;
        stkArr = new int [StkSize];  ///Alloacte StkArr dynamically in heap with StkSize
        tos = 0;  ///refer to first empty place to push into
        cout<<"\n I am Stack parameterized Ctor...!";
    }

    Stack(int Sz)
    {
        StkSize = Sz;
        stkArr = new int [StkSize];  ///Alloacte StkArr dynamically in heap with StkSize
        tos = 0;  ///refer to first empty place to push into
        cout<<"\n I am Stack parameterized Ctor...!";
    }

    ~Stack()
    {
        for(int i=0; i<StkSize; i++)
            stkArr[i] = -1;

        delete[] stkArr;
        cout<<"\n I am Stack Destructor...!";
    }

    bool IsFull()
    {
        return (tos == 5);


    }

    void Push(int Value)
    {
        if(IsFull() == false)
            stkArr[tos++] = Value;
        else
            cout<<"\n Stack is Full........!!";
    }

    bool IsEmpty()
    {
        if(tos == 0)
            return true;
        else
            return false;
    }

    int Pop()
    {
        if(IsEmpty() == false)
            return stkArr[--tos];
        else
        {
            cout<<"\n Stak is Empty....!!";
            return -1;
        }
    }

    ///Return by value
    Stack Reverse()
    {
        cout<<"\n Reversing....";

        Stack Rvs(this -> StkSize);  ///Ctor with 1 param

        Rvs.tos = this -> tos;      /// = Rvs.tos = (*this).tos;

        for(int i=0; i<tos; i++)
            Rvs.stkArr[i] = stkArr[tos-i-1];

        return Rvs;
    }

    friend void PrintStack(Stack myStk);  /// PrintStack is standAlone but it is a Friend to class stack
                                        /// Si , it can access all private data of the class
};

///StandAlone Function
void PrintStack(Stack myStk)  ///Stack myStk = S1 ///Pass by value
{
    for(int i=0; i<myStk.tos; i++)
        cout<<"\n Value = "<<myStk.stkArr[i];
}

int main()
{


    ///************* Copy Ctor Case(1): Pass by value to function ********************
/*
    Stack S1(4);

    S1.Push(11);
    S1.Push(12);
    S1.Push(13);

    PrintStack(S1);   ///Call by value --> will call Copy Ctor

    cout<<"\n Poped Value = "<<S1.Pop();
    cout<<"\n Poped Value = "<<S1.Pop();

*/
    ///************* Copy Ctor Case(2): Return by value from function ********************
/*
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    /// Stack SS = S1.Reverse();  /// (returned RVS ... Stack SS = Rvs; ) without CpyCtor
    Stack SS = S1.Reverse();  /// (returned temp ... Stack SS = temp; )  with CopyCtor
    ///Stack SS = Temp;
    cout<<SS.Pop();

    //cout<<S1.Reverse().pop();

*/


    /*
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);

    cout<<"\n Poped Value = "<<S1.Pop();
     cout<<"\n Poped Value = "<<S1.Pop();
     cout<<"\n Poped Value = "<<S1.Pop();
     cout<<"\n Poped Value = "<<S1.Pop();
*/
/*
     Stack S2(7);

    S2.Push(11);
    S2.Push(12);
    S2.Push(13);
    S2.Push(14);


    cout<<"\n Poped Value = "<<S2.Pop();
     cout<<"\n Poped Value = "<<S2.Pop();
     cout<<"\n Poped Value = "<<S2.Pop();
     cout<<"\n Poped Value = "<<S2.Pop();
     cout<<"\n Poped Value = "<<S2.Pop();
*/
  /*  return 0;
}
*/



/*
class Nice {
    int a;
public:
    Nice() { a = 0; }
    Nice(Nice &myN) {
        this->a = myN.a;
        cout << "I am the copy constructor" << endl;
    }
    void setA(int m) {
        a = m;
    }
    int getA() { return a; }
};

void show(Nice &obj) {
    cout << "I am the show function, value is: " << obj.getA() << endl;
}

int main() {
    Nice n1;
    n1.setA(15);
    show(n1);
    return 0;
}
*/

/*
class Parent
{
public:
    int x;




    ~Parent()
    {
        //cout << "\n Parent Destructor";
    }

    void MyMethod()
    {
        cout << "Parent Method" << endl;
    }
};



int main()
{
    Parent Pnt();

//    cout << Pnt.x << endl;
//    Pnt.MyMethod();

    return 0;
}
*/



class Parent
{
public:
    int x;

    Parent(int n)
    {
        x = n;
    }

    Parent()
    {
        x = 0;
    }

    ~Parent()
    {
        //cout << "\n Parent Destructor";
    }

    virtual void MyMethod()

    {
        cout << " Parent Method" << endl;
    }
};


class Child : public Parent
{
public:
    int y;

    Child(int n)
    {
        y = n;
    }

    Child()
    {
        y = 0;
    }

    ~Child()
    {
        //cout << "\n Child Destructor";
    }

    void MyMethod()
    {
        cout << " Child Method" << endl;
    }
};


class GrandChild : public Child
{
public:
    int y;

    GrandChild(int n)
    {
        y = n;
    }

    GrandChild()
    {
        y = 0;
    }

    ~GrandChild()
    {
        //cout << "\n Grand Child Destructor";
    }

    void MyMethod()
    {
        cout << " Grand Child Method" << endl;
    }
};





int main()
{

    Parent Pnt(3);
    Child Chd;
    GrandChild GdChd(7);

    Parent* Pntptr;
    Child* Chdptr ;
    GrandChild* GdChdptr;

    Pntptr = &Pnt;


    cout << "PntPtr -> x = " << Pntptr -> x << endl;
    ///cout << "PntPtr -> y = " << Pntptr -> y << endl;            /// error

    cout << "P.MyMethod: ";
    Pnt.MyMethod();

    cout << "Pntptr -> Parent: ";
    Pntptr -> MyMethod();

    Pntptr = &Chd;
    cout << "Pntptr -> Child: ";
    Pntptr -> MyMethod();

    Pntptr = &GdChd;
    cout << "Pntptr -> Grand Child: ";
    Pntptr -> MyMethod();


    Chdptr = &GdChd;
    cout << "Chdptr -> Grand Child: ";
    Chdptr -> MyMethod();

    /// error
    ///Chdptr = &Pnt;
    ///cout << "Chdptr -> Parent: ";
    ///Chdptr -> MyMethod();





    return 0;
}

