#include <stdio.h>
#include <stdlib.h>
#include "../lib/common.h"
#include "../lib/lib.h"
#define MIN_TABLE_SIZE 1024

/* Place in the implementation file*/
struct ListNode 
{
    ElementType Element;
    Position Next;
};

typedef Position List;

/* List *TheList will be an array of lists, allocated later */
/* The lists use headers (for simplicity) */
/* though this wasters space */
struct HashTbl
{
    int TableSize;
    List *TheLists;
};

typedef unsigned int Index;

Index Hash(int Key, int TableSize)
{
    unsigned int HashVal = 0;
    do 
    {
        HashVal = (HashVal << 5) + Key % 10;
        Key = Key / 10;
    } while (Key);

    return HashVal % TableSize;
}

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if ( TableSize < MIN_TABLE_SIZE)
    {
        printf("Table size too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if ( H == NULL )
        FatalError("Out of space!!!");

    H->TableSize = NextPrime(TableSize);

    /* Allocate array of lists */
    H->TheLists = malloc( sizeof( List ) * H->TableSize );
    if ( H-> TheLists == NULL )
        FatalError("Out of space!!!");

    /* Allocate list headers */
    for ( i = 0; i < H->TableSize; i++ )
    {
        H->TheLists[i] = malloc( sizeof(struct ListNode));
        if ( H->TheLists[i] == NULL)
            FatalError("Out of space!!!");
        else
            H->TheLists[i]->Next = NULL;
    }

    return H;
}

Position Find(ElementType Key, HashTable H)
{
    Position P;
    List L;
    int index;

    //bug here;
    index = Hash(Key, H->TableSize);
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    /* the comparison depends on the element type */
    while(P != NULL && P->Element != Key)
        P = P->Next;
    return P;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H);
    if( Pos == NULL )
    {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
            FatalError("Out of space");
        else
        {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;     /* Probably need strcpy! */
            L->Next = NewCell;
        }
    }

}
