/*
#include "hashSepC.h"
#include "hashSepC.c"
*/
#include "hashQuad.h"
#include "hashQuad.c"

int main()
{
    int element = 66;
    int TableSize = 2017;
    Position p;

    HashTable H = InitializeTable(TableSize);
    if (H == NULL)
    {
        FatalError("\nInitializeTable failed\n");
    }
    Insert(66, H);
    p = Find(66, H);
    printf("Element %d is in the position of hashTable %p\n", element, p);
    p = Find(12, H);
    printf("%p\n", p);

    return 0;
}

