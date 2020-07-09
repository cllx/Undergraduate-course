/*
*20140031   ��С��   �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int Bisection(float a,float b,float eps,int N){
	float x,fval;
	int n;
	while(n <= N){
		x = (a + b)/2;           //�����м��
		fval = x*x*x+x-1;        //�����Ӧyֵ
		float fa;
		fa = a*a*a+a-1;          //������ߵ��yֵ
		if(fabs(x-a) < fabs(eps)){    //������㾫��Ҫ���򷵻�
			printf("�������Ϊ��");
			printf("(%f,%f)\n",a,x);
			printf("��Ľ��Ϊ��%f",fval);
			return n;
		}
		if(fval == 0.0){           //����պõ��ڣ��򷵻�
			printf("��Ϊ��%f",x);
			printf("��Ľ��Ϊ��%f",fval);
			return n;
		}
		if(fval*fa < 0.0)          //����м������ߵ���ţ������м������ұߵĵ�
			b = x;
		else
			a = x;                 //���������ߵĵ�
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
	 printf("\n��������Ϊ��%d",n);
	 return 0;
}
