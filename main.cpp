#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ElemType;

#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

bool ListInsert(SqList& L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1)
	{
		return false;
	}
	if (L.length >= MaxSize)
	{
		return false;
	}
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

bool ListDelete(SqList& L, int i, ElemType& e)
{
	if (i<1 || i>L.length)
	{
		return false;
	}
	if (L.length == 0)
	{
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

void PrintList(SqList& L)
{
	for (int i = 0; i < L.length; i++)
		printf("%3d", L.data[i]);
	printf("\n");
}

int main(void)
{
	SqList L;//Ë³Ðò±íµÄÃû³Æ
	bool ret = true;
	ElemType del = 0;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;
	int insert = 0;
	scanf("%d", &insert);
	ret = ListInsert(L, 2, insert);
	if (ret)
	{
		PrintList(L);
	}

	int del_ = 0;
	scanf("%d", &del_);
	ret = ListDelete(L, del_, del);
	if (ret)
	{
		PrintList(L);
	}
	else {
		printf("false");
	}

	return 0;
}