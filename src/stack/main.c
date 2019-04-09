#include "arraystack.h"

unsigned int top, length;
int stack[MAXLENGTH];

/* test stack implement with array */
int main(int argc, const char** argv)
{
    if (isEmpty()){
        push(3);
    }
    tralver();
    push(1);
    push(5);
    tralver();
    while (!isEmpty()){
        printf("pop %d\n", pop());
    }
    tralver();
    return 0;
}
