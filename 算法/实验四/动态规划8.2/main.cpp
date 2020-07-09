/*
*20140031 陈小龙
*/
#include<stdio.h>
#include<stdlib.h>
int c[6][7];        //定义状态表
void knapsack(int m,int n)
{
    int i,j,w[6],v[6];    //这里之所以定义物品数组长度为6是为了方便后面写程序而把第0个物品也放进去了
    for(i=1;i<=n;i++){
        printf("\n请输入第%d物品重量和对应价值：",i);
        scanf("\n%d,%d",&w[i],&v[i]);
    }
    for(i=0;i<6;i++)
        for(j=0;j<7;j++)
            c[i][j]=0;     //把物品价值重量表（状态表）全部初始化为0
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(w[i]<=j){   //若当前剩余载重不小于当前物品重量
                if(v[i]+c[i-1][j-w[i]]>c[i-1][j])//状态转移方程
                    c[i][j]=v[i]+c[i-1][j-w[i]]; //若放入当前物品后的总价值大于不放入的情况，那就放入(添加到表中)
                else
                    c[i][j]=c[i-1][j]; //否则就不放入，把不放入放入情况(此时的价值)放入表中
            }
            else c[i][j]=c[i-1][j];    //若当前剩余载重小于当前物品重量，不放入该物品，并把相应价值写入表中
        }
}
int main()
{
   int m,n;
   int i,j;
   printf("陈小龙   20140031   计科2班\n\n");
   printf("请输入箱子重量和物品数：");
   scanf("%d,%d",&m,&n);
   knapsack(m,n);
   printf("\n");
   printf("动态规划的表为：\n");
   for(i=0;i<6;i++)
       for(j=0;j<7;j++){
           printf("%d ",c[i][j]);   //显示表中的信息
           if(j==6)
               printf("\n");        //每行显示剩余载重为0-6的情况
   }
}
