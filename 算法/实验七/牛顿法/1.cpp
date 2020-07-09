/*
*20140031 陈小龙
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point{
    float x;
    float y;
}a;
int niudun(struct point a,float eps,int N){
	float fval,x;
	int n = 1;
	while(n <= N){
		x = a.x-a.y/(3*a.x*a.x+1);     //求截点的横坐标
		fval = x*x*x+x-1;
		if(fabs(x-a.x) < fabs(eps) || fval == 0.0){//刚好找到或满足精度要求就停止迭代
            printf("解的横坐标为：%f\n",x);
			printf("解的结果为：%f",fval);
			return n;
		}
		else{
			a.y = fval;         //以截点的横坐标新的切点的横坐标，纵坐标
			a.x = x;
		}
		n++;
	}
	return n;
}
int main(){
	 float eps = 0.01;
	 a.x = 1.0,a.y = 1.0;
	 int N,n;
	 N = 50;
	 n = niudun(a,eps,N);
	 printf("\n迭代次数为：%d",n);
	 return 0;
}
