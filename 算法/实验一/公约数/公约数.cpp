/*
*20140031 ��С�� �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
int gcd(int dividend,int divisor){
    int com;
	while(divisor!=0){
//ÿ��ѭ���ѵ�ǰ�ĳ�����Ϊ��һ�εı�������������Ϊ����
	    com=dividend%divisor;
		dividend=divisor;
		divisor=com;
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
