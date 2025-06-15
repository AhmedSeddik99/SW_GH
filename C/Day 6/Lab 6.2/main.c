#include <stdio.h>
#include <stdlib.h>


int printArr(int* ptr);


int main()
{
    int i;
    int arr[5];

    //int* ptr;
    //ptr = arr;

    for(i = 0; i < 5; i++)
    {
        printf("Enter the element number (%d)\n", i);
        scanf("%d", &arr[i]);
    }

    printArr(arr);

    return 0;
}


int printArr(int* ptr)
{
    int i;
    int sum = 0;

    for(i = 0; i < 5; i++)
    {
        printf("Element number (%d): %d\n", i, *(ptr + i));
        sum += *(ptr + i);
    }

    printf("Summation of array elements = %d\n", sum);

};
