/*
*20140031 ��С�� �ƿ�2��
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x[100];
bool place(int k)     //����ʺ�k������x[k]���Ƿ�����ͻ
{
    int i;
    for(i=1;i<k;i++)
        if(x[k]==x[i]||abs(k-i)==abs(x[k]-x[i]))
            return false;
        return true;
}
void queue(int n)
{
    int i,k;
    for(i=1;i<=n;i++)
        x[i]=0;
    k=1;
    while(k>=1)
    {
        x[k]=x[k]+1;       //����һ�з��õ�k���ʺ�
        while(x[k]<=n&&!place(k))
            x[k]=x[k]+1;   //������һ��
        if(x[k]<=n&&k==n)  //�õ�һ�����
        {
            for(i=1;i<=n;i++)
                printf("%d ",x[i]);
            printf("\n");
            //��return��ֻ�������һ�ֽ⣬����return����Լ������ݣ����ȫ���Ŀ��ܵĽ�
            //return;
        }
        else if(x[k]<=n&&k<n)
            k=k+1;    //������һ���ʺ�
        else
        {
            x[k]=0;   //����x[k],����
            k=k-1;
        }
    }
}

int main()
{
   int n;
   printf("����ʺ����n:");
   scanf("%d",&n);
   queue(n);
   return 0;
}
