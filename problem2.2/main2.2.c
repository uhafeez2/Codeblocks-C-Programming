#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 20

int main()
{
    int sortarr[ARRSIZE],target=0,i,j,temp,x,y;
    printf("Please enter 20 sorted integers: ");
    for(i=0; i<ARRSIZE; i++)
    {
        scanf("%d",&sortarr[i]);
    }
    printf("Please enter a target value: ");
    scanf("%d",&target);
int arr_size = 20;
    for(i=0;i<ARRSIZE;i++)
    {
        for(j=i;j<ARRSIZE;j++)
        {
            if(sortarr[i]+sortarr[j]==target)
            {
                temp=1;
                x=sortarr[i];
                y=sortarr[j];
                printf("Pairs that have sum equal to target value %d: %d and %d.\n ",target,x,y);
            }
            else
            {
                temp =0;

            }
        }
    }
if(!temp)
{
printf("No pairs of integers in the given array can be summed to the target value\n");
}

    return 0;
}


/*
Given a sorted array of 20 integers and a target integer value, your program needs to print out all pairs of
integers which have sum equal to the target value. If there is no pair of integers to return, print out “No
pair of integers in the given array can be summed to the target value”. The array of integers and the target
value should be given from the keyboard (taken as user input).*/
