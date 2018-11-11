#include "hashSepC.h"
#include "hashSepC.c"

int main()
{
    int element = 66;
    int TableSize = 1197;
    Position p;

    HashTable H = InitializeTable(TableSize);
    if (H == NULL)
    {
        printf("init failed\n");
        exit(1);
    }
    Insert(66, H);
    p = Find(66, H);
    printf("Element %d is in the position of hashTable %p\n", element, p);
    p = Find(12, H);
    printf("%p\n", p);

    return 0;
}

