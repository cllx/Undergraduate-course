#include <stdio.h>
#include <malloc.h>
#define MAX 20			//多项式最多项数
typedef struct			//定义存放多项式的数组类型
{
	double coef;		//系数
	int exp;			//指数
}PolyArray;
typedef struct pnode	//定义单链表结点类型
{
	double coef;		//系数
	int exp;			//指数
	struct pnode *next;
}PolyNode;
void DispPoly(PolyNode *L)	//输出多项式
{
	bool first=true;		//first为true表示是第一项
	PolyNode *p=L->next;
	while (p!=NULL)
	{
		if (first)
			first=false;
		else if (p->coef>0)
			printf("+");
		if (p->exp==0)
			printf("%g",p->coef);
		else if (p->exp==1)
			printf("%gx",p->coef);
		else
			printf("%gx^%d",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");
}
void DestroyList(PolyNode *&L)	//销毁单链表
{
	PolyNode *p=L,*q=p->next;
	while (q!=NULL)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
void CreateListR(PolyNode *&L,PolyArray a[],int n) //尾插法建表
{
	PolyNode *s,*r;int i;
	L=(PolyNode *)malloc(sizeof(PolyNode));	//创建头结点
	L->next=NULL;
	r=L;						//r始终指向终端结点,开始时指向头结点
	for (i=0;i<n;i++)
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));//创建新结点
		s->coef=a[i].coef;
		s->exp=a[i].exp;
		r->next=s;				//将*s插入*r之后
		r=s;
	}
	r->next=NULL;				//终端结点next域置为NULL
}
void Sort(PolyNode *&head)		//按exp域递减排序
{
	PolyNode *p=head->next,*q,*r;
	if (p!=NULL)				//若原单链表中有一个或以上的数据结点
	{
		r=p->next;				//r保存*p结点后继结点的指针
		p->next=NULL;			//构造只含一个数据结点的有序表
		p=r;
		while (p!=NULL)
		{
			r=p->next;			//r保存*p结点后继结点的指针
			q=head;
			while (q->next!=NULL && q->next->exp>p->exp) 
				q=q->next;		//在有序表中找插入*p的前驱结点*q
			if(q->next==p) ;
			else{
				p->next=q->next;	//将*p插入到*q之后
				q->next=p;
			}
			p=r;
		}
	}
}
void Add(PolyNode *&ha,PolyNode *hb,PolyNode *&hc)  //求两有序集合的并
{
	hc=ha;
    while (ha->next!=NULL)
	{
		ha=ha->next;
	}
    ha->next=hb->next;
}
void main()
{
	PolyArray  polynome1[4],polynome2[5];
	PolyNode *L,*R,*S;
    int i;
    for(i=0;i<4;i++){
	    printf("请输入系数:");
		scanf("%f",&polynome1[i].coef);
		printf("请输入指数:");
		scanf("%f",&polynome1[i].exp);
	}
    CreateListR(L,polynome1,4);
	Sort(L);
	DispPoly(L);
	for(i=0;i<5;i++){
	    printf("请输入系数:");
		scanf("%f",&polynome2[i].coef);
		printf("请输入指数:");
		scanf("%f",&polynome2[i].exp);
	}
    CreateListR(R,polynome2,5);
	Sort(R);	
	DispPoly(R);
	Add(L,R,S);
	Sort(S);
    DispPoly(S);
    DestroyList(L);
	DestroyList(R);
	DestroyList(S);
}

