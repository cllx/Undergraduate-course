#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

struct point{
    float x;
    float y;
}a,b;

int Bisection(struct point a,struct point b,float eps,int N){
	float x,fval;
	int n;
	while(n <= N){
		x = ((b.y-a.y)*a.x/(b.x-a.x)-a.y)*((b.x-a.x)/(b.y-a.y)); //计算截点的横坐标
		fval = x*x*x+x-1;                                        //计算以改横坐标为x值的方程的y值
		float fa = a.x*a.x*a.x+a.x-1;               //计算根的左边的另一点的纵坐标
		if(fabs(x-a.x) < fabs(eps)){              //满足精度要求则返回
			printf("解的区间为：");
			printf("(%f,%f)\n",a.x,b.x);
			printf("解的结果为：%f",fval);
			return n;
		}
		if(fval == 0.0){
			printf("解的横坐标为：%f",x);
			printf("解的结果为：%f",fval);
			return n;
		}
		if(fval*fa < 0.0){
            a.x = x;                  //如果新的点与左边点异号，则用截点更新左边点
			a.y = fval;
		}
		else{
			b.x = x;             //否则用截点更新右边点
			b.y = fval;
		}
		n++;
	}
	return n;
}

int main(){
	 float eps = 0.01;
	 a.x = 0.0,a.y = -1.0,b.x = 1.0,b.y = 1.0;
	 int N,n;
	 N = 50;
	 n = Bisection(a,b,eps,N);
	 printf("\n迭代次数为：%d",n);
	 return 0;
}
