#include<stdio.h>
#include"Stack.h"
int main()
{
	int e;
	SqStack q;
	if (StackEmpty(&q)) printf("��ջ\n");
	else printf("�ǿ�\n");
	InitStack(&q);
	if (StackEmpty(&q)) printf("��ջ\n");
	else printf("�ǿ�\n");
	Push(&q,3);
	Push(&q, 4);
	GetTop(&q, &e);
	printf("e=%d\n", e);
	printf("����%d\n", StackLength(&q));
	if (StackEmpty(&q)) printf("��ջ\n");
	else printf("�ǿ�\n");
	Pop(&q, &e);
	printf("e=%d\n", e);
	/*ClearStack(&q);
	if (StackEmpty(&q)) printf("��ջ\n");
	else printf("�ǿ�\n");*/
	//DestroyStack(&q);
	if (StackEmpty(&q)) printf("��ջ\n");
	else printf("�ǿ�\n");
	StackTraverse(&q);
	
	return 0;	
}