//�ļ���:algo3-3.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 5
typedef char ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q)	//��ʼ������
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)	//���ٶ���
{
	free(q);
}
bool QueueEmpty(SqQueue *q)	//�ж϶��п�
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)	//����
{
	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)	//����
{
	if (q->front==q->rear)		//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}

void main()
{
	ElemType e;
	SqQueue *q;
	printf("���ζ��л�����������:\n");
	printf("  (1)��ʼ������q\n");
	InitQueue(q);
	printf("  (2)���ν�����Ԫ��a,b,c\n");
	if (!enQueue(q,'a')) printf("\t��ʾ:����,���ܽ���\n");
	if (!enQueue(q,'b')) printf("\t��ʾ:����,���ܽ���\n");
	if (!enQueue(q,'c')) printf("\t��ʾ:����,���ܽ���\n");
	printf("  (3)����Ϊ%s\n",(QueueEmpty(q)?"��":"�ǿ�"));
	if (deQueue(q,e)==0) 
		printf("�ӿ�,���ܳ���\n");
	else
		printf("  (4)����һ��Ԫ��%c\n",e);
	printf("  (5)���ν�����Ԫ��d,e,f\n");
	if (!enQueue(q,'d')) printf("\t��ʾ:����,���ܽ���\n");
	if (!enQueue(q,'e')) printf("\t��ʾ:����,���ܽ���\n");
	if (!enQueue(q,'f')) printf("\t��ʾ:����,���ܽ���\n");
	printf("  (6)����������:");
	while (!QueueEmpty(q))
	{	deQueue(q,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("  (7)�ͷŶ���\n");
	DestroyQueue(q);
}


