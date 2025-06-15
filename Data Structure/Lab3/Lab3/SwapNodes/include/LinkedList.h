#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

using namespace std;

template <typename T>
class LinkedList
{
    //How Many Node ?
    //Node node;
    //Node node[?????];
    private:
        Node <T> * head;
        Node <T> * tail;

        Node <T> * getNodeUsingData(T data){
            Node <T> *current = head;
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

        void add(T data){
            //Create Node
            Node <T> * node = new Node <T> (data); //Create Object Node , Data=data , next,prev=null

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
            Node <T> * current = head;//NULL
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

        void SwapNodes(Node <T>* Node1, Node <T>* Node2){
            T temp;
            temp = Node1 -> Data;
            Node1 -> Data = Node2 -> Data;
            Node2 -> Data = temp;
        }

        void bubbleSort(){
            int sorted=0;
            int Size = GetCount();
            Node <T>* current = head;

            for(int j=0; sorted==0; j++){
                sorted=1;
                for(int i=0; i<Size-1-j; i++){
//                    cout << (current -> Data) << endl;
//                    cout << ((current -> Next) -> Data) << endl;
                    if((current -> Data) > ((current -> Next) -> Data)){
                        SwapNodes(current, current -> Next);
                        sorted=0;
                    }
                    current = current-> Next;
                }
                current = head;
            }
        }


        void InsertAfter(T data, T afterData) {
            Node <T>* current;
            Node <T>* new_node;

            current = getNodeUsingData(data);
            new_node = new Node <T>(afterData);

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


        void InsertBefore(T data, T beforeData) {
            Node <T>* current;
            Node <T>* new_node;

            current = getNodeUsingData(data);
            new_node = new Node <T> (beforeData);

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
            Node <T> * current = head;          /// Start of LinkedList

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


        T GetDataByIndex(int index) {
            Node <T> * current = head;
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
            Node <T> * node = getNodeUsingData(data);
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
                    Node <T> * A=node->Prev;
                    Node <T> * B=node->Next;
                    A->Next=B;
                    B->Prev=A;
                }

                delete(node);

            }

        }

        int search_using_data(T data){
            Node <T> * node = getNodeUsingData(data);
            if(node == NULL){
                return 0;
            }
            else{
                return 1;
            }
        }

};

#endif // LINKEDLIST_H
