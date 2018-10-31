#include "../lib/common.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef __Tree_H
typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType x, SearchTree T);
SearchTree Delete(ElementType x, SearchTree T);
ElementType Retrieve(Position p);
void PrintTree(SearchTree T);
int Height(SearchTree T);

#endif

struct TreeNode 
{
    ElementType data;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
    }
}

Position Find(ElementType x, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (x < T->data)
        return Find(x, T->Left);
    else if (x > T->data)
        return Find(x, T->Right);
    return T;
}

Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

/*nonrecursive implementation of FindMax*/
Position FindMax(SearchTree T)
{
    if (T != NULL)
        while(T->Right != NULL)
            T = T->Right;
    return T;
}

SearchTree Insert(ElementType x, SearchTree T)
{
    if (T == NULL)
    {
        /*Create and return a one-node tree*/
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            exit(1);
        else
        {
            T->data = x;
            T->Left = T->Right =  NULL;
        }
    }
    else if (x < T->data)
        T->Left = Insert(x, T->Left);
    else if (x > T->data)
        T->Right = Insert(x, T->Right);
    return T;   /*Do not forget this lines!!*/
}

SearchTree Delete(ElementType x, SearchTree T)
{
    Position TmpCell;
    
    if (T == NULL)
        exit(1);
    else if (x < T->data)
        T->Left = Delete(x, T->Left);
    else if (x > T->data)
        T->Right = Delete(x, T->Right);
    else    /*Found element to be deleted*/
    {
        if (T->Left && T->Right)    /*Two children*/
        {
            /*Replace with smallest in right subtree*/
            TmpCell = FindMin(T->Right);
            T->data = TmpCell->data;
            T->Right = Delete(T->data, T->Right);
        }
        else    /*One or zero children*/
        {
            TmpCell = T;
            if (T->Left == NULL)
                T = T->Right;
            else if(T->Right == NULL)
                T = T->Left;
            free(TmpCell);
        }
    }
    return T;
}

void PrintTree(SearchTree T)
{
    if (T != NULL)
    {
        PrintTree(T->Left);
        printf("%d ", T->data);
        PrintTree(T->Right);
    }
}

int Height(SearchTree T)
{
    if (T == NULL)
        return -1;
    else
        return 1 + MAX(Height(T->Left), Height(T->Right));
}

