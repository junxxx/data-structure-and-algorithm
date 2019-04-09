/**
 * implement stack with global array 1st version
 * !!! this always a bad idea to implement stack 
 *     with global variable
 * !!!
 */
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000
typedef int ElementType;
extern int stack[MAXLENGTH];
extern unsigned int top;
extern unsigned int length;

void push(ElementType e);
ElementType pop();
int isEmpty();
void tralver();

#endif 
