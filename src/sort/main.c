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
int* init_array(int *A, int size)
{
    time_t t;
    int min ,max;
    min = get_integer("The min number in the array");
    max = get_integer("Max number!");

    A = (int*)malloc(size * sizeof(int));
    if (A == NULL)
        FatalError("Out of space!");
    srand((unsigned)time(&t));
    for (int i = 0; i < size; i++)
    {
       A[i]= rand() % (max - min + 1) + min;
    }
    return A;
}

int menu()
{
    printf("#########----------###########\n");
    printf("1).Insertion sort\n");
    printf("2).Shell sort\n");
    printf("3).Heap sort\n");
    printf("4).Merge sort\n");
    printf("5).Quick sort\n");
    printf("#########----------###########\n");
    return get_integer("You choose:");
}


int main()
{
    int select, size, *test;
    while (select = menu())
    {
        size = get_integer("Array size");
        while(size <= 0)
            size = get_integer("Array size must bigger then zero");

        test = init_array(test, size);

        printf("Before sort:\n");
        print_array(test, size);
        switch (select) {
            case 1:
                insertion_sort(test,size);
                break;
            case 2:
                shell_sort(test, size);
                break;
            case 3:
                heap_sort(test, size);
                break;
            case 4:
                merge_sort(test, size);
                break;
            case 5:
                quick_sort(test, size);
                break;
        }
        printf("After sort:\n");
        print_array(test, size);
    }
   return 0;
}
