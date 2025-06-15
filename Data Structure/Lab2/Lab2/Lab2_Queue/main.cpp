#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue Q(5);

    Q.EnQueue(11);
    Q.EnQueue(12);
    Q.EnQueue(13);
    Q.EnQueue(14);
    Q.EnQueue(15);

    cout << "Front of the Queue = " << Q.GetFront() << endl;
    cout << "Rear of the Queue = " << Q.GetRear() << endl;
    cout <<"\n\n";

    Q.EnQueue(16);               /// Queue is Full
    cout <<"\n\n";


    Q.Display();
    cout <<"\n\n";


    Q.DeQueue();
    Q.DeQueue();

    Q.Display();
    cout <<"\n\n";


    cout << "Front of the Queue = " << Q.GetFront() << endl;
    cout << "Rear of the Queue = " << Q.GetRear() << endl;
    cout <<"\n\n";

    Q.EnQueue(16);
    Q.EnQueue(17);
    Q.EnQueue(18);
    Q.EnQueue(19);
    Q.Display();
    cout <<"\n\n";


    cout << "Front of the Queue = " << Q.GetFront() << endl;
    cout << "Rear of the Queue = " << Q.GetRear() << endl;
    cout <<"\n\n";

    return 0;
}
