#ifndef __STACK_ARRAY_H
#define __STACK_ARRAY_H
#define MIN_STACK_SIZE 10
#define EMPTYTOS 0
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; 
struct stackRecord;
typedef struct stackRecord *stack;

int isEmpty(stack s);
int isFull(stack s);
stack createStack(int maxElements);
void disposeStack(stack s);
void makeEmpty(stack s);
ElementType top(stack s);
void pop(stack s);
ElementType topAndPop(stack s);
void push(stack s, ElementType e);

#endif      /* __STACK_ARRAY_H */

