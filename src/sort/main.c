#include "../lib/common.h"
#include "../lib/lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void print_array(int a[], unsigned int n)
{
    for(int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
}

/**
 * init random array
 */
void init_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
       A[i] = rand() % 100;
    }
}

int main()
{
    int i, test[10];
    time_t t;
    srand((unsigned)time(&t));
    init_array(test, 10);
    printf("before insertion_sort: ");
    print_array(test, 10);
    insertion_sort(test, 10);
    printf("array after insertion_sort: ");
    print_array(test, 10);
    init_array(test, 10);
    printf("before shell_sort: ");
    print_array(test, 10);
    shell_sort(test, 10);
    printf("after shell_sort: ");
    print_array(test, 10);
    init_array(test, 10);
    printf("before heap_sort: ");
    print_array(test, 10);
    heap_sort(test, 10);
    printf("after heap_sort: ");
    print_array(test, 10);
    init_array(test, 10);
    printf("before m_sort: ");
    print_array(test, 10);
    merge_sort(test, 10);
    printf("after m_sort: ");
    print_array(test, 10);
    return 0;
}
