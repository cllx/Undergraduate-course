/*
*20140031 ��С�� �ƿ�2��
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
    printf("�������еĴ�С����ֵ��");
    scanf("%d",&n);
    fn = Fib_seq(n);
    printf("��쳲��������еĺ�Ϊ��%d\n",fn);
    return 0;
}
