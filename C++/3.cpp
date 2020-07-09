#include <iostream>
using namespace std;
int swap(int &m,int &n);
int change(int m,int n);
void swap(int *m,int *n);
int main()
{
    int a=3,b=5;
	cout<<"a="<<a<<"b="<<b<<endl;
	swap(a,b);
	cout<<"a="<<a<<"b="<<b<<endl;
	swap(&a,&b);
	cout<<"a="<<a<<"b="<<b<<endl;
	change(a,b);
	cout<<"a="<<a<<"b="<<b<<endl;
	return 0;
}
int swap(int &m,int &n)   //引用作为函数参数
{      
	int temp;
    temp=m;
    m=n;
    n=temp;
    return temp;
}
void swap(int *m,int *n)  //指针作为函数参数
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}
int change(int m,int n)   //变量作为函数参数
{      
	int temp;
    temp=m;
    m=n;
    n=temp;
    return temp;
}
