#include <stdio.h>
#include <stdlib.h>

int reverseNums(int num)
{
    int rev_num = 0;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num;
}

int main()
{
    int num,reverse,addnum;
    printf("Enter a number: ");
    scanf("%d/n",&num);
   reverse = reverseNums(num);
   addnum= num + reverse;
   printf("Sum of the original number + reverse number = %d\n",addnum);


    return 0;
}
