#include <stdio.h>
int curr[5][5], maxclaim[5][5], avl[5];
int alloc[5] = {0,0,0,0,0};
int maxres[5], running[5], safe=0;
int count = 0, i, j, exec, r, p,k=1;
 
int main()
{
    printf("\n��������� : ");
    scanf("%d",&p);
 
    for(i=0;i<p;i++)
    {
        running[i]=1;
        count++;
    }
 
    printf("\n������Դ����: ");
    scanf("%d",&r);
 
    for(i=0;i<r;i++)
    { 
        printf("\n����ʵ����Դ %d: ",k++);
        scanf("%d",&maxres[i]);
    }
 
    printf("\n���������Դ��:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&maxclaim[i][j]);
        }
    }
 
    printf("\n����������Դ��:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&curr[i][j]);
        }
    }
 
    printf("\nʵ����Դ: ");
    for(i=0;i<r;i++)
    {
        printf("\t%d",maxres[i]);
    }
 
    printf("\n�������Դ��:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("\t%d",curr[i][j]);
        }
 
        printf("\n");
    }
 
    printf("\n�����Դ��:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("\t%d",maxclaim[i][j]);
        }
 
        printf("\n");
    }
 
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            alloc[j]+=curr[i][j];
        }
    }
 
    printf("\n�������Դ:");
    for(i=0;i<r;i++)
    {
        printf("\t%d",alloc[i]);
    }
 
    for(i=0;i<r;i++)
    {
        avl[i]=maxres[i]-alloc[i];
    }
 
    printf("\n���õ���Դ:");
    for(i=0;i<r;i++)
    {
        printf("\t%d",avl[i]);
    }
    printf("\n");
 
    //Main procedure goes below to check for unsafe state.
    while(count!=0)
    {
        safe=0;
        for(i=0;i<p;i++)
        {
            if(running[i])
            {
                exec=1;
                for(j=0;j<r;j++)
                {
                    if(maxclaim[i][j] - curr[i][j] > avl[j]){
                        exec=0;
                        break;
                    }
                }
                if(exec)
                {
                    printf("\n����%d ����ִ��\n",i+1);
                    running[i]=0;
                    count--;
                    safe=1;
 
                    for(j=0;j<r;j++) {
                        avl[j]+=curr[i][j];
                    }
 
                    break;
                }
            }
        }
        if(!safe)
        {
            printf("\n���̴��ڲ���ȫ״̬.\n");
            break;
        }
        else
        {
            printf("\n������̴��ڰ�ȫ״̬");
            printf("\n��ȫ������:");
 
            for(i=0;i<r;i++)
            {
                printf("\t%d",avl[i]);
            }
 
            printf("\n");
        }
    }
}
