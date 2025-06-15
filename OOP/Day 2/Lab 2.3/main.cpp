#include <iostream>

using namespace std;


class Stack
{
	int* StackArr;
	int Tos = 0;
	int Size;

public:
    Stack(int n)
    {
        Size = n;
        StackArr = new int [Size];
        cout << "The Constructor\n" << endl;
        Tos = 0;
    }

    ~Stack()
    {
        delete[] StackArr;
        cout << "The Destructor\n" << endl;
    }

    bool IsFull()
    {
        return (Tos == Size);
    }

    bool IsEmpty()
    {
        return (Tos == 0);
    }


    void Push(int element)
    {
        if(IsFull() == false)
        {
            StackArr[Tos] = element;
            Tos ++;
        }
        else
            cout << "Stack is Full\n" << endl;
    }



    int Pop()
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


	int Peak()
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


	/*void PrintStack()
	{

	}*/
};





int main()
{
	Stack S1(5);

	S1.Push(10);
	S1.Push(20);
	S1.Push(30);

	cout<< S1.Peak() << endl;       //30
	cout<< S1.Peak() << endl;       //30

	cout<< S1.Pop()  << endl;       //30
	cout<< S1.Pop()  << endl;       //20



	Stack S2(5);


	S2.Push(11);
	S2.Push(12);
	S2.Push(13);
	S2.Push(14);
	S2.Push(15);


    cout << S2.Reverse().Pop() << endl;

    return 0;
}
