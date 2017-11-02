#include <stdio.h>
#include <string.h>

void printRecords(char **, char **, float *, int);
int addRecord(char **, char **, float *, int);
int deleteRecords(char **, char **, float *, int);
void searchLast(char **, char **, float *, int);
void sortScore(char **, char **, float *, int);
void sortLast(char **, char **, float *, int);
void medianScore(char **, char **, float *, int);

int main()
{
   char **firstName, **lastName;
   float *score;
   int count, choice;
   int i = 0, j = 0;

printf("Please indicate the number of records you want to enter (min 5, max 15):\n");
        scanf("%d", &count);

   //dynamic memory allocation using malloc
   firstName = (char **)malloc(20 * sizeof(char **));
   lastName = (char **)malloc(20 * sizeof(char **));
   score = (float *)malloc(20 * sizeof(float));
   for (i = 0; i < count; i++)
   {
       firstName[i] = (char *)malloc(15 * sizeof(char));
       lastName[i] = (char *)malloc(15 * sizeof(char));

   }
        printf("Please input records of students (enter a new line after each record), with following format: \nfirst name last name score\n");
   for (i = 0; i <count; i++)
   {
       scanf("%s %s %f", firstName[i], lastName[i], &score[i]);
   }


   printf("\n");

   //print menu
   do
   {
       printf("\nPlease select an option from the list below: \n");
                printf("Print records (press 1)\n");
                printf("Add new record (press 2)\n");
                printf("Delete record(s) (press 3)\n");
                printf("Search by last name (press 4)\n");
                printf("Sort by score (press 5)\n");
                printf("Sort by last name (press 6)\n");
                printf("find median score(press 7)\n");
                printf("Exit the program (press 0)\n");
                printf("--------------------------\n\n");
                printf("Enter a value from 0 to 7 to perform a function.\n");
                scanf("%d", &choice);

       switch (choice)
       {
           case 1:
               printRecords(firstName, lastName, score, count);
               break;
           case 2:
               count = addRecord(firstName, lastName, score, count);
               break;
           case 3:
               count = deleteRecords(firstName, lastName, score, count);
               break;
           case 4:
               searchLast(firstName, lastName, score, count);
               break;
           case 5:
               sortScore(firstName, lastName, score, count);
               printRecords(firstName, lastName, score, count);;
               break;
           case 6:
               sortLast(firstName, lastName, score, count);
               printRecords(firstName, lastName, score, count);
               break;
           case 7:
               sortScore(firstName, lastName, score, count);
               medianScore(firstName, lastName, score, count);
               break;
           case 0:
               printf("\nExiting the program\n");
               return 0;
               break;
           default:
               printf("Choice not in Menu ,Exit the program\n");
               break;
       }
   } while (1);
   return 0;
}
//print records
void printRecords(char **firstName, char **lastName, float *score, int count)
{
   int i = 0;
   for (i = 0; i < count; i++)
   {
       printf("First Name: %s, Last Name: %s, Score: %5.2f\n", firstName[i], lastName[i], score[i]);
   }
}
//add new record
int addRecord(char **firstName, char **lastName, float *score, int count)
{
   printf("\nTo add the record, enter the prompted details, one by one.\n");

   firstName[count] = (char *)malloc(15 * sizeof(char));
   lastName[count] = (char *)malloc(15 * sizeof(char));



   printf("Enter first name: ");
   scanf("%s", firstName[count]);
   printf("Enter second name: ");
   scanf("%s", lastName[count]);
   printf("Enter score: ");
   scanf("%f", &score[count]);
   count = count + 1;
   return count;
}

//delete records
int deleteRecords(char **firstName, char **lastName, float *score, int count)
{
   int i = 0;
   int j;
   char *name;
   printf("\nTo delete a record from the list, enter the last name.\n");
   name = (char *)malloc(15 * sizeof(char));
   printf("Enter last name to delete: ");
   scanf("%s", name);
   int counter = count;
   for (i = 0; i < count - 1; i++)
   {
       if (strcmp(lastName[i], name) == 0)
       {
           for(j = i; j<count; j++)
           {
               lastName[j] = lastName[j + 1];
               firstName[j] = firstName[j + 1];
               score[j] = score[j + 1];
           }
           counter--;
       }
   }
   count = counter;
   return count;
}

//search by last name
void searchLast(char **firstName, char **lastName, float *score, int count)
{
   int i = 0;
   char *name;
   name = (char *)malloc(15 * sizeof(char));
   printf("\nTo search a record from the list, enter the last name.\n");
   printf("Enter last name to search: ");
   scanf("%s", name);
   int bool = 0;
   for (i = 0; i < count; i++)
   {
       if (strcmp(lastName[i], name) == 0)
       {
printf("First Name: %10s, Second Name: %10s, Score: %5.2f\n", firstName[i], lastName[i], score[i]);
           bool = 1;
       }
   }
   if (bool == 0)
       printf("Unable to find record.\n");
}

//sort by score
void sortScore(char **firstName, char **lastName, float *score, int count)
{
   char *Ftemp = NULL;
   char *Ltemp = NULL;
   float temp = 0;
   int i, j;
   printf("\nSort the records by their score.\n");
   for (i = 0; i < count; i++)
   {
       for (j = i + 1; j < count; j++)
       {
           if (score[j] < (score[i]))
           {

               Ftemp = firstName[j];
               firstName[j] = firstName[i];
               firstName[i] = Ftemp;

               Ltemp = lastName[j];
               lastName[j] = lastName[i];
               lastName[i] = Ltemp;

               temp = score[j];
               score[j] = score[i];
               score[i] = temp;
           }
       }
   }
}

//sort by last name
void sortLast(char **firstName, char **lastName, float *score, int count)
{
   char *Ftemp = NULL;
   char *Ltemp = NULL;
   float temp = 0;
   int i, j;
   printf("\nSort the records by their last names.\n");
   for (i = 0; i < count; i++)
   {
       for (j = i + 1; j < count; j++)
       {
           if (strcmp(lastName[j], (lastName[i])) < 0)
           {
               Ftemp = firstName[j];
               firstName[j] = firstName[i];
               firstName[i] = Ftemp;

               Ltemp = lastName[j];
               lastName[j] = lastName[i];
               lastName[i] = Ltemp;

               temp = score[j];
               score[j] = score[i];
               score[i] = temp;
           }
       }
   }
}
//median score
void medianScore(char **firstName, char **lastName, float *score, int count)
{
   int median = 0, i;
   if (count % 2 != 0)
   {
       median = count / 2;
       printf("The median score is: %0.2f\n", score[median]);
   }
   else
   {
       median = count / 2;
       printf("The first median score is: %0.2f\n", score[median]);
       printf("The score above the median score is: %0.2f\n", score[median + 1]);
   }
   for (i = 0; i < median; i++)
   {
       printf("First Name: %s, Second Name: %s, Score: %5.2f\n", firstName[i], lastName[i], score[i]);
   }
}
