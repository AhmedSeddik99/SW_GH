#include <stdio.h>
#include <stdlib.h>

int main() // C Program to make simple calculations (add, sub, multiply, divid) on two integers
{
    int num1, num2;
    printf("Enter the first number\n");
    scanf("%d", &num1);
    printf("Enter the second number\n");
    scanf("%d", &num2);
    printf("The sum of the two numbers = %d\n", (num1 + num2));
    printf("The subtraction of the two numbers = %d\n", (num1 - num2));
    printf("The multiplication of the two numbers = %d\n", (num1 * num2));
    printf("The division of the two numbers = %d\n", (num1 / num2));
    return 0;
}
