#include<iostream>
using namespace std;
class CStudent
{
public:
    CStudent()  //ѧ���๹�캯��
	{
        cout<<"constructing student"<<endl;
	}
    ~CStudent() //ѧ������������
	{
        cout<<"denstructing student"<<endl;             
	}
};
class CTeacher
{ 
public:
    CTeacher()   //��ʦ�๹�캯��
	{
        cout<<"constructing teacher"<<endl;
	}
    ~CTeacher()  //��ʦ����������
	{
        cout<<"destructing teacher"<<endl;
	}
};
class CTs
{
    CStudent student;  //ѧ���������ݳ�Ա
    CTeacher teacher;   //��ʦ�������ݳ�Ա
public:
    CTs()  //��ʦѧ���๹�캯��
	{
        cout<<"costructingts"<<endl;
	}
    ~CTs()  //��ʦѧ������������
	{ 
        cout<<"destructing ts"<<endl;
	}
};
int main()
{
    CTs a;
	return 0;
}