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
	cout<<"��ʦ������:"<<name<<endl;
	cout<<"��ʦid��:"<<id<<endl;
}
person::show1()
{
	cout<<"ѧ��������:"<<name<<endl;
	cout<<"ѧ��id��:"<<id<<endl;
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
	cout<<"ѧ����������:"<<old<<endl;
	cout<<"ѧ����ѧ����:"<<sno<<endl;
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
    cout<<"������ʦѧ��:";
    cin>>degree;
	cout<<"������ʦְ��:";
	cin>>dep;
}
teacher::show()
{
	person::show();
    cout<<"��ʦѧ����:"<<degree<<endl;
	cout<<"��ʦְ����:"<<dep<<endl;
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
    cout<<"ѧ����ͨѶ��ַ��:"<<addr<<endl;
	cout<<"ѧ���ĵ绰������:"<<tel<<endl;
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
	cout<<"����ѧ������ѧ�ɼ�:";
	cin>>math;
	cout<<"����ѧ����Ӣ��ɼ�:";
	cin>>eng;
}
score::show()
{
	student::show();
	stud::show();
	cout<<"ѧ������ѧ�ɼ���:"<<math<<endl;
	cout<<"ѧ����Ӣ��ɼ���:"<<eng<<endl;
}
void main()
{
    teacher t1("�","123456");
	t1.getmess();
	t1.show();
	score c1("����","20150003",19,"�Ĵ��Ű��Ĵ�ũҵ��ѧ","18227592345");
    c1.getmess();
	c1.show();
}