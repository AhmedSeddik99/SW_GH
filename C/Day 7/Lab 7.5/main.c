#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

/*
int main()
{
  int flag=0,i,space;
  int cur=0;
  char str;
  //char arr[20]="";

    printf("enter sentence: \n\n");
    printf("enter number of space you want\n");
    scanf("%d",&space);
    char* arr=malloc(space*sizeof(char));

    gotoxy(15,15);
    textattr(0x41);

    for(i=0;i<space;i++)
    {
        printf(" ");
        arr[i]=' ';
    }
    arr[space] = '\0';

    do{

     if(cur>=space)
        cur=space-1;
      if(cur<0)
        cur=0;


     gotoxy((15+cur),15);

     str=getch();
     if(str>='a' && str<='z' ||str==' ')
     {
          arr[cur]=str;
     printf("%c",str);

     }


    switch(str){
        default : cur++;
                  break;

    case 8:                    ///backspace
                if(cur>0){
                cur--;
                for(i=cur;i<space;i++){
               arr[i] = arr[i+1]; //
                 gotoxy(15 + i, 15);
                  printf("%c",arr[i+1]);
                }
                }
             break;




    case 13:
    case 27: flag=1;
              break;
    case -32:
    case 0:
    case 224: str=getch();
    switch(str){                ///extended

    case 71:    cur=0;                   //home

                break;
    case 83 :                               ///delete
           for(i=cur;i<space;i++){
           arr[i] = arr[i+1]; //
            gotoxy(15 + i, 15);
           printf("%c",arr[i+1]);
                }
             break;
    case 75:   cur--;         // <------
               break;

    case 79:   cur=space-1;                 //   end
               break;
    case 77:  cur++;
               break;                 //        ---->


               break;
    }






    }



    }
    while(flag==0);
     textattr(0x07);
   clrscr();
  printf("the sentence is %s",arr);


    textattr(0x07);
    printf("\n");
    free(arr);

    return 0;
}

*/


int main()
{
    char ch;
    char* sentence;

    int i, n;
    int cnt = 0;
    int current = 0;
    int flag = 0;

    printf("Enter the length of line editor\n");
    scanf("%d", &n);


    sentence = malloc(n * sizeof(char));


    for(i = 0; i < n; i++)
    {
        textattr(0X40);
        gotoxy(i+3, 15);
        printf(" ");
        sentence[i] = 32;
    }


    sentence[n] = '\0';

    gotoxy(3, 15);

    do
    {
            ch = getch();
            switch(ch)
            {
                case -32:
                case 0:
                case 224:

                    ch = getch();
                    switch(ch)
                    {
                        case 75:    current--;                      // Left
                                    if(current < 0)
                                        current = (n-1);
                                    gotoxy(current+3, 15);
                                    break;

                        case 77:    current++;                      // Right
                                    if(current == n)
                                        current = 0;
                                    gotoxy(current+3, 15);
                                    break;

                        case 71:    current = 0;                    // Home
                                    gotoxy(current+3, 15);
                                    break;

                        case 79:    current = (n-1);               // End
                                    gotoxy(current+3, 15);
                                    break;

                        case 83:    gotoxy(current+3, 15);          // Delete
                                    for(i = current; i < n; i++)
                                    {
                                        sentence[i] = sentence[i+1];
                                    }
                                    gotoxy(3, 15);
                                    printf("%s", sentence);
                                    gotoxy((cnt-1)+3, 15);
                                    printf(" ");
                                    gotoxy(current+3, 15);
                                    break;
                    }

                break;

                case  8:            current --;
                                    gotoxy(current+3, 15);          // BackSpace
                                    for(i = current; i < n; i++)
                                    {
                                        sentence[i] = sentence[i+1];
                                    }
                                    gotoxy(3, 15);
                                    printf("%s", sentence);
                                    gotoxy((cnt-1)+3, 15);
                                    printf(" ");
                                    gotoxy(current+3, 15);
                                    break;


                case 13:                                        // Enter
                case 27:
                            flag = 1;                           // Esc
                            break;


                default:    gotoxy(current+3, 15);
                            printf("%c", ch);
                            sentence[current] = ch;
                            //temp[current] = ch;
                            current ++;
                            cnt++;
                            if(current == n)
                            {
                                current = 0;
                            }
            }
    }
    while(flag != 1);

    textattr(0X07);
    clrscr();

    printf("Sentence: %s",sentence);

    free(sentence);
    return 0;
}

