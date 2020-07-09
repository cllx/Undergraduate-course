#include <stdio.h>
#include <malloc.h>
#define MAX 20			//����ʽ�������
typedef struct			//�����Ŷ���ʽ����������
{
	double coef;		//ϵ��
	int exp;			//ָ��
}PolyArray;
typedef struct pnode	//���嵥����������
{
	double coef;		//ϵ��
	int exp;			//ָ��
	struct pnode *next;
}PolyNode;
void DispPoly(PolyNode *L)	//�������ʽ
{
	bool first=true;		//firstΪtrue��ʾ�ǵ�һ��
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
void DestroyList(PolyNode *&L)	//���ٵ�����
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
void CreateListR(PolyNode *&L,PolyArray a[],int n) //β�巨����
{
	PolyNode *s,*r;int i;
	L=(PolyNode *)malloc(sizeof(PolyNode));	//����ͷ���
	L->next=NULL;
	r=L;						//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));//�����½��
		s->coef=a[i].coef;
		s->exp=a[i].exp;
		r->next=s;				//��*s����*r֮��
		r=s;
	}
	r->next=NULL;				//�ն˽��next����ΪNULL
}
void Sort(PolyNode *&head)		//��exp��ݼ�����
{
	PolyNode *p=head->next,*q,*r;
	if (p!=NULL)				//��ԭ����������һ�������ϵ����ݽ��
	{
		r=p->next;				//r����*p����̽���ָ��
		p->next=NULL;			//����ֻ��һ�����ݽ��������
		p=r;
		while (p!=NULL)
		{
			r=p->next;			//r����*p����̽���ָ��
			q=head;
			while (q->next!=NULL && q->next->exp>p->exp) 
				q=q->next;		//����������Ҳ���*p��ǰ�����*q
			if(q->next==p) ;
			else{
				p->next=q->next;	//��*p���뵽*q֮��
				q->next=p;
			}
			p=r;
		}
	}
}
void Add(PolyNode *&ha,PolyNode *hb,PolyNode *&hc)  //�������򼯺ϵĲ�
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
	    printf("������ϵ��:");
		scanf("%f",&polynome1[i].coef);
		printf("������ָ��:");
		scanf("%f",&polynome1[i].exp);
	}
    CreateListR(L,polynome1,4);
	Sort(L);
	DispPoly(L);
	for(i=0;i<5;i++){
	    printf("������ϵ��:");
		scanf("%f",&polynome2[i].coef);
		printf("������ָ��:");
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

