#include<iostream>
using namespace std;
class CStudent
{
public:
    CStudent()  //学生类构造函数
	{
        cout<<"constructing student"<<endl;
	}
    ~CStudent() //学生类析构函数
	{
        cout<<"denstructing student"<<endl;             
	}
};
class CTeacher
{ 
public:
    CTeacher()   //教师类构造函数
	{
        cout<<"constructing teacher"<<endl;
	}
    ~CTeacher()  //教师类析构函数
	{
        cout<<"destructing teacher"<<endl;
	}
};
class CTs
{
    CStudent student;  //学生对象数据成员
    CTeacher teacher;   //教师对象数据成员
public:
    CTs()  //教师学生类构造函数
	{
        cout<<"costructingts"<<endl;
	}
    ~CTs()  //教师学生类析构函数
	{ 
        cout<<"destructing ts"<<endl;
	}
};
int main()
{
    CTs a;
	return 0;
}