#include <iostream>

using namespace std;


void swapArray(int & first , int & second){
    int temp=first;
    first=second;
    second=temp;
}

void bubbleSort(int *items,int Size){
    int iterations=0,sorted=0;
    for(int j=0; sorted==0; j++){
        sorted=1;
        for(int i=0; i<Size-1-j; i++){
            if(items[i]>items[i+1]){
                swapArray(items[i],items[i+1]);
                sorted=0;
            }
            iterations++;
        }
    }
}

void LinearSearch(int* Arr, int Element, int Size) {
    int cnt = 0;

    for(int i = 0; i < Size; i++) {
        if(Arr[i] == Element){
           cout << "Index of Element = " << Element << " by Linear Search : " << i << endl;
        }
    }
}



int BinarySearch(int* Arr, int Element, int Size) {
    int Start = 0;
    int End = Size - 1;
    int Mid = (Start + End) / 2;

    while(Start <= End){
        if(Arr[Mid] == Element){
            return Mid;
        }
        else if(Element < Arr[Mid]){             /// Left Side
            End = Mid - 1;
        }
        else if(Element > Arr[Mid]){             /// Right Side
            Start = Mid + 1;
        }

        Mid = (Start + End) / 2;
    }
    return -1;

}




int main()
{
    int Size = 10;
    int Element = 6;
    int Arr1[Size] = {5, 6, 1, 2, 3, 4, 3, 2, 3, 1};
    int Arr2[Size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LinearSearch(Arr1, Element, Size);

    cout << "\n";

    bubbleSort(Arr1, Size);

    cout << "Index of Element = " << Element << " in Array (1) by Binary Search : " << BinarySearch(Arr1, Element, Size) << endl;
    cout << "\n";

    cout << "Index of Element = " << Element << " in Array (2) by Binary Search : " << BinarySearch(Arr2, Element, Size) << endl;
    cout << "\n";


    return 0;
}
