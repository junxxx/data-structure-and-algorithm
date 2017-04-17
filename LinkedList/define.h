#ifndef _List_H
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitList( List *L);
void CreateList( List *L, ElementType count);

#endif      /* _List_H*/


typedef struct Node
{
    ElementType Element;
    Position    Next;
} Node;
