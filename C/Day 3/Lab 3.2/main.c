#include <stdio.h>
#include <stdlib.h>

#define length 5

int main()
{
    int arr[length] = {3, 4, 2, 9, 1};
    int Min = arr[0];
    int Max = arr[0];

    int i;

    for(i = 0; i < length; i++)
    {
        if(Min > arr[i])
        {
            Min = arr[i];
        }
        if(Max < arr[i])
        {
            Max = arr[i];
        }
    }

    printf("The Minimum value of the array = %d\n", Min);
    printf("The Maximum value of the array = %d\n", Max);

    return 0;
}
