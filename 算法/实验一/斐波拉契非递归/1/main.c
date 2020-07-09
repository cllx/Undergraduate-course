/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
int Fib_seq(int n){
    int sum=1,i,sum1=1,sum2=1;
    if(n==0 || n==1)
        return 1;
    for(i=1;i<n;i++){
        sum = sum+sum1;      //每一个值等于其前两个值的和
        sum1 = sum2;         //每循环一次更新的前两个值
        sum2 = sum;
    }
    return sum;
}
int main()
{
    int n,sum;
    printf("输入数列下标：");
    scanf("%d",&n);
    sum = Fib_seq(n);
    printf("该斐波拉契数列第%d个的值：%d\n",n+1,sum);
    return 0;
}
