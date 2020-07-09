#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define List_INIT_SPACE 100//����ռ��ʼ������
#define List_INC_SPACE 10//����ռ��������

typedef int ElemType;//ָ��˳�������������

typedef struct{
    ElemType *elem;//�洢�ռ��ַ
	int length;//��ǰ����
    int listsize;//��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}Sq_List;

int Sq_ListInit(Sq_List &L){
    L.elem=(ElemType*) malloc (List_INIT_SPACE *sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);//�洢����ʧ��
	//����һ���յ����Ա�L
	L.length=0;
	L.listsize=List_INC_SPACE;//��ʼ�洢����
	return OK;
}//����Sq_ListInit����

int LocateElem(Sq_List L,int e)
{
	int i=1;
	//�������Ա�ָ��
	int *p=L.elem;
	//����Ԫ��e
	while(i<=L.length && *p++!=e)
		++i;
	if(i<=L.length)
		return i;
    else
		return ERROR;
}
/*��˳���ĳ���*/
int GetListLength(Sq_List L)
{
	return L.length;
}
int Sq_ListDelete(Sq_List &L,int i, ElemType &e)
{
	//�ж�λ���Ƿ�Ϸ�
	if(i<1||i>L.length+1)
	{
		printf("i��ֵ���Ϸ���\n");
		return 0;
	}
	int *p,*q;//ָ�����Ա�λ��i��βָ��
	p=&(L.elem[i-1]);//��ɾ��Ԫ�ص�λ��
	e=*p;//ȡɾ��Ԫ��ֵ
	q=L.elem+L.length-1;//qָ��ָ�����Ա����һ��
	for(++p;p<=q;++p)
	*(p-1)=*p;//��ɾ��Ԫ��֮���Ԫ������
	--L.length;//���Ա��ȼ�1                 
	return OK;
}//����Sq_ListDelete����

/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
int Sq_ListInsert(Sq_List &L,int i,ElemType e)
{ 
	int k;
	if (L.length==L.listsize)/* ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>L.length+1) /* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;

	if (i<=L.length)         /* ����������λ�ò��ڱ�β */
	{
		for(k=L.length-1;k>=i-1;k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */
			L.elem[k+1]=L.elem[k];
	}
	L.elem[i-1]=e;          /* ����Ԫ�ز��� */
	L.length++;

	return OK;
}

void main(){
	Sq_List R;//ʵ�ζ���
	int flag;
	//Ϊ���жϵ��óɹ���񣬿��Լ��flag��ֵ�����߼���������ĵ��÷���
	//if(flag==1) printf("�ɹ�");
	//else printf("ʧ��");
	flag=Sq_ListInit(R);

	//��������
	int i=1;
	int elem;
	printf("the length of current list is %d\n",GetListLength(R));

	printf("input the element:");
	scanf("%d",&elem);
	if(Sq_ListInsert(R,i,elem)) printf("successed!\n");
	printf("the length of current list is %d\n",GetListLength(R));
	//Sq_ListInsert(R,i,elme);//����ֱ�ӵ���
}