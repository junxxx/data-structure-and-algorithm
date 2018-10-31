#include "../lib/common.h"
#include <stdlib.h>
#ifndef _AVLTREE_H
typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty( AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);


struct AvlNode 
{
    ElementType data;
    AvlTree Left;
    AvlTree Right;
    int Height;
}
#endif

static int Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

AvlTree Insert(ElementType X, AvlTree T)
{
    if (T == NULL)
    {
        /*create and return a one-node tree*/
        T = malloc(sizeof(struct AvlNode));
        if (T == NULL)
            exit(1);
        else
        {
            T->data = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->data)
    {
        T->Left = Insert(X, T->Left);
        if (Height( T->Left) - Height(T->Right) == 2)
        {
            if (X < T->Left->data)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if ( X > T->data)
    {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (X > T->Right->data)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    /*Else X is in the tree already; we'll do nothing*/

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

/**
 *This function can be called only if K2 has a left child
 *Perform a rotate between a node (K2) and its left child
 *Update heights, then return new root
 */
static Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;

    return K1; /*New root*/
}

/*
 * This function can be called only if K3 has a left child
 * and K3's left child has a right child
 * Do the left-right double rotation
 * Update heights, then return new root
 *
 */
static Position DoubleRotateWithLeft(Position K3)
{
    /*Rotate between K1 and K2*/
    K3->Left = SingleRotateWithLeft(K3->Left);

    /*Rotate between K3 and K2*/
    return SingleRotateWithLeft(K3);
}
