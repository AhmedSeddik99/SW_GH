#include <stdio.h>
#include <stdlib.h>

int main()
{
    char FirstName[10];
    char LastName[10];
    char FullName[20];

    puts("Enter your First Name");
    gets(FirstName);

    puts("Enter your Last Name");
    gets(LastName);

    strcpy(FullName, FirstName);
    strcat(FullName, " ");
    strcat(FullName, LastName);

    puts(FullName);

    return 0;
}
