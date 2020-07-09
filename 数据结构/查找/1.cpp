#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;					//定义关键字类型
typedef char InfoType;
typedef struct node               		//记录类型
{	
	KeyType key;                  		//关键字项
    InfoType data;               		//其他数据域
    struct node *lchild,*rchild;		//左右孩子指针
} BSTNode;
int path[MaxSize];						//全局变量,用于存放路径
void DispBST(BSTNode *b);				//函数说明
int InsertBST(BSTNode *&p,KeyType k)	//在以*p为根节点的BST中插入一个关键字为k的节点
{
   	if (p==NULL)						//原树为空, 新插入的记录为根节点
	{
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=k;p->lchild=p->rchild=NULL;
		return 1;
	}
	else if (k==p->key) 
		return 0;
	else if (k<p->key) 
		return InsertBST(p->lchild,k);	//插入到*p的左子树中
	else  
		return InsertBST(p->rchild,k);  //插入到*p的右子树中
}
BSTNode *CreatBST(KeyType A[],int n)				
//由数组A中的关键字建立一棵二叉排序树
{
  	BSTNode *bt=NULL;         			//初始时bt为空树
   	int i=0;
   	while (i<n) 
		if (InsertBST(bt,A[i])==1)		//将A[i]插入二叉排序树T中
		{
			printf("    第%d步,插入%d:",i+1,A[i]);
			DispBST(bt);printf("\n");
			i++;
		}
    return bt;               			//返回建立的二叉排序树的根指针
}
void SearchBST1(BSTNode *bt,KeyType k,KeyType path[],int i)	
//以非递归方式输出从根节点到查找到的节点的路径
{ 
	int j;
	if (bt==NULL){
		printf("不存在该分数的学校\n");
		return;
	}
	else if (k==bt->key)	//找到了节点
	{
		path[i+1]=bt->key;	//输出其路径
		printf("你要查询的学校是:%d",path[i+1]);
		printf("\n");
		return;
	}
	else
	{
		path[i+1]=bt->key;
		if (k<bt->key)
			SearchBST1(bt->lchild,k,path,i+1);  //在左子树中递归查找
		else
			SearchBST1(bt->rchild,k,path,i+1);  //在右子树中递归查找
	}
}
int SearchBST2(BSTNode *bt,KeyType k,KeyType p)		
//以递归方式输出从根节点到查找到的节点的路径
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
		SearchBST2(bt->rchild,k,p);  //在右子树中递归查找
	else if (p<bt->key)
		SearchBST2(bt->lchild,k,p);  //在右子树中递归查找
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
			SearchBST3(bt->rchild,k,path,i+1);  //在右子树中递归查找
		}else{
			path[i+1]=bt->key;
			printf("%d ",path[i+1]);
			SearchBST3(bt->rchild,k,path,i+1);  //在右子树中递归查找
			SearchBST3(bt->lchild,k,path,i+1);  //在左子树中递归查找
		}
	}
	else
		SearchBST3(bt->rchild,k,path,i+1);  //在右子树中递归查找

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
int JudgeBST(BSTNode *bt)	//判断bt是否为BST
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
	printf("创建一棵BST树:");
	printf("\n");
	bt=CreatBST(a,n);
	while(1){
		printf("请输入你想查找的分数:");
		scanf("%d",&k);
		SearchBST1(bt,k,path,-1);
		printf("大于等于你给的分数的学校是:");
		SearchBST3(bt,k,path,-1);
		printf("\n请输入你要查询的分数段:");
		scanf("%d,%d",&k,&p);
		printf("最低录取分数线在该分数段的学校有:");
		SearchBST2(bt,k,p);
		printf("\n你是否想要继续插入高校,是请输入1，否输入0:");
		scanf("%d",&i);
		if(i==1){
			printf("输入你要插入高校的分数线:");
			scanf("%d",&j);
			InsertBST(bt,j);
		}else
			break;
	}
	printf("\n");
	DispBST(bt);
	printf("\n插入查询操作结束");
}
