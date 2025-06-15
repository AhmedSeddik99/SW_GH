#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, limit;

    printf("Enter a number to generate a Multiplication Table\n");
    scanf("%d", &num);

    printf("Enter the limit of the Multiplication Table\n");
    scanf("%d", &limit);

    for(i = 0; i <= limit; i++)
    {
        printf("%d * %d = %d\n", num, i, num*i);
    }

    return 0;
}
