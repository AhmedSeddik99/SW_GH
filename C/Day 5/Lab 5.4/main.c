#include <stdio.h>
#include <stdlib.h>


struct Employee
{
    int ID;
    char name[20];
    float salary;
    float bonus;
    float deduction;
};

struct Employee AddNewEmployee()
{
    struct Employee e1;

    printf("Enter an employee ID\n");
    scanf("%d", &e1.ID);

    printf("Enter an employee name\n");
    scanf("%s", &e1.name);

    printf("Enter an employee salary\n");
    scanf("%f", &e1.salary);

    printf("Enter an employee bonus\n");
    scanf("%f", &e1.bonus);

    printf("Enter an employee deduction\n");
    scanf("%f", &e1.deduction);

    return e1;
}

void DisplayEmployee(struct Employee e1)
{
    float net_salary = 0;
    float net_bonus = 0;
    float net_deduction = 0;

    net_bonus = (e1.bonus/100)*e1.salary;
    net_deduction = (e1.deduction/100)*e1.salary;

    net_salary = e1.salary + net_bonus - net_deduction;

    printf("Employee: (%d, %s) his net salary = %f", e1.ID, e1.name, net_salary);
}

int main()
{
    struct Employee e1;

    e1 = AddNewEmployee();
    DisplayEmployee(e1);


    return 0;
}
