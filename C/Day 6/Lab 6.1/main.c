#include <stdio.h>
#include <stdlib.h>



void swapValues(int* x, int* y);

int main()
{
    int A = 5;
    int B = 9;

    printf("Before swap: A = %d, B = %d\n", A, B);

    swapValues(&A, &B);

    printf("After swap: A = %d, B = %d\n", A, B);
    return 0;
}


void swapValues(int* x, int* y)
{
  int temp;

  temp = *x;

  *x = *y;

  *y = temp;
};
