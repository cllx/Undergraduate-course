#include <iostream>
using namespace std;
class score
{
    private:
        int math,eng;
    public:
        score()
		{
		    cout<<"1111"<<endl;
		}
		~score()
		{
		    cout<<"2222"<<endl;
		}
        void setscore(int y,int m);
        void showscore();
};
void score:: showscore()
{
    cout<<"数学成绩:"<<math<<endl<<"英语成绩:"<<eng<<endl;
}
void score:: setscore(int y,int m)
{
    cout<<"输入数学成绩:";
	cin>>y;
	math = y;
    cout<<"输入英语成绩:";
	cin>>m;
	eng = m;
}
class teacher
{
    private:
        char *degree,*dep;
    public:
        teacher()
		{
		    cout<<"3333"<<endl;
		}
		~teacher()
		{
		    cout<<"4444"<<endl;
		}
        void setteacher(char* y,char* m);
        void showteacher();
};

void teacher:: showteacher()
{
    cout<<"教师职称:"<<degree<<endl<<"教师学位:"<<dep<<endl;
	delete []degree;
	delete []dep;
}
void teacher:: setteacher(char* y,char* m)
{
	y = new char[10];
	m = new char[10];
    cout<<"输入教师职称:";
	cin>>y;
	degree = y;
    cout<<"输入教师学位:";
	cin>>m;
	dep = m;
}
class student: public score
{
    private:
		int sno;
		char* name;
	public:
        student():score()
		{
		    cout<<"5555"<<endl;
		}
		~student()
		{
		    cout<<"6666"<<endl;
		}
		void setstudent(int no,char* na);
		void showstudent();
};
void student:: setstudent(int no,char* na)
{
	cout<<"输入学生学号"<<endl;
	cin>>no;
	sno = no;
    cout<<"输入学生姓名"<<endl;
	cin>>na;
	name = na;
}
void student:: showstudent()
{
    cout<<"学生学号"<<sno<<endl<<"学生姓名"<<name<<endl;
}
class stud: public score
{
    private:
		char *addr,*tel;
	public:
        stud():score()
		{
		    cout<<"7777"<<endl;
		}
		~stud()
		{
		    cout<<"8888"<<endl;
		}
		void setstud(char* ad,char* te);
		void showstud();
};
void stud:: setstud(char* ad,char* te)
{
	cout<<"输入学生通讯地址"<<endl;
	cin>>ad;
	addr = ad;
    cout<<"输入学生电话"<<endl;
	cin>>te;
	tel = te;
}
void stud:: showstud()
{
    cout<<"学生通讯地址"<<addr<<endl<<"学生电话"<<tel<<endl;
}
class person: public student,public teacher
{
    private:
		char *ID;
		int age;
	public:
        person():student(),teacher()
		{
		    cout<<"9999"<<endl;
		}
		~person()
		{
		    cout<<"0000"<<endl;
		}
		void setperson(int a,char* i);
		void showperson();
};
void person:: setperson(int a,char* i)
{
	cout<<"输入人的年龄"<<endl;
	cin>>a;
	age = a;
    cout<<"输入人的ID"<<endl;
	cin>>i;
	ID = i;
}
void person:: showperson()
{
    cout<<"人的年龄"<<age<<endl<<"人的ID"<<ID<<endl;
}
int main()
{
    score c1;
	teacher t1;
	c1.setscore(0,0);
    c1.showscore();
	t1.setteacher(0,0);
	t1.showteacher();
    return 0;
}