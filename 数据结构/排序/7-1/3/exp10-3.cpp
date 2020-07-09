//�ļ���:exp10-3.cpp
#include <stdio.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
typedef int KeyType;
typedef char InfoType[10];
typedef struct       	//��¼����
{	
	KeyType key;   		//�ؼ�����
    InfoType data; 		//����������,����ΪInfoType
} RecType;
void BubbleSort(RecType R[],int n)	//ð�������㷨
{
	int i,j,k;
	RecType temp;
	for (i=0;i<n-1;i++) 
	{	
		for (j=n-1;j>i;j--)	//�Ƚ�,�ҳ�������С�ؼ��ֵļ�¼
			if (R[j].key<R[j-1].key)   
			{	
				temp=R[j];  //R[j]��R[j-1]���н���,����С�ؼ��ּ�¼ǰ��
				R[j]=R[j-1];
				R[j-1]=temp;
			}
		printf("i=%d,ð������С�ؼ���:%d,���Ϊ: ",i,R[i].key);	//���ÿһ�˵�������
		for (k=0;k<n;k++)
			printf("%2d",R[k].key);
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
	printf("��ʼ�ؼ���: ");	//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%2d",R[k].key);
	printf("\n");
	BubbleSort(R,n);
	printf("�����:  ");	//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%2d",R[k].key);
	printf("\n");
}
