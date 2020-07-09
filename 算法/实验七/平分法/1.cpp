/*
*20140031   陈小龙   计科2班
*/
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int Bisection(float a,float b,float eps,int N){
	float x,fval;
	int n;
	while(n <= N){
		x = (a + b)/2;           //计算中间点
		fval = x*x*x+x-1;        //计算对应y值
		float fa;
		fa = a*a*a+a-1;          //计算左边点的y值
		if(fabs(x-a) < fabs(eps)){    //如果满足精度要求，则返回
			printf("解的区间为：");
			printf("(%f,%f)\n",a,x);
			printf("解的结果为：%f",fval);
			return n;
		}
		if(fval == 0.0){           //如果刚好等于，则返回
			printf("解为：%f",x);
			printf("解的结果为：%f",fval);
			return n;
		}
		if(fval*fa < 0.0)          //如果中间点与左边点异号，则以中间点更新右边的点
			b = x;
		else
			a = x;                 //否则更新左边的点
		n++;
	}
	return n;
}

int main(){
	 float a = 0.0,b = 1.0,eps = 0.01,i;
	 int N,n;
	 i = (b-a)/eps;
	 //N = log(i)/log(2)+1;
	 //printf("N=%d",N);
	 N = 50;
	 n = Bisection(a,b,eps,N);
	 printf("\n迭代次数为：%d",n);
	 return 0;
}
