#pragma once
#include<stdlib.h>
#include<stdio.h>

/*

ջ��˳��洢��ʾ

*/


#define SElemType int
#define STACK_INIT_SIZE 100		//�洢�ռ��ʼ������
#define STACKINCREMENT 10		//�洢�ռ��������

/*˳��ջ�Ķ���*/
typedef struct {
	SElemType *base;			//ջ��ָ�룬�ڹ���֮ǰ������֮��base��ֵΪNULL
	SElemType *top;			//ջ��ָ��
	int stacksize;		//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

/*������������*/

void InitStack(SqStack *s)		//����һ����ջS
{
	s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base) printf("�洢����ʧ��\n");	//�洢����ʧ��
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	printf("�����ɹ�\n");
}

void DestroyStack(SqStack *s)	//����s
{
	//free(s);
	free(s->base);
	s->top = NULL;
	s->base = NULL;
	s->stacksize = 0;
	s = NULL;
	//	free(s);
}

void ClearStack(SqStack *s)		//��s��Ϊ��ջ
{
	s->top = s->base;
}

int StackEmpty(SqStack *s)		//��ջsΪ�գ�����1�����𷵻�0
{
	if (s->base == s->top) return 1;
	else return 0;
}

int StackLength(SqStack *s)		//����s��Ԫ�ظ�������ջ�ĳ���
{
	int lenth;//ջ��
	lenth = (s->top - s->base);//?
	return lenth;
}

void GetTop(SqStack *s, SElemType *e)			//��ջ��Ϊ�գ�����e����s��ջ��Ԫ�أ�������1�����򷵻�0
{
	if (s->top == s->base)	printf("��ջ");
	else
		*e = *(s->top - 1);
}

void Push(SqStack *s, SElemType e)			//����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (s->top - s->base >= s->stacksize)//ջ����׷�Ӵ洢�ռ�
	{
		s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType));

		if (!s->base)	exit(1);	//�洢����ʧ��

		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
}

void Pop(SqStack *s, SElemType *e)		//��ջ���գ���ɾ��s��ջ��Ԫ�أ���e������ֵ��������1�����򷵻�0
{
	if (s->top == s->base)	printf("��ջ");
	else	*e = *--s->top;
}

void visit(SElemType *base)
{
	printf("%d ", *base);
}
void StackTraverse(SqStack *s)		//��ջ�׵�ջ�����˶�ջ��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��
{
	while (s->base != s->top)
	{
		visit(s->base++);
	}
	printf("OK");
}