#pragma once
#include<stdlib.h>
#include<stdio.h>

/*

栈的顺序存储表示

*/


#define SElemType int
#define STACK_INIT_SIZE 100		//存储空间初始分配量
#define STACKINCREMENT 10		//存储空间分配增量

/*顺序栈的定义*/
typedef struct {
	SElemType *base;			//栈底指针，在构造之前和销毁之后，base的值为NULL
	SElemType *top;			//栈顶指针
	int stacksize;		//当前已分配的存储空间，以元素为单位
}SqStack;

/*基本操作函数*/

void InitStack(SqStack *s)		//构造一个空栈S
{
	s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base) printf("存储分配失败\n");	//存储分配失败
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	printf("构建成功\n");
}

void DestroyStack(SqStack *s)	//销毁s
{
	//free(s);
	free(s->base);
	s->top = NULL;
	s->base = NULL;
	s->stacksize = 0;
	s = NULL;
	//	free(s);
}

void ClearStack(SqStack *s)		//把s置为空栈
{
	s->top = s->base;
}

int StackEmpty(SqStack *s)		//若栈s为空，返回1，负责返回0
{
	if (s->base == s->top) return 1;
	else return 0;
}

int StackLength(SqStack *s)		//返回s的元素个数，即栈的长度
{
	int lenth;//栈长
	lenth = (s->top - s->base);//?
	return lenth;
}

void GetTop(SqStack *s, SElemType *e)			//若栈不为空，则用e返回s的栈顶元素，并返回1，否则返回0
{
	if (s->top == s->base)	printf("空栈");
	else
		*e = *(s->top - 1);
}

void Push(SqStack *s, SElemType e)			//插入元素e为新的栈顶元素
{
	if (s->top - s->base >= s->stacksize)//栈满，追加存储空间
	{
		s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType));

		if (!s->base)	exit(1);	//存储分配失败

		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
}

void Pop(SqStack *s, SElemType *e)		//若栈不空，则删除s的栈顶元素，用e返回其值，并返回1，否则返回0
{
	if (s->top == s->base)	printf("空栈");
	else	*e = *--s->top;
}

void visit(SElemType *base)
{
	printf("%d ", *base);
}
void StackTraverse(SqStack *s)		//从栈底到栈顶依此对栈的每个元素调用函数visit().一旦visit()失败，则操作失败
{
	while (s->base != s->top)
	{
		visit(s->base++);
	}
	printf("OK");
}