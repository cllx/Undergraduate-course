//�ļ���:exp10-2.cpp
#include <stdio.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
typedef int KeyType;
typedef char InfoType[10];
typedef struct       	//��¼����
{
	KeyType key;		//�ؼ�����
	InfoType data;		//����������,����ΪInfoType
} RecType;
void ShellSort(RecType R[],int n)	//ϣ�������㷨
{
	int i,j,d,k;
	RecType temp;
	d=n/2;					//dȡ��ֵn/2
	while (d>0) 
	{	
		for (i=d;i<n;i++)	//��R[d..n-1]�ֱ������鵱ǰ��������
		{	
			j=i-d;
			while (j>=0 && R[j].key>R[j+d].key) 
			{	
				temp=R[j];      //R[j]��R[j+d]����
				R[j]=R[j+d];
				R[j+d]=temp;
				j=j-d;
			}
		}
		printf("d=%d: ",d);	//���ÿһ�˵�������
		for (k=0;k<n;k++)
			printf("%3d",R[k].key);
		printf("\n");
        d=d/2;               //�ݼ�����d
	}
}
void main()
{
	int i,k,n=10;
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	RecType R[MAXE];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("��ʼ�ؼ���: ");			//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%3d",R[k].key);
	printf("\n");
	ShellSort(R,n);
	printf("�����: ");			//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%3d",R[k].key);
	printf("\n\n");
}
