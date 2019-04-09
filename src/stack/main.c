#include "stackarray.h"

/* test stack implement with array */
int main(int argc, const char** argv)
{
    stack s = createStack(20);
    if (isEmpty(s)){
        push(s,3);
    }
    push(s,1);
    push(s,5);
    while (!isEmpty(s)) {
        printf("pop %d\n", topAndPop(s));
    }
    printf("inint another stack s2\n");
    stack s2 = createStack(100);
    push(s2, 101);
    printf("top %d\n", top(s2));
    pop(s2);
    push(s2, 3);
    printf("top %d\n", top(s2));
    return 0;
}
