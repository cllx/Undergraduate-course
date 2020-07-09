#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;				//数据元素
	struct node *lchild;		//指向左孩子
	struct node *rchild;		//指向右孩子
} BTNode;
void CreateBTNode(BTNode *&b,char *str)		//由str串创建二叉链
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')	//str未扫描完时循环
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//为左节点
		case ')':top--;break;
		case ',':k=2; break;                      	//为右节点
		default:p=(BTNode *)malloc(sizeof(BTNode));
			p->data=ch;p->lchild=p->rchild=NULL;
		         	if (b==NULL)                    //p指向二叉树的根节点
						b=p;
					else  							//已建立二叉树根节点
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
void DispBTNode(BTNode *b)	//以括号表示法输出二叉树
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
	printf("\n度数为2的节点的个数是:%d\n",i);
	DestroyBTNode(b);
	return 0;
}
