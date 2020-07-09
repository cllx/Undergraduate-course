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
	int *p=L.elem;
	//����Ԫ��e
	while(i<=L.length && *p++!=e)
		++i;
	if(i<=L.length)
		return i;
    else
		return ERROR;
}
//��˳���ĳ���
int GetListLength(Sq_List L)
{
	return L.length;
}
//�������ֵ����Сֵ
int Sq_ListMaxMin(Sq_List &L)
{
	int MAX,MIN,MAXi,MINi;
    MAX=L.elem[0];
	MIN=L.elem[0];
	for(int i=1;i<L.length;i++){
		if(MAX<=L.elem[i]){
		    MAX=L.elem[i];
			MAXi=i+1;
		}
		if(MIN>=L.elem[i]){
		    MIN=L.elem[i];
			MINi=i+1;
		}
	}
	printf("\n���ֵ�ǵ�%d����:%d",MAXi,MAX);
	printf("\n��Сֵ�ǵ�%d����:%d\n",MINi,MIN);
	return OK;
}                                                        //����Sq_ListDelete����

int Sq_ListInsert(Sq_List &L,int i,ElemType e)
{ 
	int k;
	if (L.length==L.listsize)                            //˳�����Ա��Ѿ���
		return ERROR;
	if (i<1 || i>L.length+1)                             //��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ
		return ERROR;

	if (i<=L.length)                                     //����������λ�ò��ڱ�β
	{
		for(k=L.length-1;k>=i-1;k--)                     //��Ҫ����λ��֮�������Ԫ������ƶ�һλ
			L.elem[k+1]=L.elem[k];
	}
	L.elem[i-1]=e;                                       //����Ԫ�ز���
	L.length++;

	return OK;
}

void main(){
	Sq_List R;
	int flag;
	flag=Sq_ListInit(R);

	int i=1;
	int elem;
	printf("the length of current list is %d\n",GetListLength(R));
    for(i;i<List_INC_SPACE;i++){
		printf("input the elemen num:");
		scanf("%d",&elem);
		Sq_ListInsert(R,i,elem);
	}
	printf("successed!\n");
	printf("the length of current list is %d\n",GetListLength(R));
	Sq_ListMaxMin(R);
}