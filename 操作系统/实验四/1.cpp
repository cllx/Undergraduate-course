#include <stdio.h>
int curr[5][5], maxclaim[5][5], avl[5];
int alloc[5] = {0,0,0,0,0};
int maxres[5], running[5], safe=0;
int count = 0, i, j, exec, r, p,k=1;
 
int main()
{
    printf("\n输入进程数 : ");
    scanf("%d",&p);
 
    for(i=0;i<p;i++)
    {
        running[i]=1;
        count++;
    }
 
    printf("\n输入资源数量: ");
    scanf("%d",&r);
 
    for(i=0;i<r;i++)
    { 
        printf("\n输入实例资源 %d: ",k++);
        scanf("%d",&maxres[i]);
    }
 
    printf("\n输入最大资源表:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&maxclaim[i][j]);
        }
    }
 
    printf("\n输入分配的资源表:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&curr[i][j]);
        }
    }
 
    printf("\n实例资源: ");
    for(i=0;i<r;i++)
    {
        printf("\t%d",maxres[i]);
    }
 
    printf("\n分配的资源表:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("\t%d",curr[i][j]);
        }
 
        printf("\n");
    }
 
    printf("\n最大资源表:\n");
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
 
    printf("\n分配的资源:");
    for(i=0;i<r;i++)
    {
        printf("\t%d",alloc[i]);
    }
 
    for(i=0;i<r;i++)
    {
        avl[i]=maxres[i]-alloc[i];
    }
 
    printf("\n可用的资源:");
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
                    printf("\n进程%d 正在执行\n",i+1);
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
            printf("\n进程处于不安全状态.\n");
            break;
        }
        else
        {
            printf("\n这个过程处于安全状态");
            printf("\n安全序列是:");
 
            for(i=0;i<r;i++)
            {
                printf("\t%d",avl[i]);
            }
 
            printf("\n");
        }
    }
}
