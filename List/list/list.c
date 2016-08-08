#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status InitList(SqList *L)		//init list
{
	L->length=0;
	return OK;
}

SqList Create(SqList L)
{
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < 10; i++)
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

int main()
{
	SqList L;
	ElemType e;
	Status i;

	i = InitList(&L);
	printf("初始化成功，L.length=%d\n",L.length);
	printf("遍历线性表\n");
	ListTraverse(L);
	L = Create(L);
	printf("线性表的长度为：%d\n",L.length);
	printf("创建随机链表：L.data=");
	ListTraverse(L);
//	i = ClearList(&L);
//	printf("清空Ｌ后：L.length=%d\n",L.length);
	ListInsert(&L,2,88);
	printf("将88插入第二个位置之后的线性表：\n");
	ListTraverse(L);

	return 0;
}

