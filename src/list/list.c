#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/lib.h"
#include "list.h"

int ShowMenu(int num, char *menus[])
{
    for (int i=0; i < num; i++)
        printf("%d). %s\n", i+1, menus[i]);
    return get_integer("Choose muen:");
}

void DisplayList(SqList L)
{
    printf("##################List##################\n");
    ListTraverse(L);
}

int main()
{
	SqList L;
    int inited = FALSE;
    int list_len, choose; 
    int insertP, deleteP, insertItem;
    char *menu[] = {
        "Init List", "Create List", "Insert item to position",
        "Delete item in the position", "Clear List", "Display List", "Quit"
    };

    //todo change display menu dynamiclly 
    //todo add sort to menu
    while((choose = ShowMenu(7, menu)) != 7)
    {
        switch(choose)
        {
            case 1:     //init list with list_len length
                if (!inited)
                {
                    inited = InitList(&L);
                    printf("Init list success...\n");
                }
                break;
            case 2:     //create
                if (!inited)
                    printf("Init list first\n");
                else 
                {
                    list_len = get_integer("Input the list length");
                    L = Create(L, list_len);
                    DisplayList(L);
                }
                break;
            case 3:     //insert
                if (!inited)
                    printf("Init list first\n");
                else 
                {
                    insertP = get_integer("Input the position to insert:");
                    insertItem = get_integer("Input the item to insert:");
                    ListInsert(&L, insertP, insertItem);
                    DisplayList(L);
                }
                break;
            case 4:     //delete
                if (!inited)
                    printf("Init list first\n");
                else
                {
                    deleteP = get_integer("Input the position to insert:");
                    ListDelete(&L, deleteP);
                }
                break;
            case 5:     //clear
                if (!inited)
                    printf("Init list first\n");
                else 
                {
                    ClearList(&L);
                    printf("List cleared\n");
                }
                break;
            case 6:
                if (!inited)
                    printf("Init list first\n");
                else 
                    DisplayList(L);
            default:
                break;
        }
    }

	return 0;
}

