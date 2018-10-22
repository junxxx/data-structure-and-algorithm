#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "singleLish.h"
#include "stack.h"

int main()
{
    /*
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
    */
    Stack S;
    int isEmpty;

    printf("##########栈操作########\n");
    S = CreateStack();
    Push( 4, S );
    printf("输出栈中元素\n");
    Push(9,S);
    DisplayStack( S );
    printf("清空栈\n");
    MakeEmpty(S);
    DisplayStack( S );
    printf("入栈7,6,21\n");
    Push(7,S);
    Push(6,S);
    Push(21,S);
    DisplayStack( S );
    return 0;
}


