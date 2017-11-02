/*Read 5 strings of each size 4 into a 2-dimensional character array. Output these strings in the sorted order.
To compare the characters, strcmp() can be used.*/
#include<stdio.h>
#include<string.h>
int main()
{
    char arr[5][5];
    char temp[5];
    int i,j,min;

    printf("Enter the 5 strings one by one\n");

for(i=0; i<5; i++)
{
    scanf("%s",arr[i]);
}

for(i=0; i<5; i++)
    {
        min = i;
for(j=i; j<5; j++)
   {
    if(strcmp(arr[min],arr[j]) > 0)
       {
           min = j;
       }
   }
   strcpy(temp,arr[i]);
   strcpy(arr[i],arr[min]);
   strcpy(arr[min],temp);
}
printf("\nSorted strings:\n");
for(i=0; i<5; i++)
printf("%s\n",arr[i]);
return 0;
}
