#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define N 12000
typedef int KeyType;
typedef char InfoType[10];

typedef struct       	                 //��¼����
{
	KeyType key;   		                 //�ؼ�����
	InfoType data; 		                 //����������,����ΪInfoType
} RecType;

typedef struct       	                 //��¼����
{
	long key;   		                 //�ؼ�����
	char data[50];
} Time;

//ֱ�Ӳ�������
void InsertSort(RecType R[],int n)
{
	int i,j;
	RecType temp;
	for (i=1;i<n;i++)
	{
		temp=R[i];
		j=i-1;           	             //����������������R[0..i-1]����R[i]�Ĳ���λ��
		while (j>=0 && temp.key<R[j].key)
		{
			R[j+1]=R[j];	             //���ؼ��ִ���R[i].key�ļ�¼����
			j--;
		}
        R[j+1]=temp;			         //��j+1������R[i]
	}
	printf("\n");
}

//ϣ�������㷨
void ShellSort(RecType R[],int n)
{
	int i,j,d;
	RecType temp;
	d=n/2;					             //dȡ��ֵn/2
	while (d>0)
	{
		for (i=d;i<n;i++)	             //��R[d..n-1]�ֱ������鵱ǰ��������
		{
			j=i-d;
			while (j>=0 && R[j].key>R[j+d].key)
			{
				temp=R[j];               //R[j]��R[j+d]����
				R[j]=R[j+d];
				R[j+d]=temp;
				j=j-d;
			}
		}
        d=d/2;                           //�ݼ�����d
	}
	printf("\n");
}

//ð�������㷨
void BubbleSort(RecType R[],int n)
{
	int i,j;
	RecType temp;
	for (i=0;i<n-1;i++)
	{
		for (j=n-1;j>i;j--)	             //�Ƚ�,�ҳ�������С�ؼ��ֵļ�¼
			if (R[j].key<R[j-1].key)
			{
				temp=R[j];               //R[j]��R[j-1]���н���,����С�ؼ��ּ�¼ǰ��
				R[j]=R[j-1];
				R[j-1]=temp;
			}
	}
	printf("\n");
}

//��������
void QuickSort(RecType R[],int s,int t)
{
	int i=s,j=t,k;
	RecType temp;
	if (s<t) 					                    //���������ٴ���һ��Ԫ�ص����
	{	
		temp=R[s];     			                    //������ĵ�1����¼��Ϊ��׼
        while (i!=j)  			                    //���������˽������м�ɨ��,ֱ��i=jΪֹ
		{	
			while (j>i && R[j].key>temp.key) 
			    j--;  			                    //��������ɨ��,�ҵ�1���ؼ���С��temp.key��R[j]
			R[i]=R[j];
            while (i<j && R[i].key<temp.key) 
			    i++;			                    //��������ɨ��,�ҵ�1���ؼ��ִ���temp.key�ļ�¼R[i] 
			R[j]=R[i];
		}
		R[i]=temp;
		QuickSort(R,s,i-1);		                    //��������ݹ�����
		QuickSort(R,i+1,t);		                    //��������ݹ�����
	}
}

//ֱ��ѡ�������㷨
void SelectSort(RecType R[],int n)
{
	int i,j,k;
	RecType temp;
	for (i=0;i<n-1;i++)    	 	         //����i������
	{
		k=i;
		for (j=i+1;j<n;j++)  	         //�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k]
			if (R[j].key<R[k].key)
				k=j;           	         //k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
		if (k!=i)          		         //����R[i]��R[k]
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
	    printf("����ʱ���%d�����:%s\n",i+1,D[i].data);
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
	printf("�˲��Զ�ֻ��ʾ����ǰʮ��Ԫ��\n\n");
	for (i=0;i<n;i++){
		R[i].key = rand();
		T[i].key = R[i].key;
		A[i].key = R[i].key;
		B[i].key = R[i].key;
		P[i].key = R[i].key;
	}
	for(j = 0;j < 5;j++){
		printf("������Ҫѡ�������ʽ,ֱ��ѡ����������S,������������Q,ð����������B,ϣ����������L,ֱ�Ӳ�����������I:");
		gets(&a[j]);
		if(a[j] == 'S'){
			printf("\n��ʼ�ؼ���:");
	        DispSort(R);
			printf("ֱ��ѡ������\n");
			t1 = time(NULL);
			SelectSort(R,n);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"ֱ��ѡ������");
			printf("�����:");
			DispSort(R);
			printf("�����ʱ��Ϊ: %lf seconds\n\n",difftime(t2,t1));
		}
		else if(a[j] == 'Q'){
			printf("\n��ʼ�ؼ���:");
	        DispSort(T);
		    printf("��������\n\n");
			t1 = time(NULL);
			QuickSort(T,0,n-1);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"��������");
			printf("�����:");
			DispSort(T);
			printf("�����ʱ��Ϊ: %lf\n\n",difftime(t2,t1));
		}
		else if(a[j] == 'B'){
			printf("\n��ʼ�ؼ���:");
	        DispSort(A);
		    printf("ð������\n");
			t1 = time(NULL);
			BubbleSort(A,n);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"ð������");
			printf("�����:");
			DispSort(A);
			printf("�����ʱ��Ϊ: %lf\n\n",difftime(t2,t1));
		}
		else if(a[j] == 'L'){
			printf("\n��ʼ�ؼ���:");
	        DispSort(B);
		    printf("ϣ������\n");
			t1 = time(NULL);
			ShellSort(B,n);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"ϣ������");
			printf("�����:");
			DispSort(B);
			printf("�����ʱ��Ϊ: %lf\n\n",difftime(t2,t1));
		}
		else if(a[j] == 'I'){
			printf("\n��ʼ�ؼ���:");
	        DispSort(P);
		    printf("ֱ�Ӳ�������\n");
			t1 = time(NULL);
			InsertSort(P,n);
			t2 = time(NULL);
			D[j].key = difftime(t2,t1);
			strcpy(D[j].data,"ֱ�Ӳ�������");
			printf("�����:");
			DispSort(P);
			printf("�����ʱ��Ϊ: %lf\n\n",difftime(t2,t1));
		}
		else{
		    printf("���벻�Ϲ���");
		}
	}
	BijiaoTime(D,5);
	printf("\n");
	return 0;
}
