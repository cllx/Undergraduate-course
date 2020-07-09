#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ������
	struct node *rchild;		//ָ���Һ���
} BTNode;
void CreateBTNode(BTNode *&b,char *str)		//��str������������
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')	//strδɨ����ʱѭ��
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//Ϊ��ڵ�
		case ')':top--;break;
		case ',':k=2; break;                      	//Ϊ�ҽڵ�
		default:p=(BTNode *)malloc(sizeof(BTNode));
			p->data=ch;p->lchild=p->rchild=NULL;
		         	if (b==NULL)                    //pָ��������ĸ��ڵ�
						b=p;
					else  							//�ѽ������������ڵ�
					{	
						switch(k) 
						{
						case 1:St[top]->lchild=p;break;
						case 2:St[top]->rchild=p;break;
						}
					}
		}
		j++;
		ch=str[j];
	}
}
int LevelOrder(BTNode *b)
{
    BTNode *p;
	BTNode *qu[MaxSize];
	int front,rear,i=0;
	front = rear = -1;
	rear++;
	qu[rear] = b;
	while(front != rear)
	{
	    front = (front+1)%MaxSize;
		p = qu[front];
		printf("%c",p->data);
		if(p->rchild!=NULL && p->lchild!=NULL)
		{
		    i++;
		}
		if(p->lchild!=NULL)
		{
		    rear = (rear+1)%MaxSize;
			qu[rear] = p->lchild;
		}
		if(p->rchild!=NULL)
		{
		    rear = (rear+1)%MaxSize;
			qu[rear] = p->rchild;
		}
	}
	return i;
}
void DispBTNode(BTNode *b)	//�����ű�ʾ�����������
{
	if (b!=NULL)
	{
		printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispBTNode(b->lchild);
			if (b->rchild!=NULL) printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
	printf("\n");
}
void DestroyBTNode(BTNode *&b)
{
	if (b!=NULL)
	{
		DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}

int main(){
	int i,j,m,n;
	BTNode *b,*p,*s,*R;
	char *str="A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    CreateBTNode(b,str);
	i=LevelOrder(b);
	DispBTNode(b);
	printf("\n����Ϊ2�Ľڵ�ĸ�����:%d\n",i);
	DestroyBTNode(b);
	return 0;
}
