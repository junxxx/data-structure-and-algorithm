#include <stdio.h>
#include "sort.h"

void print_array(int a[], unsigned int n)
{
    for(int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
}

int main()
{
    int test[10] = {92, 43, 14, 51, 84, 48, 32, 54, 23, 19};
    print_array(test, 10);
    insertion_sort(test, 9);
    print_array(test, 10);
    return 0;
}
