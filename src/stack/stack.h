#include "../lib/common.h"
#include <stdio.h>
#include <stdlib.h>

//stack implementation of double linked list
struct stacknode;
typedef int ElementType;
typedef struct stacknode *ptrnode;
typedef ptrnode Stack;

struct stacknode {
    ptrnode pre;
    ElementType data;
    ptrnode next;
};

Stack initStack();
Stack push(Stack s, ElementType item);
ElementType pop(Stack s);
void traverse(Stack s);
int isempty(Stack s);

Stack initStack()
{
    Stack s = malloc(sizeof(struct stacknode));
    if (s == NULL)
        exit(1);
    s->pre = s->next = NULL;
    return s;
}

Stack push(Stack stack, ElementType item)
{
    Stack s = stack, node = malloc(sizeof(struct stacknode));
    if (node == NULL)
        exit(1);
    node->pre = s->next;
    node->data = item;
    node->next = s->next;
    s->next = node->pre;
}

ElementType pop(Stack stack)
{
    Stack p, s = stack;
    if (!isempty(s))
    {
        ElementType item;
        p = s->next;
        item = p->data;
        s->next = p->next;
        free(p);
        return item;
    }
}

void traverse(Stack s)
{
    while(s->next) {
        s = s->next;
        printf("%d ", s->data);
    }
    printf("\n");
}

int isempty(Stack stack)
{
    return stack->next == NULL;
}

