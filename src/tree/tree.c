#include "tree.h"
#include <stdio.h>

int main()
{
    SearchTree tree = NULL;
    int i, element[10] = {2, 4, 3, 7 , 8, 6, 1};
    for (i = 0; i < 10; i++)
    {
        tree = Insert(element[i], tree);
    }
    PrintTree(tree);
    printf("The height of the tree is :%d\n", Height(tree));
    return 0;
}
