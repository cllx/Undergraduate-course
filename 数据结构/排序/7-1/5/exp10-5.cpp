//�ļ���:exp10-5.cpp
#include <stdio.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
typedef int KeyType;
typedef char InfoType[10];
typedef struct       	//��¼����
{	
	KeyType key;   		//�ؼ�����
    InfoType data; 		//����������,����ΪInfoType
} RecType;
void SelectSort(RecType R[],int n)	//ֱ��ѡ�������㷨
{
	int i,j,k,l;
	RecType temp;
	for (i=0;i<n-1;i++)    	 	//����i������
	{	
		k=i;
		for (j=i+1;j<n;j++)  	//�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k] 
			if (R[j].key<R[k].key)
				k=j;           	//k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
		if (k!=i)          		//����R[i]��R[k] 
		{	
			temp=R[i];R[i]=R[k];R[k]=temp;  
		}
		printf(" i=%d,ѡ��Ĺؼ���:%d,���Ϊ:",i,R[i].key);
		for (l=0;l<n;l++)		//���ÿһ�˵�������
			printf("%2d",R[l].key);
		printf("\n");
	}
}
void main()
{
	int i,k,n=10,m=5;
	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	RecType R[MAXE];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("��ʼ�ؼ���:");			//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%2d",R[k].key);
	printf("\n");
	SelectSort(R,n);
	printf("�����:");			//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%2d",R[k].key);
	printf("\n");
}
