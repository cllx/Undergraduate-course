#include<STRING.H>
#include<stdio.h>
#include<stdlib.h>
#include<CONIO.H>/*�õ���getch()*/
#define M 5 /*������*/
#define N 3 /*��Դ��*/
#define FALSE 0
#define TRUE 1 /*M�����̶�N����Դ�����Դ������*/
int MAX[M][N]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};/*ϵͳ������Դ��*/
int AVAILABLE[N]={10,5,7};/*M�������ѷ��䵽��N������*/
int ALLOCATION[M][N]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};/*M�������Ѿ��õ�N����Դ����Դ��*/
int NEED[M][N]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};/*M�����̻���ҪN����Դ����Դ��*/
int Request[N]={0,0,0};
void main(){
	int i=0,j=0;
	char flag;
	void showdata();
	void changdata(int);
	void rstordata(int);
	int chkerr();
	showdata();
	enter:
	{ 
		printf("��������������Դ�Ľ��̺ţ���0��");
		printf("%d",M-1);
		printf("��:");
		scanf("%d",&i);
	}
	if(i<0||i>=M)
	{
		printf("����Ľ��̺Ų����ڣ���������!\n");
		goto enter;
	}
	err:
	{
		printf("���������");
		printf("%d",i);
		printf("�������Դ��\n");
		printf("���:ABC\n");
		printf("");
		for(j=0;j<N;j++)
		{
			scanf("%d",&Request[j]);
			if(Request[j]>NEED[i][j])
			{
				printf("%d",i);
				printf("�Ž���");
				printf("�������Դ��>����");
				printf("%d",i);
				printf("����Ҫ");
				printf("%d",j);
				printf("����Դ����Դ��!���벻��������!������ѡ��!\n");
				goto err;
			}
			else
			{
				if(Request[j]>AVAILABLE[j])
				{
					printf("����");
					printf("%d",i);
					printf("�������Դ������ϵͳ����");
					printf("%d",j);
					printf("����Դ����Դ��!���벻��������!������ѡ��!\n");
					goto err;
				}
			}
		}
	}
	changdata(i);
	if(chkerr())
	{
		rstordata(i);
		showdata();
	}else
		showdata();
	printf("\n");
	printf("��'y'��'Y'������,�����˳�\n");
	flag=getch();
	if(flag=='y'||flag=='Y')
	{
		goto enter;
	}else
	{
		 exit(0);
	}
}/*��ʾ����*/
void showdata()
{
	int i,j;
	printf("ϵͳ������Դ����:\n");
	printf("***Available***\n");
	printf("��Դ���:ABC\n");
	printf("��Դ��Ŀ:");
	for(j=0;j<N;j++)
	{
		printf("%d",AVAILABLE[j]);
	}
	printf("\n");
	printf("\n");
	printf("�����̻���Ҫ����Դ��:\n");
	printf("******Need******\n");
	printf("��Դ���:ABC\n");
	for(i=0;i<M;i++)
	{
		printf("");
		printf("%d",i);
		printf("�Ž���:");
		for(j=0;j<N;j++)
		{
			printf("%d",NEED[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("�������Ѿ��õ�����Դ��:\n");
	printf("***Allocation***\n");
	printf("��Դ���:ABC\n");
	for(i=0;i<M;i++){printf("");
		printf("%d",i);
	printf("�Ž���:");/*printf(":\n");*/
	for(j=0;j<N;j++)
	{
		printf("%d",ALLOCATION[i][j]);
	}
	printf("\n");
}
printf("\n");}/*ϵͳ�Խ���������Ӧ����Դ�����ı�*/
void changdata(int k){
	int j;
	for(j=0;j<N;j++)
	{
		AVAILABLE[j]=AVAILABLE[j]-Request[j];
		ALLOCATION[k][j]=ALLOCATION[k][j]+Request[j];
		NEED[k][j]=NEED[k][j]-Request[j];
	}
}/*��Դ�����ı�*/
void rstordata(int k)
{
	int j;
	for(j=0;j<N;j++)
	{
		AVAILABLE[j]=AVAILABLE[j]+Request[j];
		ALLOCATION[k][j]=ALLOCATION[k][j]-Request[j];
		NEED[k][j]=NEED[k][j]+Request[j];
	}
}/*��ȫ�Լ�麯��*/
int chkerr()//�ڼٶ�������Դ������¼��ϵͳ�İ�ȫ��
{
	int WORK[N],FINISH[M],temp[M];//temp[]������¼���̰�ȫִ�е�˳��
	int i,j,m,k=0,count;
	for(i=0;i<M;i++)
	FINISH[i]=FALSE;
	for(j=0;j<N;j++)
	WORK[j]=AVAILABLE[j];//�ѿ�������Դ������WORK[]
	for(i=0;i<M;i++)
	{
		count=0;
		for(j=0;j<N;j++)
		if(FINISH[i]==FALSE && NEED[i][j]<=WORK[j])
			count++;
		if(count==N)//�����̸�����Դ������NEED<=WORKʱ
		{
			for(m=0;m<N;m++)
			WORK[m]=WORK[m]+ALLOCATION[i][m];
			FINISH[i]=TRUE;
			temp[k]=i;//��¼�����������Ľ���
			k++;i=-1;
		}
	}
	for(i=0;i<M;i++)
		if(FINISH[i]==FALSE)
		{
			printf("ϵͳ����ȫ!!!������Դ���벻�ɹ�!!!\n");
			return 1;
		}
	printf("\n");
	printf("����ȫ�Լ�飬ϵͳ��ȫ�����η���ɹ���\n");
	printf("\n");
	printf("���ΰ�ȫ���У�");
	for(i=0;i<M;i++)//��ӡ��ȫϵͳ�Ľ��̵���˳��
	{
		printf("����");
		printf("%d",temp[i]);
		if(i<M-1)
			printf("->");
	}
	printf("\n");
	return 0;
}