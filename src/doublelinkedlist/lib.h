#include <stdio.h>
#include <stdlib.h>
typedef struct DulNode
{
    int data;
    struct DulNode *prior;
    struct DulNode *next;
} DulNode, *DuLinkList;
