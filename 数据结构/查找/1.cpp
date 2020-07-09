#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;					//����ؼ�������
typedef char InfoType;
typedef struct node               		//��¼����
{	
	KeyType key;                  		//�ؼ�����
    InfoType data;               		//����������
    struct node *lchild,*rchild;		//���Һ���ָ��
} BSTNode;
int path[MaxSize];						//ȫ�ֱ���,���ڴ��·��
void DispBST(BSTNode *b);				//����˵��
int InsertBST(BSTNode *&p,KeyType k)	//����*pΪ���ڵ��BST�в���һ���ؼ���Ϊk�Ľڵ�
{
   	if (p==NULL)						//ԭ��Ϊ��, �²���ļ�¼Ϊ���ڵ�
	{
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=k;p->lchild=p->rchild=NULL;
		return 1;
	}
	else if (k==p->key) 
		return 0;
	else if (k<p->key) 
		return InsertBST(p->lchild,k);	//���뵽*p����������
	else  
		return InsertBST(p->rchild,k);  //���뵽*p����������
}
BSTNode *CreatBST(KeyType A[],int n)				
//������A�еĹؼ��ֽ���һ�ö���������
{
  	BSTNode *bt=NULL;         			//��ʼʱbtΪ����
   	int i=0;
   	while (i<n) 
		if (InsertBST(bt,A[i])==1)		//��A[i]�������������T��
		{
			printf("    ��%d��,����%d:",i+1,A[i]);
			DispBST(bt);printf("\n");
			i++;
		}
    return bt;               			//���ؽ����Ķ����������ĸ�ָ��
}
void SearchBST1(BSTNode *bt,KeyType k,KeyType path[],int i)	
//�Էǵݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
{ 
	int j;
	if (bt==NULL){
		printf("�����ڸ÷�����ѧУ\n");
		return;
	}
	else if (k==bt->key)	//�ҵ��˽ڵ�
	{
		path[i+1]=bt->key;	//�����·��
		printf("��Ҫ��ѯ��ѧУ��:%d",path[i+1]);
		printf("\n");
		return;
	}
	else
	{
		path[i+1]=bt->key;
		if (k<bt->key)
			SearchBST1(bt->lchild,k,path,i+1);  //���������еݹ����
		else
			SearchBST1(bt->rchild,k,path,i+1);  //���������еݹ����
	}
}
int SearchBST2(BSTNode *bt,KeyType k,KeyType p)		
//�Եݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
{ 
	if (bt==NULL)
		return 0;
	else if (k<=bt->key && p>=bt->key)
	{
		printf("%d ",bt->key);
		SearchBST2(bt->rchild,k,p);
		SearchBST2(bt->lchild,k,p);
		return 1;
	}
	else if (k>bt->key)
		SearchBST2(bt->rchild,k,p);  //���������еݹ����
	else if (p<bt->key)
		SearchBST2(bt->lchild,k,p);  //���������еݹ����
}

void SearchBST3(BSTNode *bt,KeyType k,KeyType path[],int i)	
{ 
	if (bt==NULL)
		return;
	else if (k<=bt->key)
	{
		if(k==bt->key){
			path[i+1]=bt->key;
			printf("%d ",path[i+1]);
			SearchBST3(bt->rchild,k,path,i+1);  //���������еݹ����
		}else{
			path[i+1]=bt->key;
			printf("%d ",path[i+1]);
			SearchBST3(bt->rchild,k,path,i+1);  //���������еݹ����
			SearchBST3(bt->lchild,k,path,i+1);  //���������еݹ����
		}
	}
	else
		SearchBST3(bt->rchild,k,path,i+1);  //���������еݹ����

}

void DispBST(BSTNode *bt)	
{
	if (bt!=NULL)
	{
		printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{
			printf("(");
			DispBST(bt->lchild);
			if (bt->rchild!=NULL) printf(",");
			DispBST(bt->rchild);
			printf(")");
		}
	}
}
KeyType predt=-32767;
int JudgeBST(BSTNode *bt)	//�ж�bt�Ƿ�ΪBST
{
	int b1,b2;
	if (bt==NULL)
		return 1;
	else 
	{
		b1=JudgeBST(bt->lchild);
		if (b1==0 || predt>=bt->key)
			return 0;
		predt=bt->key;
		b2=JudgeBST(bt->rchild);
		return b2;
	}
}
void main()
{
	BSTNode *bt;
	KeyType i,j,k,p;
	int a[]={4,9,0,1,8},n=5;
	printf("����һ��BST��:");
	printf("\n");
	bt=CreatBST(a,n);
	while(1){
		printf("������������ҵķ���:");
		scanf("%d",&k);
		SearchBST1(bt,k,path,-1);
		printf("���ڵ�������ķ�����ѧУ��:");
		SearchBST3(bt,k,path,-1);
		printf("\n��������Ҫ��ѯ�ķ�����:");
		scanf("%d,%d",&k,&p);
		printf("���¼ȡ�������ڸ÷����ε�ѧУ��:");
		SearchBST2(bt,k,p);
		printf("\n���Ƿ���Ҫ���������У,��������1��������0:");
		scanf("%d",&i);
		if(i==1){
			printf("������Ҫ�����У�ķ�����:");
			scanf("%d",&j);
			InsertBST(bt,j);
		}else
			break;
	}
	printf("\n");
	DispBST(bt);
	printf("\n�����ѯ��������");
}
