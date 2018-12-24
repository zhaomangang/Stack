#include<stdio.h>
#include"Stack.h"
int main()
{
	int e;
	SqStack q;
	if (StackEmpty(&q)) printf("ø’’ª\n");
	else printf("∑«ø’\n");
	InitStack(&q);
	if (StackEmpty(&q)) printf("ø’’ª\n");
	else printf("∑«ø’\n");
	Push(&q,3);
	Push(&q, 4);
	GetTop(&q, &e);
	printf("e=%d\n", e);
	printf("≥§£∫%d\n", StackLength(&q));
	if (StackEmpty(&q)) printf("ø’’ª\n");
	else printf("∑«ø’\n");
	Pop(&q, &e);
	printf("e=%d\n", e);
	/*ClearStack(&q);
	if (StackEmpty(&q)) printf("ø’’ª\n");
	else printf("∑«ø’\n");*/
	//DestroyStack(&q);
	if (StackEmpty(&q)) printf("ø’’ª\n");
	else printf("∑«ø’\n");
	StackTraverse(&q);
	
	return 0;	
}