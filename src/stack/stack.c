#include "../lib/common.h"
#include "stack.h"
#include <stdio.h>

int main()
{
    Stack s;
    s = initStack();
    s = push(s, 1);
    traverse(s);
    s = push(s, 4);
    s = push(s, 9);
    traverse(s);
    printf("\n%d pop from stack\n", pop(s));
    traverse(s);
    printf("\n%d pop from stack\n", pop(s));
    printf("\n%d pop from stack\n", pop(s));
    printf("\n%d pop from stack\n", pop(s));
    s = push(s, 66);
    traverse(s);
        
    return 0;
}
