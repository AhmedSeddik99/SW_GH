#ifndef STACK_H
#define STACK_H

#include "Node.h"


class Stack
{
    private:
        Node* Stkptr;
        int tos;

    public:

        Stack() {
            ///Stk = new Node(data);
            cout << "Constructor" << endl;
            Stkptr = NULL;
            tos = -1;
        }

        int isEmpty(){
            if(tos == -1){
                return 1;
            }
            return 0;
        }

        void push(int data){
            Node* NewNode = new Node(data);
            tos ++;
            NewNode -> Prev = Stkptr;
            Stkptr = NewNode;
        }


        int pop(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return -1;
            }
            Node* temp;
            temp = Stkptr;
            Stkptr = Stkptr -> Prev;
            delete[] Stkptr;
            tos --;
            return temp -> Data;
        }


        int peek(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return Stkptr -> Data;
        }


        int Display(){
            Node* temp = Stkptr;
            while(temp != NULL) {
                ///cout << "Not Empty" << endl;
                cout << temp -> Data << endl;
                temp = temp -> Prev;
            }
        }


        ~Stack() {
            delete[] Stkptr;
            cout << "Destructor" << endl;
        }

};

#endif // STACK_H
