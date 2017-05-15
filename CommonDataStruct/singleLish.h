#ifndef _List_H
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List InitList();
void CreateListHead( List L, int n);
void DisplayList( List L);
int IsEmpty(List L);
int IsLast(Position p, List L);
Position Find(ElementType e, List L);
Position FindPrevious(ElementType e, List L);
void Insert(ElementType e, List L,Position p);
void Delete(ElementType e, List L);

#endif      /* _List_H*/


typedef struct Node
{
    ElementType Element;
    Position    Next;
} Node;



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
    printf("\nElement in list:");
    Position p = L->Next;

    while(p != NULL)
    {
        if( !IsLast(p,L)){
            printf("%p|%d|%p-->",&(p->Element),p->Element,p->Next);
        } else {
            printf("%p|%d|%p",&(p->Element),p->Element,p->Next);
        }
        p = p->Next;
    }
    printf("End of list\n");
}
int IsEmpty( List L)
{
    return(L->Next == NULL);
}
int IsLast(Position p, List L)
{
    return(p->Next == NULL);
}
Position Find(ElementType e, List L)
{
    Position p;
    p = L->Next;
    while( (p != NULL) && (p->Element != e)){
        p = p->Next;
    }
    return p;
}
Position FindPrevious(ElementType e, List L)
{
    Position p;
    p = L;
    while( (p->Next != NULL) && (p->Next->Element != e) ){
        p = p->Next;
    }
    return p;
}
/*Insert element after position p*/
void Insert(ElementType e, List L, Position p)
{
    Position tmp_node;
    tmp_node = (Position)malloc(sizeof(Node));
    if( tmp_node == NULL ){
        printf("Out of space\n");
        exit(1);
    } else {
        tmp_node->Element = e;
        tmp_node->Next = p->Next;
        p->Next = tmp_node;
    }
}
void Delete(ElementType e, List L)
{
    Position p;
    p = FindPrevious(e,L);
    if( p->Next != NULL ){
        p->Next = p->Next->Next;
    }
}