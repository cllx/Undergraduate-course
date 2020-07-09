//�ļ���:exp3-3.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 5
typedef char ElemType;
typedef struct 
{
	ElemType elem[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
extern void InitQueue(SqQueue *q);
extern void DestroyQueue(SqQueue *&q);
extern bool QueueEmpty(SqQueue *q);
extern bool enQueue(SqQueue *&q,ElemType e);
extern bool deQueue(SqQueue *&q,ElemType &e);
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
