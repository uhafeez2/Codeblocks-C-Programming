#include <stdio.h>
#include <string.h>

int main()
{
   char string[10];
   int c = 0, count[26] = {},countLetters=0;
int letter =0;
   printf("Enter a string\n");
  gets(string);
   while (string[c] != '\0')
   {
      if (string[c] >= 'a' && string[c] <= 'z')
         count[string[c]-'a']++;
      c++;
   }

printf("Characters repeated: ");
   for (c = 0; c < 26; c++)
   {
      if ((count[c] != 1)&&(count[c]!=0))
      {
          letter=1;
         printf("%c,",c+'a');
         countLetters++;
    }
   }
    if(!letter)
   {
       printf("no character repeated");
   }
     if (letter)
     {
      printf("\nNumber of characters repeated:\n ");
     }
     else if (!letter)
     {
         printf(" \n");
     }
   for(c=0;c<26;c++)
   {
       if(letter)
       {
           printf("%d\n",countLetters);
           break;
       }
   }
   return 0;
}

/*Write a C program that counts the number of repeated characters in a phrase entered by the user and prints
them. If none of the characters are repeated, then print “No character is repeated”
For example: If the phrase is “full proof” then the output will be
Number of characters repeated: 3
Characters repeated: f, l, o
Note: Assume the length of the string is 10. */
