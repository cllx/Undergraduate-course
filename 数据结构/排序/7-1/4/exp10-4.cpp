//�ļ���:exp10-4.cpp
#include <stdio.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
typedef int KeyType;
typedef char InfoType[10];
typedef struct			//��¼����
{	
	KeyType key;		//�ؼ�����
    InfoType data; 		//����������,����ΪInfoType
} RecType;
int n;
void QuickSort(RecType R[],int s,int t) //��R[s]��R[t]��Ԫ�ؽ��п�������
{
	int i=s,j=t,k;
	RecType temp;
	if (s<t) 					//���������ٴ���һ��Ԫ�ص����
	{	
		temp=R[s];     			//������ĵ�1����¼��Ϊ��׼
        while (i!=j)  			//���������˽������м�ɨ��,ֱ��i=jΪֹ
		{	
			while (j>i && R[j].key>temp.key) 
			    j--;  			//��������ɨ��,�ҵ�1���ؼ���С��temp.key��R[j]
			R[i]=R[j];
            while (i<j && R[i].key<temp.key) 
			    i++;			//��������ɨ��,�ҵ�1���ؼ��ִ���temp.key�ļ�¼R[i] 
			R[j]=R[i];
		}
		R[i]=temp;
		printf(" ��������ΪR[%d..%d],���Ϊ:",s,t);	//���ÿһ�˵�������
		for (k=0;k<10;k++)
			if (k==i)
				printf(" [%d]",R[k].key);
			else
				printf("%4d",R[k].key);
		printf("\n");
		QuickSort(R,s,i-1);		//��������ݹ�����
		QuickSort(R,i+1,t);		//��������ݹ�����
	}
}
void main()
{
	int i,k;
	n=10;
	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	RecType R[MAXE];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("��ʼ�ؼ���: ");			//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%4d",R[k].key);
	printf("\n");
	QuickSort(R,0,n-1);
	printf("�����:  ");			//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%4d",R[k].key);
	printf("\n");
}
