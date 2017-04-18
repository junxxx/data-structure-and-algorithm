#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

int main()
{
    int count = 5;
    List L = InitList();
    CreateListHead(L, count);
    DisplayList(L);
    return 0;
}
/*init linked list*/
List InitList()
{

    List L = (List)malloc(sizeof(Node));
    if(L == NULL)
    {
        printf("\n Failed to malloc memory to init List!\n");
        exit(1);
    }
    L->Next = NULL;
    return L;
}
/*create*/
void CreateListHead(List L, int n)
{
    List p;
    int i;
    srand(time(0));
    for ( i=0; i<n; i++)
    {
        p = (List)malloc(sizeof(Node));
        p->Element = rand()%100+1;
        p->Next = L->Next;
        L->Next = p;
    }
}
void DisplayList( List L)
{

    Position p = L->Next;
    while(p != NULL)
    {
        printf("%d-->",p->Element);
        p = p->Next;
    }
    printf("End of list");
}