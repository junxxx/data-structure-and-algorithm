//
// Created by Administrator on 2017/5/15 0015.
//

#ifndef _STACK_H
#define _STACK_H
typedef int ElementType;

struct StackNode;
typedef struct StackNode *PtrToStackNode;
typedef PtrToStackNode Stack;

int IsEmpty( Stack S );
Stack CreateStack( void );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType E, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );
/*实现栈---带特殊头结点的链表*/
struct StackNode
{
    ElementType Element;
    PtrToStackNode Next;
};

#endif //LINKEDLIST_STACK_H

int IsEmpty( Stack S )
{
    return S->Next == NULL;
}

Stack CreateStack( void )
{
    Stack S;

    S = malloc( sizeof( struct StackNode ) );
    if( S == NULL )
        exit(0);
    MakeEmpty( S );
    return S;
}

void MakeEmpty( Stack S )
{
    if( S == NULL )
        exit(0);
    else
        while( !IsEmpty( S ) )
            Pop( S );

}

void Pop( Stack S )
{
    PtrToStackNode FirstCell;

    if( IsEmpty( S ) )
        exit(0);
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free( FirstCell );
    }
}

void Push( ElementType E, Stack S )
{
    PtrToStackNode TmpCell;

    TmpCell = malloc( sizeof( struct StackNode ) );
    if( TmpCell == NULL )
        exit(0);
    else
    {
        TmpCell->Element = E;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

void DisplayStack( Stack S )
{
    if( S == NULL )
        exit(0);
    else
    {
        while( S->Next != NULL){
            printf("echo something");
            printf("***%d***",S->Element);
            S = S->Next;
        }
    }
}