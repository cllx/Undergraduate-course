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
    cout<<"��ѧ�ɼ�:"<<math<<endl<<"Ӣ��ɼ�:"<<eng<<endl;
}
void score:: setscore(int y,int m)
{
    cout<<"������ѧ�ɼ�:";
	cin>>y;
	math = y;
    cout<<"����Ӣ��ɼ�:";
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
    cout<<"��ʦְ��:"<<degree<<endl<<"��ʦѧλ:"<<dep<<endl;
	delete []degree;
	delete []dep;
}
void teacher:: setteacher(char* y,char* m)
{
	y = new char[10];
	m = new char[10];
    cout<<"�����ʦְ��:";
	cin>>y;
	degree = y;
    cout<<"�����ʦѧλ:";
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
	cout<<"����ѧ��ѧ��"<<endl;
	cin>>no;
	sno = no;
    cout<<"����ѧ������"<<endl;
	cin>>na;
	name = na;
}
void student:: showstudent()
{
    cout<<"ѧ��ѧ��"<<sno<<endl<<"ѧ������"<<name<<endl;
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
	cout<<"����ѧ��ͨѶ��ַ"<<endl;
	cin>>ad;
	addr = ad;
    cout<<"����ѧ���绰"<<endl;
	cin>>te;
	tel = te;
}
void stud:: showstud()
{
    cout<<"ѧ��ͨѶ��ַ"<<addr<<endl<<"ѧ���绰"<<tel<<endl;
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
	cout<<"�����˵�����"<<endl;
	cin>>a;
	age = a;
    cout<<"�����˵�ID"<<endl;
	cin>>i;
	ID = i;
}
void person:: showperson()
{
    cout<<"�˵�����"<<age<<endl<<"�˵�ID"<<ID<<endl;
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