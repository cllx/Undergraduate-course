//�ļ���:exp7-1.cpp
#include <stdio.h>
typedef char ElemType;
typedef struct node
{
	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ������
	struct node *rchild;		//ָ���Һ���
} BTNode;
extern void CreateBTNode(BTNode *&b,char *str);
extern BTNode *FindNode(BTNode *b,ElemType x);
extern BTNode *LchildNode(BTNode *p);
extern BTNode *RchildNode(BTNode *p);
extern int BTNodeDepth(BTNode *b);
extern void DispBTNode(BTNode *b);
extern int BTWidth(BTNode *b);
extern int Nodes(BTNode *b);
extern int LeafNodes(BTNode *b);
extern void DestroyBTNode(BTNode *&b);
void main()
{	BTNode *b,*p,*lp,*rp;;
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("�������Ļ�����������:\n");
	printf("  (1)���������:");DispBTNode(b);printf("\n");
	printf("  (2)H�ڵ�:");
	p=FindNode(b,'H');
	if (p!=NULL)
	{	lp=LchildNode(p);
		if (lp!=NULL) 
			printf("����Ϊ%c ",lp->data);
		else
			printf("������ ");
		rp=RchildNode(p);
		if (rp!=NULL)
			printf("�Һ���Ϊ%c",rp->data);
		else
			printf("���Һ��� ");
	}
	printf("\n");
	printf("  (3)������b�����:%d\n",BTNodeDepth(b));
	printf("  (4)������b�Ŀ��:%d\n",BTWidth(b));
	printf("  (5)������b�Ľڵ����:%d\n",Nodes(b));
	printf("  (6)������b��Ҷ�ӽڵ����:%d\n",LeafNodes(b));
	printf("  (7)�ͷŶ�����b\n");
	DestroyBTNode(b);
}
