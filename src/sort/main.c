#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void print_array(int a[], unsigned int n)
{
    for(int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
}

int main()
{
    int i, test[10];
    time_t t;
    srand((unsigned)time(&t));
    for (i = 0; i < 10; i++)
    {
        test[i] = rand() % 100;
    }
    //init random array
    print_array(test, 10);
    insertion_sort(test, 10);
    print_array(test, 10);
    for (i = 0; i < 10; i++)
    {
        test[i] = rand() % 100;
    }
    print_array(test, 10);
    shell_sort(test, 10);
    print_array(test, 10);
    return 0;
}
