#include "../lib/common.h"
#include <stdio.h>
#include <stdlib.h>

//queue is a list,which first in first out
//implement queue with pointer, tail enqueue, head dequeue
#ifndef _QUEUE_HEAD_H
#define _QUEUE_HEAD_H
typedef int ElementType;

typedef struct qnode {
    ElementType data;
    struct qnode *next;
} qnode;
typedef qnode *ptrnode;
typedef ptrnode Queue;

Queue init();
Queue enqueue(Queue q, ElementType e);
ElementType dequeue(Queue q);
int getlen(Queue q);
void traverse(Queue q);
int isempty(Queue q);
#endif
Queue init()
{
    Queue queue = malloc(sizeof(struct qnode));
    if (queue == NULL)
    {
       printf("malloc queue error"); 
       exit(1);
    }
    queue->next = NULL;
    return queue;
}

Queue enqueue(Queue queue, ElementType item)
{
    Queue q = queue, tmpnode;
    tmpnode = malloc(sizeof(struct qnode));
    if (tmpnode == NULL)
    {
        printf("enqueue malloc error");
        exit(1);
    }
    while(q->next) {
        q = q->next;
    }
    tmpnode->data = item;
    tmpnode->next = NULL;
    q->next = tmpnode;
    return queue;
}

ElementType dequeue(Queue queue)
{
    Queue q = queue;
    ElementType item;
    if (isempty(q))
    {
        printf("empty queue\n");
        exit(1);
    }
    //head pointer
    q = q->next;
    item = q->data;
    queue->next = q->next;
    free(q);
    return item;
}

int isempty(Queue queue)
{
    return queue->next == NULL;
}

void traverse(Queue queue)
{
    Queue q = queue;
    while(q->next) {
        q = q->next;
        printf("%d\t", q->data);
    }
    printf("\n");
}



