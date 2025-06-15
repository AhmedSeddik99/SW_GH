#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{
    public:
        Node* Prev;
        int Data;
        Node(int data){
            Data = data;
            Prev = NULL;
        }
};

#endif // NODE_H
