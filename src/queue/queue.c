#include "../lib/common.h"
#include "queue.h"
#include <stdio.h>

int main()
{
    Queue q;
    q = init();
    printf("enqueue:\n");
    q = enqueue(q, 3);
    q = enqueue(q, 4);
    q = enqueue(q, 5);
    traverse(q);
    dequeue(q);
    traverse(q);
}
