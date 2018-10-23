#include "../lib/common.h"
#include <stdlib.h>

#ifndef _S_LIST_H
#define _S_LIST_H
//implement single list with head node
typedef int ElementType;
struct node;
struct node {
    ElementType data;
    struct node *next;
}; 

typedef struct node *List; 
List init(); 
List create(); 
int isEmpty(List L);
List insert(List L, int, ElementType); 
List append();
void display(List L); 
int delList(List L, int p);
int clear(List L); 
int getLen(List L);

#endif

List init()
{
    List node = malloc(sizeof(struct node));
    if ( node == NULL)
    {
        printf("malloc error\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

int isEmpty(List L)
{
    return L->next == NULL;
}

List insert(List L, int p, ElementType item)
{
    List tmp, node = L;
    if (p < 0)
    { 
        printf("position should be greter than zero\n");
        exit(1);
    }
    tmp = malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("malloc error\n");
        exit(1);
    }
    //isLast 
    if (p >= getLen(L))
    {
        p = getLen(L);
    }
    while(p--) {
        node = node->next;
    }
    tmp->data = item;
    tmp->next = node->next;
    node->next = tmp;
}

//todo it's not easy 
List append()
{

}

void display(List L)
{
    if(!isEmpty(L))
    {
        //head
        L = L->next;
        do {
            printf("%d ", L->data);
            L = L->next;
        } while(L);
        printf("\n");
    }
}

int clear(List L)
{
    while(L->next)
    {
        free(L);
        L = L->next;
    }
}

int delList(List L, int p)
{
    List tmp, node = L;
    if (p < 0 || p > getLen(L))
    {
        printf("element out of index\n");
        exit(1);
    }
    while(p--)
    {
        node = node->next;
    }
    tmp =  node->next;
    node->next = tmp->next;
    free(tmp);
}


int getLen(List L)
{
    int i = 0;
    while(L->next) {
        L = L->next;
        i++;
    }

    return i;
}


