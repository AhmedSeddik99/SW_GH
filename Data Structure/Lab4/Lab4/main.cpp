#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree tr;

    tr.add(50);
    tr.add(60);
    tr.add(40);
    tr.add(70);
    tr.add(55);
    tr.add(30);
    tr.add(45);
    tr.add(35);
    tr.add(20);
    tr.add(37);



    tr.getMaxDepth();


    return 0;
}
