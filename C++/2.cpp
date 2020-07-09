#include <iostream>
using namespace std;

void input(int *p); 
void max_min_value(int *p);
void output(int *p);

int main()
{
    int *p;
    p = new int[10];
	input(p);
    max_min_value(p);
    output(p);
    delete []p;
    return 0;
}

void input(int *p)
{ 
	int i,j=1;
	for(i=0;i<10;i++)
	{
	    cout<<"数组第"<<j+i<<"个元素=";
		cin>>p[i];
	}
}
void max_min_value(int *p)
{
    int max,min,i,tem,j;
	max = p[0];
	min = p[0];
	j = 0;
    for(i=1;i<10;i++)
	{
	    if(max<p[i])
		{
			max=p[i];
			j = i;
		}
		else ;
	}
    tem = p[j];
	p[j] = p[9];
	p[9] = tem;
    j = 0;
	for(i=1;i<10;i++)
	{
	    if(min>p[i])
		{
		    min = p[i];
			j = i;
		}
		else ;
	}
	tem = p[j];
	p[j] = p[0];
	p[0] = tem;
}
void output(int *p)
{
    int i,j=1;
	for(i=0;i<10;i++)
	{
	     cout<<"数组第"<<j+i<<"个元素="<<p[i]<<endl;
	}
}