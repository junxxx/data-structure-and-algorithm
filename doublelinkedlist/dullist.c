#include "lib.h"

/*init the double linked list */
DuLinkList Init_List()
{
    DuLinkList L;
    L = (DuLinkList)malloc(sizeof(DulNode));
    if( L == NULL )
    {
	printf("\nFailed to allocate memory for DulNode");
	exit(1);
    }
    L->next = NULL;
    return L;
}

void CreateDulList(DuLinkList *L)
{
    
}
int main()
{
    DuLinkList p,node;
}
