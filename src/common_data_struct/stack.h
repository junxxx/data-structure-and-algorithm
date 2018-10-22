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
    {
        printf("Out of space!");
        exit(0);
    }
    /*！！！注意初始化时栈时，一定要给S->Next赋值NULL*/
    S->Next = NULL;
    MakeEmpty( S );
    return S;
}

void MakeEmpty( Stack S )
{
    if( S == NULL )
    {
        printf("Error Stack NULL");
        exit(0);
    }
    else
    {
        while( !IsEmpty( S ) ){
            Pop( S );
        }
    }
}

void Pop( Stack S )
{
    PtrToStackNode FirstCell;

    if( IsEmpty( S ) )
    {
        printf("Pop Empty Stack\n");
        exit(0);
    }
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
    {
        printf("Failed to malloc space for Node");
        exit(0);
    }
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
        /*栈顶指针，不含元素，要特殊处理一下*/
        S = S->Next;
        while( S != NULL){
            printf("***  %d  ***\n",S->Element);
            S = S->Next;
        }
    }
}