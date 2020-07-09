#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef char ElemType;
typedef struct
{
    ElemType *base;             //ջ��
    ElemType *top;              //ջ��
    int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if( !s->base )
    {
        exit(0);
    }

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{
    if( s->top - s->base >= s->stackSize )
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
        {
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
    if( s->top == s->base )
    {
        return;
    }
    *e = *--(s->top);
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
    ElemType c;
    sqStack s,q;
    int len, i,j,n=3;
	int sum=0;

    InitStack(&s);
    InitStack(&q);

    printf("�������������������#���ű�ʾ������\n");
    scanf("%c", &c);
    while( c != '#' )
    {
        Push(&s, c);
        scanf("%c", &c);//���ǰһ��scanf��������ַ���,��ô�����scanf�Ͳ����������ˣ���ǰ��Ļ�������ȡ��û�ж�����ַ�
    }

    getchar();  // ��'\n'�ӻ�����ȥ��

    len = StackLen(s);
    printf("ջ�ĵ�ǰ������: %d\n", len);

    for( i=0; i < len; i+=n )
    {
		if(len-i==1){
			j=0;
			for(j=0;j<1;j++){
				Pop(&s, &c);
				sum = sum + (c-48) * pow(2, j);
			};
			Push(&q, sum);
			break;
		}else if(len-i==2){
			j=0;
			for(j=0;j<2;j++){
				Pop(&s, &c);
				sum = sum + (c-48) * pow(2, j);
			};
			Push(&q, sum);
			break;
		}
		j=0;
		for(j=0;j<3;j++){
			Pop(&s, &c);
			sum = sum + (c-48) * pow(2, j);
		};
		Push(&q, sum);
		sum=0;
    }

	len = StackLen(q);
	printf("������ת��Ϊ�˽�������:");
	for( i=0; i < len; i++ ){
		Pop(&q, &c);
	    printf("%d", c);
	}
    printf("\n", c);
    return 0;
}