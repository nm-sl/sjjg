#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

LinkList CreatList1(LinkList& L)//ͷ�巨
{
	int x; LNode* s;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->next = L->next;
		L->next = s;
		s->data = x;
		scanf("%d",&x);
	}
	return L;
}

LinkList CreatList2(LinkList& L)
{
	L = (LinkList)malloc(sizeof(LNode));
	int x; LNode* s, *r = L;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}

int main()
{
	LinkList L;
	LinkList search;
	CreatList1(L);
	//CreatList2(L);
	PrintList(L);
}