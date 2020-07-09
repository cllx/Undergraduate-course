/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
int Fib_seq(int n){
    int sum,fn;
    if(n==0 || n==1){
        return 1;
    }
    fn = Fib_seq(n-2)+Fib_seq(n-1);
    return fn;
}
int main()
{
    int n,fn;
    printf("输入数列的大小长度值：");
    scanf("%d",&n);
    fn = Fib_seq(n);
    printf("该斐波拉契数列的和为：%d\n",fn);
    return 0;
}
