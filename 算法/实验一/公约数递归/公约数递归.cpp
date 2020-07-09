/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
int gcd(int dividend,int divisor){
	while(divisor!=0){
		gcd(divisor,dividend%divisor);  //当余数不等于0的时候，每循环一次递归调用该函数一次
		dividend=divisor;
		divisor=dividend%divisor;
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
