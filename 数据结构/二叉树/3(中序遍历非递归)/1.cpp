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
void InOrder1(BTNode *b)    //中序遍历的非递归算法
{
    BTNode *St[MaxSize],*p;
	int top = -1;
	if(b!=NULL)
	{
	    p = b;
		while(p!=NULL || top>-1)    //处理*p节点的左子树
		{                           //扫描*p的所有左节点并进栈
		    while(p!=NULL)
			{
			    top++;
				St[top] = p;
				p = p->lchild;
			}
			//执行到此处时，栈顶元素没有左孩子或左子树均已访问过
			if(top>-1)
			{
			    p = St[top];          //出栈 *p节点
				top--;
				printf("%c",p->data);    //访问之
				p = p->rchild;        //转向处理*p的右孩子节点
			}
		}
		printf("\n");
	}
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
int LeafNodes(BTNode *b)	//求二叉树b的叶子节点个数
{
	int num1,num2;
    if (b==NULL) 
		return 0;
    else if (b->lchild==NULL && b->rchild==NULL) 
		return 1;
    else
    {
        num1=LeafNodes(b->lchild);
        num2=LeafNodes(b->rchild);
        return (num1+num2);
	}
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
	int i;
	BTNode *b,*p,*s,*R;
	char *str="A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    CreateBTNode(b,str);
	InOrder1(b);
	i = LeafNodes(b);
	printf("叶子节点的数目是:%d\n",i);
	return 0;
}
