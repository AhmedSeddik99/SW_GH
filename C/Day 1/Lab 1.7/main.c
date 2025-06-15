#include <stdio.h>
#include <stdlib.h>

int main() // C Program to compute Quotient and Remainder
{
    int num1, num2, Quotient, Remainder;
    printf("Enter the first number\n");
    scanf("%d", &num1);
    printf("Enter the second number\n");
    scanf("%d", &num2);
    
    Quotient = num1/num2;
    Remainder = num1 % num2;
    printf("The Quotient = %d & The Remainder = %d\n", Quotient, Remainder);
    return 0;
}
