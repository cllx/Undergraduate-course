/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
int gcd(int dividend,int divisor){
    int com;
	while(divisor!=0){
//每次循环把当前的除数作为下一次的被除数，余数作为除数
	    com=dividend%divisor;
		dividend=divisor;
		divisor=com;
	}
	return dividend;
}
int main(){
    int divisor,dividend,Com_divisor;
	printf("输入被除数:");
	scanf("%d",&dividend);
	printf("输入除数:");
	scanf("%d",&divisor);
	Com_divisor=gcd(dividend,divisor);
	printf("最大公约数为：%d\n",Com_divisor);
	return 0;
}
