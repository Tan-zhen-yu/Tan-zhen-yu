#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int f(int x)

{
    int c = x;
    int  a = 0;

    for (a = 2; a < x; a++); 
    {
      ​ ​if(c%a==0)
      {
          return 0;
          }

      ​    ​    

     

​ }

    return 1;

}



int main()

{
    int i = 0, j = 0;

    printf("2 ");

    for (i = 3; i <= 100; i++)

    {

        if (f(i))
        {
            printf("%d", i);
            }

    }


    return 0;

}