#include <stdio.h>
#include <stdlib.h>


int* IncrArray();



int main()
{
    int i;

    int* Arr;

    Arr = IncrArray();

    for(i = 0; i < 5; i++)
    {
        printf("The element no.(%d) of the array = %d\n", i, *(Arr + i));
    }

    free(Arr);
    return 0;
}



int* IncrArray()
{
    int i, n;

    //int Arr[5];

    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);

    int* Arr = malloc(n*sizeof(int));

    printf("Enter the elements of the array\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
        Arr[i]+= 10;
    }

    return Arr;
}





