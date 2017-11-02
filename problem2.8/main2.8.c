#include <stdio.h>
#include <stdlib.h>

int checkPrime(int n)
{
    int i, isPrime = 1;

    for(i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

int main()
{
    int num, i, check=0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    for(i = 2; i<= num/2; i++)
    {
        if (checkPrime(i) == 1)
        {
            if (checkPrime(num-i) == 1)
            {
                printf("%d = %d + %d\n", num, i, num - i);
                check = 1;
            }

        }
    }

    if (check == 0)
        printf("%d cannot be expressed as the sum of two prime numbers.", num);

    return 0;
}
