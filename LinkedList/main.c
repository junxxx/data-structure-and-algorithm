#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

int main()
{
    Position p;
    int count = 5;
    List L = InitList();
    CreateListHead(L, count);
    DisplayList(L);
    Insert(88,L,L->Next);
    DisplayList(L);
    Insert(22,L,L);
    DisplayList(L);
    p = Find(88,L);
    printf("\nElement 88's address in List is:%p",p);
    Delete(88,L);
    DisplayList(L);
    return 0;
}