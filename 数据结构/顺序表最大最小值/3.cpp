#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define List_INIT_SPACE 100//储存空间初始分配量
#define List_INC_SPACE 10//储存空间分配增量

typedef int ElemType;//指定顺序表中数据类型

typedef struct{
    ElemType *elem;//存储空间基址
	int length;//当前长度
    int listsize;//当前分配的存储容量(以sizeof(ElemType)为单位)
}Sq_List;

int Sq_ListInit(Sq_List &L){
    L.elem=(ElemType*) malloc (List_INIT_SPACE *sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);//存储分配失败
	//构造一个空的线性表L
	L.length=0;
	L.listsize=List_INC_SPACE;//初始存储容量
	return OK;
}//函数Sq_ListInit结束

int LocateElem(Sq_List L,int e)
{
	int i=1;
	int *p=L.elem;
	//查找元素e
	while(i<=L.length && *p++!=e)
		++i;
	if(i<=L.length)
		return i;
    else
		return ERROR;
}
//求顺序表的长度
int GetListLength(Sq_List L)
{
	return L.length;
}
//查找最大值和最小值
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
	printf("\n最大值是第%d个数:%d",MAXi,MAX);
	printf("\n最小值是第%d个数:%d\n",MINi,MIN);
	return OK;
}                                                        //函数Sq_ListDelete结束

int Sq_ListInsert(Sq_List &L,int i,ElemType e)
{ 
	int k;
	if (L.length==L.listsize)                            //顺序线性表已经满
		return ERROR;
	if (i<1 || i>L.length+1)                             //当i比第一位置小或者比最后一位置后一位置还要大时
		return ERROR;

	if (i<=L.length)                                     //若插入数据位置不在表尾
	{
		for(k=L.length-1;k>=i-1;k--)                     //将要插入位置之后的数据元素向后移动一位
			L.elem[k+1]=L.elem[k];
	}
	L.elem[i-1]=e;                                       //将新元素插入
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