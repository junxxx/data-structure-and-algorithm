#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_integer(char *promt)
{
    int i;
    printf("%s ",promt);
    scanf("%d", &i);
    return i;
}

int is_prime(int number)
{
    if (number <=1) return 0;
    if (number % 2 == 0 && number > 2) return 0;
    for (int i = 3; i <= floor(sqrt(number)); i+= 2)
    {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

void FatalError(char *tips)
{
    printf("%s\n", tips);
    exit(1);
}

void Error(char *s)
{
    printf("%s\n", s);
}

int NextPrime(int number)
{
    while(!is_prime(++number))
    {
        ;
    }

    return number;
}

void swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
