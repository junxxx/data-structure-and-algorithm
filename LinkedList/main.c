#include <stdio.h>
#include <stdlib.h>
#include "define.h"


int main() {
    List L;
    int count;
    printf("############InitList####################\n");
    InitList(L);
    printf("The address of List L is %p\n",L);
    printf("Enter the count of elements to store in the list:\n");
    scanf("%d",&count);
    printf("The number you have typed is %d\n",count);
    CreateList( L, count);
    return 0;
}

void InitList( List *L)
{
    (*L) = (List)malloc(sizeof(Node));
    if((*L) == NULL)
    {
        printf("\n Failed to malloc memory to init List!\n");
        exit(1);
    }
    (*L)->Next = NULL;
}

/*create linked list*/
void CreateList( List *L, ElementType n)
{
    List p;
    int i;
//    printf("The List Element is %d\n",L->Element);
    printf("The number you have typed is %d\n",n);
//    while( n > 0 ){
    for(i = 0; i < n; i++){
        p = (List)malloc(sizeof(Node));
        printf("p's address is %p",p);
        scanf("%d",&p->Element);
        printf("The number you've just type is %d\n",p->Element);
        p->Next = (*L)->Next;
        (*L)->Next = p;
//        printf("\n n now is %d\n",n);
//        n--;
//        printf("\n n now is %d\n",n);
    }

}