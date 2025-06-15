#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

class Queue
{
    int Size;
    int* Q;
    int Front, Rear;

    public:
        Queue(int n) {
            Size = n;
            Q = new int [Size];
            Front = Rear = 0;
            cout << "Constructor" << endl;
        }


        bool isFull() {
            return (Rear == Size);
        }


        bool isEmpty() {
            return (Front == Rear);
        }


        void EnQueue(int data){
            if(isFull())
                cout << "Queue is Full, Can't add data = "  << data << endl;

            else {
                Q[Rear] = data;
                Rear ++;
            }
        }


        int DeQueue(){
            int Data;

            if(isEmpty())
                cout << "Queue is Empty" << endl;

            else {
                Data = Q[Front];

                for(int i = 0; i < Rear; i++){
                    Q[i] = Q[i+1];
                }

                Rear --;
            }
            return Data;
        }


        int GetFront() {
            if(isEmpty()){
                cout << "Queue is Empty" << endl;
                return -1;
            }

            return Q[Front];
        }


        int GetRear() {
            if(isEmpty()){
                cout << "Queue is Empty" << endl;
                return -1;
            }

            return Q[Rear-1];           /// (Rear - 1) Since Rear is pointing to last empty index
        }


        void Display(){
            if(isEmpty())
                cout << "Queue is Empty" << endl;

            else {
                for (int i = 0; i < Rear; i++) {
                    cout << "Element number: " << (i+1) << " = " << Q[i] << endl;
                }
            }
        }



        ~Queue() {
            cout << "Destructor" << endl;
            delete[] Q;
        }

};

#endif // QUEUE_H
