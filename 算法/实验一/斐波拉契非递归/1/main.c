/*
*20140031 ��С�� �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
int Fib_seq(int n){
    int sum=1,i,sum1=1,sum2=1;
    if(n==0 || n==1)
        return 1;
    for(i=1;i<n;i++){
        sum = sum+sum1;      //ÿһ��ֵ������ǰ����ֵ�ĺ�
        sum1 = sum2;         //ÿѭ��һ�θ��µ�ǰ����ֵ
        sum2 = sum;
    }
    return sum;
}
int main()
{
    int n,sum;
    printf("���������±꣺");
    scanf("%d",&n);
    sum = Fib_seq(n);
    printf("��쳲��������е�%d����ֵ��%d\n",n+1,sum);
    return 0;
}
