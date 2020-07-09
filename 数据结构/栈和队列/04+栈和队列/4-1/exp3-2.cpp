//�ļ���:exp3-2.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct linknode
{
	ElemType data;				//������
	struct linknode *next;		//ָ����
} LiStack;
extern void InitStack(LiStack *&s);
extern void DestroyStack(LiStack *&s);
extern bool StackEmpty(LiStack *s);
extern void Push(LiStack *&s,ElemType e);
extern bool Pop(LiStack *&s,ElemType &e);
extern bool GetTop(LiStack *s,ElemType &e);
void main()
{
	ElemType e;
	LiStack *s;
	printf("ջs�Ļ�����������:\n");
	printf("  (1)��ʼ��ջs\n");
	InitStack(s);
	printf("  (2)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("  (3)���ν�ջԪ��a,b,c,d,e\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	printf("  (4)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("  (5)��ջ����:");
	while (!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("  (6)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("  (7)�ͷ�ջ\n");
	DestroyStack(s);
}
