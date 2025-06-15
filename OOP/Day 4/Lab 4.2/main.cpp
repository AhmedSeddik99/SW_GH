#include <iostream>

using namespace std;


class Stack
{
	int* StackArr;
	int Tos = 0;
	int Size;

    static int counter;



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

	Stack operator = (const Stack &st);

	Stack operator + (const Stack &st);

	friend void viewContent(Stack myStack);

	static int get_Counter()
    {
        return counter;
    }
};

int Stack :: counter = 0;




int main()
{
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);



    Stack S2;

    S2.Push(11);
    S2.Push(12);
    S2.Push(13);
    S2.Push(14);


//    viewContent(S1);
//    cout << "___________________" << endl;
//    viewContent(S2);

    Stack S3;

    cout << "Counter = " << Stack :: get_Counter() << endl << endl;



    cout << "------------------" << endl;

    S3 = S1 + S2;
    cout << "S1 + S2: " << endl; //viewContent(S3);

    cout << "------------------" << endl << endl;

    S1 = S2;
    cout << "S1 = S2: " << endl; //viewContent(S1);
    cout << "------------------" << endl;

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
    counter ++;
    cout << "Copy Constructor\n" << endl;
}


Stack :: Stack(int n)
{
    this -> Size = n;
    StackArr = new int [Size];
    this -> Tos = 0;
    counter ++;
    cout << "1 Parameter Constructor\n" << endl;
}

Stack :: Stack()
{
    this -> Size = 5;
    StackArr = new int [Size];
    this -> Tos = 0;
    counter ++;
    cout << "Parameterless Constructor\n" << endl;
}

Stack :: ~Stack()
{
    delete[]  StackArr;
    counter --;
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


Stack Stack :: operator = (const Stack &st)
{
    this -> Size = st.Size;
    this -> Tos = st.Tos;
    delete[] this -> StackArr;
    StackArr = new int[this -> Size];

    for(int i = 0; i < this -> Tos; i++)
    {
        this -> StackArr[i] = st.StackArr[i];
    }

    return *this;
}


Stack Stack :: operator + (const Stack &st)         /// this -> S1, st -> S2
{
    Stack S_Tot;
    S_Tot.Size = this -> Size + st.Size;
    S_Tot.Tos  = this -> Tos  + st.Tos;
    delete[] S_Tot.StackArr;
    S_Tot.StackArr = new int[S_Tot.Size];

    for(int i = 0; i < this -> Tos; i++)
    {
        S_Tot.StackArr[i] = this -> StackArr[i];
    }

    for(int i = this -> Tos; i < S_Tot.Tos; i++)
    {
        S_Tot.StackArr[i] = st.StackArr[i - this -> Tos];
    }

    return S_Tot;
}

void viewContent(Stack myStack)
{
    for(int i = 0; i < myStack.Tos; i++)
    {
        cout << myStack.StackArr[i] << endl;
    }
}
