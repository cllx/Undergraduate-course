/*
*20140031 ��С�� �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
int gcd(int dividend,int divisor){
	while(divisor!=0){
		gcd(divisor,dividend%divisor);  //������������0��ʱ��ÿѭ��һ�εݹ���øú���һ��
		dividend=divisor;
		divisor=dividend%divisor;
	}
	return dividend;
}
int main(){
    int divisor,dividend,Com_divisor;
	printf("���뱻����:");
	scanf("%d",&dividend);
	printf("�������:");
	scanf("%d",&divisor);
	Com_divisor=gcd(dividend,divisor);
	printf("���Լ��Ϊ��%d\n",Com_divisor);
	return 0;
}
