#include "stackarray.h"
struct stackRecord
{
    int capacity;
    int topOfStack;
    ElementType *array;
};

int isEmpty(stack s)
{
    return s->topOfStack == EMPTYTOS;
}

int isFull(stack s)
{
    return s->capacity == s->topOfStack;
}

stack createStack(int maxElements)
{
    stack s = malloc(sizeof(struct stackRecord));
    if (s == NULL){
    }
    s->array = malloc(sizeof(ElementType) * maxElements);
    if (s->array == NULL) {
    }
    s->capacity = maxElements;
    makeEmpty(s);
    return s;
}
void disposeStack(stack s)
{
    if (s != NULL){
        free(s->array);
        free(s);
    }
}

void makeEmpty(stack s)
{
    s->topOfStack = EMPTYTOS;
}

ElementType top(stack s)
{
    return isEmpty(s) ? 0 : s->array[s->topOfStack];
}
void pop(stack s)
{
    if (isEmpty(s)){
        printf("stack empty");
    } else 
        s->topOfStack--;
}
ElementType topAndPop(stack s)
{
    if (!isEmpty(s)){
        return s->array[s->topOfStack--];
    } else {
        printf("stack empty");
        return 0;
    }
}
void push(stack s, ElementType e)
{
    if (isFull(s)){
        printf("stack is full");
    } else
        s->array[++s->topOfStack] = e;
}



