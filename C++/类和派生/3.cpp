#include <iostream>
#include <string>
using namespace std;
class person
{
private:
	string name, id;
public:
	person(string Name=0,string Id=0)
	{
	    name = Name;
		id = Id;
	}
	show();
	show1();
	~person(){};
};
person::show()
{
	cout<<"老师姓名是:"<<name<<endl;
	cout<<"老师id是:"<<id<<endl;
}
person::show1()
{
	cout<<"学生姓名是:"<<name<<endl;
	cout<<"学生id是:"<<id<<endl;
}
class student:public person
{
private:
	int old;
	string sno;
public:
	student(string Name,string Id,int age,string no):person(Name,Id)
	{
	    old = age;
		sno = no;
	}
	show();
	~student(){};
};
student::show()
{
	show1();
	cout<<"学生的年龄是:"<<old<<endl;
	cout<<"学生的学号是:"<<sno<<endl;
}
class teacher:public person
{
private:
	string degree,dep;
public:
	teacher(string name,string id):person(name,id){};
	~teacher(){};
    getmess();
	show();
};
teacher::getmess()
{
    cout<<"输入老师学历:";
    cin>>degree;
	cout<<"输入老师职称:";
	cin>>dep;
}
teacher::show()
{
	person::show();
    cout<<"老师学历是:"<<degree<<endl;
	cout<<"老师职称是:"<<dep<<endl;
}
class stud
{
private:
	string addr,tel;
public:
	stud(string add,string pho)
	{
	     addr = add;
		 tel = pho;
	}
	show();
	~stud(){};
};
stud::show()
{
    cout<<"学生的通讯地址是:"<<addr<<endl;
	cout<<"学生的电话号码是:"<<tel<<endl;
}
class score: public student,private stud
{
private:
	int math,eng;
public:
	score(string Name,string no,int age,string add,string pho):student(Name,no,age,no),stud(add,pho){};
	~score(){};
	getmess();
    show();
};
score::getmess()
{
	cout<<"输入学生的数学成绩:";
	cin>>math;
	cout<<"输入学生的英语成绩:";
	cin>>eng;
}
score::show()
{
	student::show();
	stud::show();
	cout<<"学生的数学成绩是:"<<math<<endl;
	cout<<"学生的英语成绩是:"<<eng<<endl;
}
void main()
{
    teacher t1("李俊","123456");
	t1.getmess();
	t1.show();
	score c1("张磊","20150003",19,"四川雅安四川农业大学","18227592345");
    c1.getmess();
	c1.show();
}