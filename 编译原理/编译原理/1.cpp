#include<stdio.h>
int GetSum(int i,int j){
    int sum = 0;
    if(i > j){
	    return sum;
	}
	else{
	    sum = GetSum(i+1,j) + i;
	}
    return sum;
}

int Fibonacci(int n){
    int sum = 0;
	if(sum > 100){
		printf("%d",sum);
		return sum;
	}
	else{
		if(n == 1 || n ==2){
			return 1;
		}else{
		    sum = Fibonacci(n-1) + Fibonacci(n-2);
			return sum;
		}
	}
}
 
void main(){
    int i = 24,j = 78,int S = 0,n = 40;
	printf("递归求和的值为:%d\n",GetSum(i,j));
	for(int k = 24;k < 79;k++){
	    S = S + k;
	}
	printf("循环求和的值为:%d\n",S);

	i = 0;j = 1;
	printf("斐波纳契数列为:");
	for(i = 0;i < n;i++){
	    printf("%d  ",Fibonacci(i+1));
	}	
}	