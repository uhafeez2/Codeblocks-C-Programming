#include <stdio.h>
#include <stdlib.h>

int n,i=1,j=1;
void f(int i)
{
    if (i==n)
    {
        printf("\The nth value is: %d",j);
        exit(1);
    }
    else
    {
    j = (j*j)+1;
     printf("%d\n",j);
     i++;

     f(i);
    }

}

int main()
{

    printf("Enter nth value: ");
    scanf("%d",&n);
    printf("Series: \n");
    printf("%d\n",i);
   f(i);

}





/*Given the following series: 1 2 5 26 677 ….. such that the nth term of the series equals to (n-1)th ^2 +1
and the first term of the series is 1. Write a program using recursive function named f to compute the nth
term. Use for loop to print the values of first n terms in the series. You will take input n from the user. */
