#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int sum = 0;

    while(sum < 100)
    {
        printf("Enter a number\n", N);
        scanf("%d", &N);
        sum += N;
    }
    printf("sum = %d", sum);
    return 0;
}
