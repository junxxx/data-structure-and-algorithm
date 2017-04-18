#ifndef _List_H
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List InitList();
void CreateListHead( List L, int n);
void DisplayList( List L);

#endif      /* _List_H*/


typedef struct Node
{
    ElementType Element;
    Position    Next;
} Node;
