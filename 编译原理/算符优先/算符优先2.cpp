#include <stdio.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#define MAX 100
using namespace std;
char S[MAX];
char shuru[MAX],yu[MAX];
void scanner();
int panyouxian(char x);
void shengyuchuan();
int k;
char youxian[7][7]=
{

	{'>','<','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},

	{'>','>','<','<','<','>','>'},

	{'>','>','>','$','$','>','>'},

	{'<','<','<','<','<','=','$'},

	{'>','>','>','$','$','>','>'},

	{'<','<','<','<','<','$','='},
}; //$Ϊ�ո�

int main()
{
	int l,j;
	cout<<"������һ���ַ���:";
	cin.get(shuru,MAX); //��������ַ����浽����
	k=0;
	S[k]='#';
	S[k+1]='\0';
	l=strlen(shuru); //�������ַ����ĳ���
	for(j=0;j<l;j++)
		yu[j]=shuru[j];
	yu[j]='\0';
	scanner();
	return 0;
}
void scanner() //ɨ��������봮
{
	int i,j,l,h1,l1,h2,l2,h3,l3,y1,y2,r1,r2;
	int step=0;//����������
	char a; //������ڷ������ַ�
	char p1,Q,p2;
	l=strlen(shuru); //������봮����
	for(i=0;i<l;i++)
	{
		a=shuru[i];
		if(S[k]=='+'||S[k]=='*'||S[k]=='^'||S[k]=='i'||S[k]=='('||S[k]==')'||S[k]=='#')
			j=k;
		else
			j=k-1;
		h1=panyouxian(S[j]);// �����ȹ�ϵ���в��S[j]��a�����ȹ�ϵ
		if(a=='+'||a=='*'||a=='^'||a=='i'||a=='('||a==')'||a=='#')
			l1=panyouxian(a);
		else //������Ӻ��в����ս��������������ַ������Ϸ�
		{
			cout<<"����!���Ϸ��ľ���!"<<endl;
			break;
		}
		p1=youxian[h1][l1];
		if(p1=='>')
		{
            loop:
			Q=S[j];
			if(S[j-1]=='+'||S[j-1]=='*'||S[j-1]=='^'||S[j-1]=='i'||S[j-1]=='('||S[j-1]==')'||S[j-1]=='#')
				j=j-1;
			else
				j=j-2;
			h2=panyouxian(S[j]);
			l2=panyouxian(Q);
			p1=youxian[h2][l2];
			if(p1=='<')//S[j+1]��S[k]��ԼΪF
			{
				k=j+1;
				shengyuchuan();
				step++;
				i--;
				S[k]='F';
				r1=strlen(S);
				for(r2=k+1;r2<r2;r2++)
					S[r2]='\0';//����ַ���Լ����ջ�����������
				y1=strlen(yu);
				for(y2=0;y2<y1;y2++)
					yu[y1-y2]=yu[y1-y2-1];
				yu[0]='i';
			}
			else
				goto
				loop;
		}
		else
		{
			if(p1=='<') //�ƽ������һ���ǲ���Լ��ʣ����ַ�������һ��
			{
				shengyuchuan();
				shuru[l]='\0';
				step=step+1;
				k=k+1;
				S[k]=a;
			}
			else
			{
				if(p1=='=')
				{
					h3=panyouxian(S[j]);
					l3=panyouxian('#');
					p2=youxian[h3][l3];
					if(p2=='=')
					{
						shengyuchuan();
						step++;
						cout<<"�Ϸ��ľ���!"<<endl;;
						break;
					}
					else
					{
						k=k+1;
						S[k]=a;
					}
				}
				else
				{
					cout<<"����!"<<endl;
					break;
				}
			}
		}
	}
}

void shengyuchuan()
{
	int i,j;
	i=strlen(yu);
	for(j=0;j<i;j++)
		yu[j]=yu[j+1];
	yu[i-1]='\0';
}
int panyouxian(char x)
{
	int m;
	switch(x)
	{
	case'+':
		m=0;
		break;
	case'*':
		m=1;
		break;
	case'^':
		m=2;
		break;
	case'i':
		m=3;
		break;
	case'(':
		m=4;
		break;
	case')':
		m=5;break;
	case'#':
		m=6;
		break;
	}
	return m;
}
