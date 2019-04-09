#include "arraystack.h"

int isEmpty()
{
    return length == 0;
}

void push(ElementType e)
{
    if (top < MAXLENGTH) {
        stack[++top] = e;
        length++;
    }
    else 
        exit(1);
}

ElementType pop()
{
    if (isEmpty()){
        exit(1);
    }
    ElementType e = stack[top--];
    length--;
    return e;
}

void tralver()
{
    for (int i = length; i > 0 ; i--){
        printf("%d%s", stack[i], i == 1 ? "\n" : " ");
    }
}
