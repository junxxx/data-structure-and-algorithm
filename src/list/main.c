#include "../lib/common.h"
#include <stdio.h>
#include "p_list.h"

int main()
{
    //init list
    //creat list
    //isEmpty
    //insert
    //getLen
    //delete

    List L;
    int i;
    printf("init list\n");
    L = init();
    printf("isEmpty:%d listLen: %d\n", isEmpty(L), getLen(L));
    printf("insert list\n");
    insert(L, 0, 10);
    printf("isEmpty:%d listLen: %d\n", isEmpty(L), getLen(L));
    display(L);
    insert(L, 1, 10);
    printf("isEmpty:%d listLen: %d\n", isEmpty(L), getLen(L));
    display(L);
    insert(L, 2, 20);
    printf("isEmpty:%d listLen: %d\n", isEmpty(L), getLen(L));
    display(L);
    insert(L, 3, 30);
    printf("isEmpty:%d listLen: %d\n", isEmpty(L), getLen(L));
    display(L);
    insert(L, 1, 1);
    printf("isEmpty:%d listLen: %d\n", isEmpty(L), getLen(L));
    display(L);
    insert(L, 1, 111);
    printf("isEmpty:%d listLen: %d\n", isEmpty(L), getLen(L));
    display(L);
    delList(L, 2);
    display(L);
}
