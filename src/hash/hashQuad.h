#ifndef _HashQuad_H

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType ;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize);
void DestoyTable( HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);

#endif /* _HashQuad_H */

