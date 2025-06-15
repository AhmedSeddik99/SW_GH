#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
    //How Many Node ?
    //Node node;
    //Node node[?????];
    private:
        Node * head;
        Node * tail;

        Node * getNodeUsingData(int data){
            Node *current = head;
            while(current != NULL){
                if(current-> Data == data){
                    return current;
                }
                //Jump
                current=current->Next;
            }
            return NULL;
        }


    public:
        LinkedList() {
            head=tail=NULL;
        }

        void add(int data){
            //Create Node
            Node * node = new Node(data); //Create Object Node , Data=data , next,prev=null

                if(head == NULL){//First Node
                    head=tail=node;
                    //node->Next=node->prev=NULL;
                }
                else{//Not First Node
                    tail->Next =node; //Old->Next=NewNode
                    node->Prev=tail; //newNode->prev=old(Node)
                    tail=node;//tail=node;
                }
        }

        void display(){
            Node * current = head;//NULL
            if(current == NULL){
                cout<<"Linked List is Empty \n";
                return ;
            }
            while(current != NULL){
                //Display
                cout<<current->Data<<"\t";
                //Increment Jump Node
                current=current->Next;
            }
            cout<<endl;
        }


        void InsertAfter(int data, int afterData) {
            Node* current;
            Node* new_node;

            current = getNodeUsingData(data);
            new_node = new Node(afterData);

            if(current == NULL)
                cout << "Not Found" << endl;
            else {
                if (current == tail) {      /// last Node
                    current -> Next = new_node;
                    new_node -> Prev = current;
                    tail = new_node;
                }

                else {                     /// not last Node
                    new_node -> Next = current -> Next;         /// current -> next = Node was after current
                    (current -> Next) -> Prev = new_node;
                    current -> Next = new_node;
                    new_node -> Prev = current;
                }
            }
        }


        void InsertBefore(int data, int beforeData) {
            Node* current;
            Node* new_node;

            current = getNodeUsingData(data);
            new_node = new Node(beforeData);

            if(current == NULL)
                cout << "Not Found" << endl;
            else {
                if (current == head) {      /// first Node
                    current -> Prev = new_node;
                    new_node -> Next = current;
                    head = new_node;
                }

                else {                     /// not first Node
                    new_node -> Prev = (current -> Prev);         /// current -> prev = Node was before current
                    (current -> Prev) -> Next = new_node;
                    current -> Prev = new_node;
                    new_node -> Next = current;
                }
            }
        }


        int GetCount() {
            int cnt = 0;
            Node * current = head;          /// Start of LinkedList

            if (head == NULL){
                cout << "Linked List is Empty" << endl;
                return 0;
            }
            else {
                while (current != NULL) {
                    cnt ++;
                    current = current -> Next;
                }
                return cnt;
            }
        }


        int GetDataByIndex(int index) {
            Node* current = head;
            int cnt = 0;

            if(current == NULL) {
                cout << "Empty LinkedList" << endl;
                return -1;
            }
            else {
                while (current != NULL) {
                    if (cnt == index) {
                        return current -> Data;
                    }
                    cnt ++;
                    current = current -> Next;
                }
                cout << "Index exceeds the Number of Nodes in the LinkedList" << endl;
                return -1;
            }
        }



        void removeNode(int data){
            //Search Linked List
            Node * node = getNodeUsingData(data);
            if(node == NULL){
                cout<<"Element Not Found , Can't Remove \n";
                return;
            }
            else{
                //Remove First
                if(node == head){
                    if(node == tail){
                        tail=head=NULL;
                    }
                    else{
                        head=node->Next;
                        head->Prev=NULL;
                    }

                }
                else if (node == tail){ //Remove Last
                    tail=node->Prev;
                    tail->Next=NULL;
                }
                else{//Remove Mid
                    Node * A=node->Prev;
                    Node * B=node->Next;
                    A->Next=B;
                    B->Prev=A;
                }

                delete(node);

            }

        }

        int search_using_data(int data){
            Node * node = getNodeUsingData(data);
            if(node == NULL){
                return 0;
            }
            else{
                return 1;
            }
        }
    protected:

};

#endif // LINKEDLIST_H
