#include <iostream>
#include "LinkedList.h"

using namespace std;


int main()
{
    LinkedList <int> myList;

    myList.add(1);
    myList.add(5);
    myList.add(3);
    myList.display();                     /// 1       5       3

    myList.InsertAfter(3, 2);
    myList.display();                    /// 1       5       3       2

    myList.InsertBefore(1, 7);
    myList.display();                   /// 7       1       5       3       2


    myList.bubbleSort();
    myList.display();

    return 0;
}
