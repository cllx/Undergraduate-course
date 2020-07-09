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
void InOrder1(BTNode *b)    //��������ķǵݹ��㷨
{
    BTNode *St[MaxSize],*p;
	int top = -1;
	if(b!=NULL)
	{
	    p = b;
		while(p!=NULL || top>-1)    //����*p�ڵ��������
		{                           //ɨ��*p��������ڵ㲢��ջ
		    while(p!=NULL)
			{
			    top++;
				St[top] = p;
				p = p->lchild;
			}
			//ִ�е��˴�ʱ��ջ��Ԫ��û�����ӻ����������ѷ��ʹ�
			if(top>-1)
			{
			    p = St[top];          //��ջ *p�ڵ�
				top--;
				printf("%c",p->data);    //����֮
				p = p->rchild;        //ת����*p���Һ��ӽڵ�
			}
		}
		printf("\n");
	}
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
int LeafNodes(BTNode *b)	//�������b��Ҷ�ӽڵ����
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
	printf("Ҷ�ӽڵ����Ŀ��:%d\n",i);
	return 0;
}
