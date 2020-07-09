#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct linknode
{
	ElemType data;				//������
	struct linknode *next;		//ָ����
} LiStack;
void InitStack(LiStack *&s)		//��ʼ��ջs
{	s=(LiStack *)malloc(sizeof(LiStack));
	s->next=NULL;
}
void DestroyStack(LiStack *&s)	//����ջ
{	LiStack *p=s,*q=s->next;
	while (q!=NULL)
	{	free(p);
		p=q;
		q=p->next;
	}
	free(p);	//��ʱpָ��β�ڵ�,�ͷ���ռ�
}
bool StackEmpty(LiStack *s)	//�ж�ջ�Ƿ�Ϊ��
{
	return(s->next==NULL);
}
void Push(LiStack *&s,ElemType e)	//��ջ
{	LiStack *p;
	p=(LiStack *)malloc(sizeof(LiStack));
	p->data=e;				//�½�Ԫ��e��Ӧ�Ľڵ�*p
	p->next=s->next;		//����*p�ڵ���Ϊ��ʼ�ڵ�
	s->next=p;
}
bool Pop(LiStack *&s,ElemType &e)	//��ջ
{	LiStack *p;
	if (s->next==NULL)		//ջ�յ����
		return false;
	p=s->next;				//pָ��ʼ�ڵ�
	e=p->data;
	s->next=p->next;		//ɾ��*p�ڵ�
	free(p);				//�ͷ�*p�ڵ�
	return true;
}
bool GetTop(LiStack *s,ElemType &e)	//ȡջ��Ԫ��
{	if (s->next==NULL)		//ջ�յ����
		return false;
	e=s->next->data;
	return true;
}
