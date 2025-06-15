#ifndef NODE_H
#define NODE_H


template <typename T>
class Node
{
    public:
        Node * Prev,*Next;
        T Data;
        Node(T data){
            Data=data;
            Prev=Next=NULL;
        }
};

#endif // NODE_H
