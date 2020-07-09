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
	//定义线性表指针
	int *p=L.elem;
	//查找元素e
	while(i<=L.length && *p++!=e)
		++i;
	if(i<=L.length)
		return i;
    else
		return ERROR;
}
/*求顺序表的长度*/
int GetListLength(Sq_List L)
{
	return L.length;
}

int Sq_ListDelete(Sq_List &L)
{
	int *p,*q,k;                                         //指向线性表位置i和尾指针
	k=0;
	for(int i=0;i<L.length;i++){
		if(L.elem[k]==L.elem[k+1]){
		    p=&(L.elem[k]);                              //被删除元素的位置
			q=L.elem+L.length-1;                         //q指针指向线性表最后一个
			for(p++;p<=q;++p){
				*(p-1)=*p;                               //被删除元素之后的元素左移
			}
			--L.length;     
		}else{
		    k++;
		}
	}
	if(L.elem[L.length-1]==L.elem[L.length-2]){
	    --L.length;
	}
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

//遍历顺序表
void Sq_ListInsert(Sq_List &L)
{ 
    int i=0;
	for(i;i<L.length;i++){
	    printf("\n顺序表中第%d个数是：%d",i+1,L.elem[i]);
	}

}

void main(){
	Sq_List R;//实参定义
	int flag;
	//为了判断调用成功与否，可以检查flag的值，或者见插入操作的调用方法
	//if(flag==1) printf("成功");
	//else printf("失败");
	flag=Sq_ListInit(R);

	//这样调用
	int i=1;
	int elem;
	printf("the length of current list is %d\n",GetListLength(R));
    for(i;i<List_INC_SPACE;i++){
		printf("input the element order by num:");
		scanf("%d",&elem);
		Sq_ListInsert(R,i,elem);
	}
	printf("successed!\n");
	printf("the length of current list is %d\n",GetListLength(R));
	Sq_ListDelete(R);
	Sq_ListInsert(R);
	printf("\n the length of current list is %d\n",GetListLength(R));
}