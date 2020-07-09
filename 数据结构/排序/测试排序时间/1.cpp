#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define N 12000
typedef int KeyType;
typedef char InfoType[10];

typedef struct       	                 //记录类型
{
	KeyType key;   		                 //关键字项
	InfoType data; 		                 //其他数据项,类型为InfoType
} RecType;

typedef struct       	                 //记录类型
{
	long key;   		                 //关键字项
	char data[50];
} Time;

//直接插入排序
void InsertSort(RecType R[],int n)
{
	int i,j;
	RecType temp;
	for (i=1;i<n;i++)
	{
		temp=R[i];
		j=i-1;           	             //从右向左在有序区R[0..i-1]中找R[i]的插入位置
		while (j>=0 && temp.key<R[j].key)
		{
			R[j+1]=R[j];	             //将关键字大于R[i].key的记录后移
			j--;
		}
        R[j+1]=temp;			         //在j+1处插入R[i]
	}
	printf("\n");
}

//希尔排序算法
void ShellSort(RecType R[],int n)
{
	int i,j,d;
	RecType temp;
	d=n/2;					             //d取初值n/2
	while (d>0)
	{
		for (i=d;i<n;i++)	             //将R[d..n-1]分别插入各组当前有序区中
		{
			j=i-d;
			while (j>=0 && R[j].key>R[j+d].key)
			{
				temp=R[j];               //R[j]与R[j+d]交换
				R[j]=R[j+d];
				R[j+d]=temp;
				j=j-d;
			}
		}
        d=d/2;                           //递减增量d
	}
	printf("\n");
}

//冒泡排序算法
void BubbleSort(RecType R[],int n)
{
	int i,j;
	RecType temp;
	for (i=0;i<n-1;i++)
	{
		for (j=n-1;j>i;j--)	             //比较,找出本趟最小关键字的记录
			if (R[j].key<R[j-1].key)
			{
				temp=R[j];               //R[j]与R[j-1]进行交换,将最小关键字记录前移
				R[j]=R[j-1];
				R[j-1]=temp;
			}
	}
	printf("\n");
}

//快速排序
void QuickSort(RecType R[],int s,int t)
{
	int i=s,j=t,k;
	RecType temp;
	if (s<t) 					                    //区间内至少存在一个元素的情况
	{	
		temp=R[s];     			                    //用区间的第1个记录作为基准
        while (i!=j)  			                    //从区间两端交替向中间扫描,直至i=j为止
		{	
			while (j>i && R[j].key>temp.key) 
			    j--;  			                    //从右向左扫描,找第1个关键字小于temp.key的R[j]
			R[i]=R[j];
            while (i<j && R[i].key<temp.key) 
			    i++;			                    //从左向右扫描,找第1个关键字大于temp.key的记录R[i] 
			R[j]=R[i];
		}
		R[i]=temp;
		QuickSort(R,s,i-1);		                    //对左区间递归排序
		QuickSort(R,i+1,t);		                    //对右区间递归排序
	}
}

//直接选择排序算法
void SelectSort(RecType R[],int n)
{
	int i,j,k;
	RecType temp;
	for (i=0;i<n-1;i++)    	 	         //做第i趟排序
	{
		k=i;
		for (j=i+1;j<n;j++)  	         //在当前无序区R[i..n-1]中选key最小的R[k]
			if (R[j].key<R[k].key)
				k=j;           	         //k记下目前找到的最小关键字所在的位置
		if (k!=i)          		         //交换R[i]和R[k]
		{
			temp=R[i];R[i]=R[k];R[k]=temp;
		}
	}
	printf("\n");
}

void DispSort(RecType R[])
{
    int n = 10,k;
	for (k=0;k<n;k++)
		printf("%2d  ",R[k].key);
	printf("\n\n");
}

void BijiaoTime(Time D[],int n){
	int i,j,k;
	Time temp;
	for (i=0;i<n-1;i++)
	{
		k=i;
		for (j=i+1;j<n;j++)
			if (D[j].key < D[k].key)
				k=j;
		if (k!=i)
		{
			temp=D[i];D[i]=D[k];D[k]=temp;
		}
	}
	for(i = 0;i < n;i++){
	    printf("排序时间第%d快的是:%s\n",i+1,D[i].data);
	}
}

int main()
{
	char a[5];
	int i,n=N,j;
	long t1,t2;
	RecType R[N],T[N],A[N],B[N],P[N];
	Time D[5];
	srand(0);
	printf("此测试都只显示数组前十个元素\n\n");
	for (i=0;i<n;i++){
		R[i].key = rand();
		T[i].key = R[i].key;
		A[i].key = R[i].key;
		B[i].key = R[i].key;
		P[i].key = R[i].key;
	}
	for(j = 0;j < 5;j++){
		printf("输入你要选择的排序方式,直接选择排序输入S,快速排序输入Q,冒泡排序输入B,希尔排序输入L,直接插入排序输入I:");
		gets(&a[j]);
		if(a[j] == 'S'){
			printf("\n初始关键字:");
	        DispSort(R);
			printf("直接选择排序\n");
			t1 = time(NULL);
			SelectSort(R,n);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"直接选择排序");
			printf("最后结果:");
			DispSort(R);
			printf("排序的时间为: %lf seconds\n\n",difftime(t2,t1));
		}
		else if(a[j] == 'Q'){
			printf("\n初始关键字:");
	        DispSort(T);
		    printf("快速排序\n\n");
			t1 = time(NULL);
			QuickSort(T,0,n-1);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"快速排序");
			printf("最后结果:");
			DispSort(T);
			printf("排序的时间为: %lf\n\n",difftime(t2,t1));
		}
		else if(a[j] == 'B'){
			printf("\n初始关键字:");
	        DispSort(A);
		    printf("冒泡排序\n");
			t1 = time(NULL);
			BubbleSort(A,n);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"冒泡排序");
			printf("最后结果:");
			DispSort(A);
			printf("排序的时间为: %lf\n\n",difftime(t2,t1));
		}
		else if(a[j] == 'L'){
			printf("\n初始关键字:");
	        DispSort(B);
		    printf("希尔排序\n");
			t1 = time(NULL);
			ShellSort(B,n);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"希尔排序");
			printf("最后结果:");
			DispSort(B);
			printf("排序的时间为: %lf\n\n",difftime(t2,t1));
		}
		else if(a[j] == 'I'){
			printf("\n初始关键字:");
	        DispSort(P);
		    printf("直接插入排序\n");
			t1 = time(NULL);
			InsertSort(P,n);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"直接插入排序");
			printf("最后结果:");
			DispSort(P);
			printf("排序的时间为: %lf\n\n",difftime(t2,t1));
		}
		else{
		    printf("输入不合规则");
		}
	}
	BijiaoTime(D,5);
	printf("\n");
	return 0;
}
