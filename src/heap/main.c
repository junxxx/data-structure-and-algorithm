#include "binHeap.h"
#include "binHeap.c"

int main()
{
    int i, test[10] = {32, 26, 65, 68, 19, 31, 24, 16, 21, 13};
    int MaxElements = 20;
    PriorityQueue H = Initialize(MaxElements);
    if (H == NULL)
    {
        exit(1);
    }

    for (i = 0; i < 10; i++)
    {
        Insert(test[i], H);
    }
    printf("Priority Queue H's Size is: %d\n", H->Size);

    for(i = 1; i <= H->Size; i++)
    {
        printf("%d%s", H->Elements[i], i == H->Size ? "\n" : " ");
    }

    return 0;
}
