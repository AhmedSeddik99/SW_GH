#include <iostream>

using namespace std;


class Stack
{
	int* StackArr;
	int Tos = 0;
	int Size;

public:
    Stack(const Stack &st);

    Stack(int n);

    Stack();

    ~Stack();

    bool IsFull();

    bool IsEmpty();

    void Push(int element);

    int Pop();

	int Peak();

	Stack Reverse();             //return new stack "with reversed internal array of original stack"

	friend void viewContent(Stack myStack);
};





int main()
{
    /*Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    viewContent(S1);

    cout << "Num = " << S1.Pop() << endl;
    cout << "Num = " << S1.Pop() << endl;
    */

///************* Copy Ctor Case(2): Return by value from function ********************
/*
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    //Stack SS = S1.Reverse();
    //cout<SS.pop();

    cout << S1.Reverse().Pop() << endl;
*/
///************* Copy Ctor Case(3): Create obj in terms of another obj "Explicitly" ********************

    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    Stack S3 ( S1 );

    for(int i=0; i<10; i++)
    S3.Pop();


    for(int i=0; i<10; i++)
        S3.Push(-1);

    cout<<"Num = "<<S1.Pop()<<endl;
    cout<<"Num = "<<S1.Pop()<<endl;



    return 0;
}




Stack :: Stack(const Stack &st)
{
    this -> Size = st.Size;
    this -> Tos = st.Tos;
    StackArr = new int [Size];

    for(int i = 0; i < Size; i++)
    {
        this -> StackArr[i] = st.StackArr[i];
    }
    cout << "The Constructor\n" << endl;
}


Stack :: Stack(int n)
{
    this -> Size = n;
    StackArr = new int [Size];
    this -> Tos = 0;
    cout << "The Constructor\n" << endl;
}

Stack :: Stack()
{
    this -> Size = 5;
    StackArr = new int [Size];
    this -> Tos = 0;
    cout << "The Constructor\n" << endl;
}

Stack :: ~Stack()
{
    delete[]  StackArr;
    cout << "The Destructor\n" << endl;
}

bool Stack :: IsFull()
{
    return (this -> Tos == this -> Size);
}

bool Stack :: IsEmpty()
{
    return (this -> Tos == 0);
}


void Stack :: Push(int element)
{
    if(IsFull() == false)
    {
        this -> StackArr[Tos] = element;
        this -> Tos ++;
    }
    else
        cout << "Stack is Full\n" << endl;
}



int Stack :: Pop()
{
    if(IsEmpty() == false)
    {
        this -> Tos --;
        return this -> StackArr[Tos];
    }
    else
    {
        cout << "Stack is Empty\n" << endl;
        return -1;
    }
}


int Stack :: Peak()
{
    return this -> StackArr[Tos-1];
}


Stack Stack :: Reverse()             //return new stack "with reversed internal array of original stack"
{
    Stack Rvr(this -> Size);
    Rvr.Tos = this -> Tos;

    for (int i = 0; i < Rvr.Tos; i++)
    {
        Rvr.StackArr[i] = this -> StackArr[this -> Tos - 1 - i];
    }

    return Rvr;
};


void viewContent(Stack myStack)
{
    for(int i = 0; i < myStack.Tos; i++)
    {
        cout << myStack.StackArr[i] << endl;
    }
}
