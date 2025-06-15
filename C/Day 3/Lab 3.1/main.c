#include <stdio.h>
#include <stdlib.h>

#define length 5

int main()
{
    int arr[length];
    int i;

    // Inputting
    for(i = 0; i < length; i++)
    {
        printf("Enter the values of the element number %d\n", i+1);
        scanf("%d", &arr[i]);
    }


    // Outputting
    for(i = 0; i < length; i++)
    {
        printf("The value of the element number (%d) = %d\n", i, arr[i]);
    }

    return 0;
}
