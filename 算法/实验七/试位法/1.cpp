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
		x = ((b.y-a.y)*a.x/(b.x-a.x)-a.y)*((b.x-a.x)/(b.y-a.y)); //����ص�ĺ�����
		fval = x*x*x+x-1;                                        //�����Ըĺ�����Ϊxֵ�ķ��̵�yֵ
		float fa = a.x*a.x*a.x+a.x-1;               //���������ߵ���һ���������
		if(fabs(x-a.x) < fabs(eps)){              //���㾫��Ҫ���򷵻�
			printf("�������Ϊ��");
			printf("(%f,%f)\n",a.x,b.x);
			printf("��Ľ��Ϊ��%f",fval);
			return n;
		}
		if(fval == 0.0){
			printf("��ĺ�����Ϊ��%f",x);
			printf("��Ľ��Ϊ��%f",fval);
			return n;
		}
		if(fval*fa < 0.0){
            a.x = x;                  //����µĵ�����ߵ���ţ����ýص������ߵ�
			a.y = fval;
		}
		else{
			b.x = x;             //�����ýص�����ұߵ�
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
	 printf("\n��������Ϊ��%d",n);
	 return 0;
}
