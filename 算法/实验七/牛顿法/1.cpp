/*
*20140031 ��С��
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
		x = a.x-a.y/(3*a.x*a.x+1);     //��ص�ĺ�����
		fval = x*x*x+x-1;
		if(fabs(x-a.x) < fabs(eps) || fval == 0.0){//�պ��ҵ������㾫��Ҫ���ֹͣ����
            printf("��ĺ�����Ϊ��%f\n",x);
			printf("��Ľ��Ϊ��%f",fval);
			return n;
		}
		else{
			a.y = fval;         //�Խص�ĺ������µ��е�ĺ����꣬������
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
	 printf("\n��������Ϊ��%d",n);
	 return 0;
}
