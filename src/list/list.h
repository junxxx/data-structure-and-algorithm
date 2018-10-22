#include "../lib/common.h"
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status InitList(SqList *L);		//init list
SqList Create(SqList L, int);
Status ClearList(SqList *L);
Status visit(ElemType c);
Status ListTraverse(SqList L);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int p);

Status InitList(SqList *L)		//init list
{
	L->length=0;
	return OK;
}

SqList Create(SqList L, int len)
{
	int i;
    if (len > MAXSIZE)
        exit(1);
	srand((unsigned)time(NULL));
	for(i = 0; i < len; i++)
	{
		L.data[i] = rand()%100;
		L.length++;
	}
	return L;
}

Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

Status visit(ElemType c)
{
	printf("%d ",c);
	return OK;
}

Status ListTraverse(SqList L)
{
	int i;
	for(i = 0; i < L.length; i++)
		visit(L.data[i]);
	printf("\n");
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if(L->length==MAXSIZE)
		return ERROR;
	if(i < 1 || i > L->length+1)
		return ERROR;
	if(i <= L->length)
	{
		for(k=L->length-1; k >= i - 1;k--)
			L->data[k+1]=L->data[k];
	}
	L->data[i-1] = e;
	L->length++;

	return OK;
}

Status ListDelete(SqList *L, int p)
{
    int k;
    if (L->length == MAXSIZE)
        return ERROR;
    if (p < 0 || p > L->length - 1)
        return ERROR;
    for (k = p; k < L->length - 1; k++)
        L->data[k] = L->data[k+1];
    L->length--;
    return OK;
}
