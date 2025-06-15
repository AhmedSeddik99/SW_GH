#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

#define no_departments 3
#define no_employees 3


struct Employee
{
    int ID;
    char name[20];
    float salary;
    float bonus;
    float deduction;
};


struct Depart
{
    int ID;
    char name[20];
    struct Employee DepartArr[no_employees];
};


struct Employee AddNewEmployee()
{
    struct Employee e1;

    printf("Enter an employee ID\n");
    scanf("%d", &e1.ID);

    printf("Enter an employee name\n");
    _flushall();
    scanf("%s", &e1.name);

    printf("Enter an employee salary\n");
    scanf("%f", &e1.salary);

    printf("Enter an employee bonus\n");
    scanf("%f", &e1.bonus);

    printf("Enter an employee deduction\n");
    scanf("%f", &e1.deduction);

    return e1;
}


struct Depart AddNewDepart()
{
    struct Depart d1;

    int i;

    printf("Enter a department ID\n");
    scanf("%d", &d1.ID);

    printf("Enter a department name\n");
    _flushall();
    scanf("%s", &d1.name);

    printf("----------------------------------------------\n");
    for(i = 0; i < no_employees; i++)
    {
        printf("Enter the data of employee no.(%d)\n", i);
        d1.DepartArr[i] = AddNewEmployee();
        printf("_________________________________________\n");
    }

    return d1;
}



void DisplayDepart(struct Depart d1)
{
    float net_salary = 0;
    float net_bonus = 0;
    float net_deduction = 0;

    int i;

    printf("Department: (%d, %s) \n", d1.ID, d1.name);

    for(i = 0; i < no_employees; i++)
    {
        net_bonus = (d1.DepartArr[i].bonus/100)*d1.DepartArr[i].salary;
        net_deduction = (d1.DepartArr[i].deduction/100)*d1.DepartArr[i].salary;

        net_salary = d1.DepartArr[i].salary + net_bonus - net_deduction;

        printf("Employee: (%d, %s) his net salary = %f\n", d1.DepartArr[i].ID, d1.DepartArr[i].name, net_salary);
    }
    printf("__________________________________________________________________________________\n");
}

int main()
{
    char ch;
    char menu[6][12] = {"New", "Display", "Display All", "Delete", "Delete All", "Exit"};

    int i;
    int current = 0;
    int flag = 0;
    int idx = 0;
    int cnt = 0;
    int no_emp_flag = 0;
    int idxArr[no_employees] = {-2, -2, -2, -2, -2};


    struct Depart DepartArr[no_departments];

    do
    {
        textattr(0X07);
        clrscr();

        for(i = 0; i < 6; i++)
        {
            if(current == i)
                textattr(0X70);
            else
                textattr(0X07);

            gotoxy(15, 4*i+3);
            printf(menu[i]);
        }

            ch = getche();
            switch(ch)
            {
                case -32:
                case 0:
                case 224:

                    ch = getche();
                    switch(ch)
                    {
                        case 72:    current--;              // Up
                                    if(current < 0)
                                        current = 5;
                                    break;

                        case 80:    current++;              // Down
                                    if(current > 5)
                                        current = 0;
                                    break;

                        case 71:    current = 0;            // Home
                                    break;

                        case 79:    current = 2;            // End
                                    break;
                    }

                break;

                case 27:    flag = 1;                   // Esc
                            break;

                case 9:     break;

                case 13:    switch(current)
                            {
                                case 0: clrscr();
                                        printf("\t\t\t *** New Employee ***\n");
                                        printf("Enter the index of the new Department\n");
                                        scanf("%d", &idx);
                                        if(idx >= no_departments || idx < 0)
                                        {
                                            printf("The index of the Department should be between 0 & %d\n", no_departments-1);
                                        }
                                        else
                                        {
                                            DepartArr[idx] = AddNewDepart();
                                            idxArr[cnt] = idx;
                                            cnt ++;
                                        }
                                        getche();
                                        break;


                                case 1: clrscr();
                                        printf("Enter the index of the Department to be displayed\n");
                                        scanf("%d", &idx);
                                        if(idx >= no_departments || idx < 0)
                                            printf("The index of the Department should be between 0 & %d\n", no_departments-1);
                                        else
                                        {
                                            for(i = 0; i < no_departments; i++)
                                            {
                                                if(idx == idxArr[i])
                                                {
                                                    printf("\t\t\t *** Display Department no.(%d) ***\n", idx);
                                                    DisplayDepart(DepartArr[idx]);
                                                    no_emp_flag = 0;
                                                    break;
                                                }
                                                else
                                                    no_emp_flag = 1;
                                            }
                                            if(no_emp_flag == 1)
                                            {
                                                printf("\t\t\t *** No Department with this index to be displayed ***\n");
                                            }
                                        }

                                        getche();
                                        break;


                                case 2: clrscr();
                                        printf("\t\t\t *** Display All ***\n");
                                        for(i = 0; i < cnt; i++)
                                        {
                                            if(idxArr[i] != -2)
                                            {
                                                printf("Department no.(%d)", idxArr[i]);
                                                DisplayDepart(DepartArr[idxArr[i]]);
                                            }
                                        }
                                        getche();
                                        break;


                                case 3: clrscr();
                                        printf("Enter the index of the Department to be deleted\n");
                                        scanf("%d", &idx);
                                        if(idx >= no_departments || idx < 0)
                                        {
                                            printf("The index of the Department should be between 0 & %d\n", no_departments-1);
                                        }
                                        else
                                        {
                                            for(i = 0; i < no_departments; i++)
                                            {
                                                if(idx == idxArr[i])
                                                {
                                                    printf("\t\t\t *** Delete Department no.(%d) ***\n", idx);
                                                    idxArr[i] = -2;
                                                    no_emp_flag = 0;
                                                    break;
                                                }
                                                else
                                                    no_emp_flag = 1;
                                            }
                                            if(no_emp_flag == 1)
                                            {
                                                printf("\t\t\t *** No Department with this index to be deleted ***\n");
                                            }
                                        }
                                        getche();
                                        break;

                                case 4: clrscr();
                                        printf("\t\t\t *** All Departments have been deleted ***\n");
                                        for(i = 0; i < no_departments; i++)
                                        {
                                            idxArr[i] = -2;
                                        }
                                        getche();
                                        break;

                                case 5: flag = 1;
                                        break;

                            }
            }
        }
        while(flag != 1);

    return 0;
}
