#include <stdio.h>
#include <stdlib.h>
#include "../lib/common.h"
#include "../lib/lib.h"

#define MINTABLESIZE 1024

enum KindOfEntry { Legitimate, Empty, Deleted};

struct HashEntry 
{
    ElementType     Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

/* Cell *TheCells will be an array of */
/* HashEntry cells, allocated later */

struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};

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

    if (TableSize < MINTABLESIZE)
    {
        Error("Table size too small");
        return NULL;
    }

    /* Allocate table */
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("Out of space!!!");

    H->TableSize = NextPrime(TableSize);

    /* Allocate array of Cells */
    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if (H->TheCells == NULL)
        FatalError("Out of space!!!");

    for (i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;
    
    return H;
}

Position Find(ElementType Key, HashTable H)
{
    Position CurrentPos;
    int CollisionNum;

    CollisionNum = 0;
    CurrentPos = Hash(Key, H->TableSize);
    while(H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        CurrentPos += 2 * ++CollisionNum -1;
        if (CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos;

    Pos = Find(Key, H);
    if (H->TheCells[Pos].Info != Legitimate)
    {
        /* OK to insert here */
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}

HashTable Rehash(HashTable H)
{
    int i, OldSize;
    Cell *OldCells;

    OldCells = H->TheCells;
    OldSize = H->TableSize;

    /* Get a new, empty table */
    H = InitializeTable(2 * OldSize);

    /* Scan through old talbe, reinserting into new */
    for (i = 0; i < OldSize; i++)
        if (OldCells[i].Info == Legitimate)
            Insert(OldCells[i].Element, H);

    free(OldCells);
    return H;
}

