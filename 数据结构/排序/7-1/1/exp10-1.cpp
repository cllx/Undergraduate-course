//�ļ���:exp10-1.cpp
#include <stdio.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
typedef int KeyType;
typedef char InfoType[10];
typedef struct       	//��¼����
{	
	KeyType key;   		//�ؼ�����
	InfoType data; 		//����������,����ΪInfoType
} RecType;
void InsertSort(RecType R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{
	int i,j,k;
	RecType temp;
	for (i=1;i<n;i++) 
	{
		temp=R[i];
		j=i-1;           	//����������������R[0..i-1]����R[i]�Ĳ���λ��
		while (j>=0 && temp.key<R[j].key) 
		{ 	
			R[j+1]=R[j];	//���ؼ��ִ���R[i].key�ļ�¼����
			j--;
		}
        R[j+1]=temp;			//��j+1������R[i]
		printf("i=%d,",i);		//���ÿһ�˵�������
		printf("����%d,���Ϊ: ",temp);
		for (k=0;k<n;k++)
			printf("%3d",R[k].key);
		printf("\n");
	}
}
void main()
{
	int i,k,n=10;
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	RecType R[MAXE];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("��ʼ�ؼ���: ");		//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%3d",R[k].key);
	printf("\n");
	InsertSort(R,n);
	printf("�����: ");		//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%3d",R[k].key);
	printf("\n");
}
