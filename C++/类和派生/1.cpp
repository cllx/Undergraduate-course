#include <iostream>
using namespace std;
class  CDate
{
    private:
        int year,month,day; //�ֱ����ꡢ�¡���    
		char str1[20];
    public:
        CDate(int y=0, int m=0,int d=0)
		{
		    cout<<"1111"<<endl;
		}
		~CDate()
		{
		    cout<<"4444"<<endl;
		}
        void setDate(int y,int m,int d);
        char* getDate();
};

char* CDate:: getDate()
{
    char t[20];
    _itoa(year,str1,10);        //����任Ϊ�ַ�����ʾ
    strcat(str1,"/");           //�ꡢ�¡���֮����"/"����
    _itoa(month,t,10);          //���±任Ϊ�ַ�����ʾ
    strcat(str1,t);             //���ꡢ���ַ���ƴ��
    strcat(str1,"/");
    _itoa(day,t,10);
    strcat(str1,t);             //���ꡢ�¡���ƴ�ӳ�һ���ַ���
	strcat(str1,"/");
    return str1;
}
void CDate:: setDate(int y,int m,int d)
{
    cout<<"�������"<<endl;
	cin>>y;
	year = y;
    cout<<"�����·�"<<endl;
	cin>>m;
	month = m;
	cout<<"�������"<<endl;
	cin>>d;
	day = d;
}
class CTime
{
    
    private:
		int hour,minute,second;    //ʱ���֡���
		char str2[20];    
    public:
        CTime(int h=0,int m=0, int s=0)
		{
		    cout<<"2222"<<endl;
		}
		~CTime()
		{
		    cout<<"5555"<<endl;
		}
        void setTime(int h,int m, int s);
        char* getTime();
};
char* CTime:: getTime()
{   
    char t[20];
    _itoa(hour,str2,10);        //��Сʱ�任Ϊ�ַ�����ʾ
    strcat(str2,":");           //Сʱ�����ӡ���֮����":"����
    _itoa(minute,t,10);         //���ֱ任Ϊ�ַ�����ʾ
    strcat(str2,t);             //��Сʱ�����ַ���ƴ��
    strcat(str2,":");
    _itoa(second,t,10);
    strcat(str2,t);             //��Сʱ���֡���ƴ�ӳ�һ���ַ���
    return str2;
}
void CTime:: setTime(int h,int m, int s)
{
    cout<<"����Сʱ"<<endl;
	cin>>h;
	hour = h;
    cout<<"�������"<<endl;
	cin>>m;
	minute = m;
	cout<<"��������"<<endl;
	cin>>s;
	second = s;
}
class CDateTime: public CDate, public CTime              //��������
{             
    public:
        //CDateTime():CDate(),CTime(){}
        CDateTime(int y,int m,int d,int h,int min,int s):CDate(y,m,d),CTime(h,min,s)
		{
		    cout<<"6666"<<endl;
		}
		~CDateTime()
		{
			cout<<"7777"<<endl;
		}
        void getDateTime();
        //void getDateTime(int y,int m,int d,int h,int min,int s);
};
void CDateTime:: getDateTime()
{
	char* str3;
    str3 = strcat(getDate(),getTime());
	cout<<str3<<endl;
}
int main()
{
	int y=0,m=0,d=0,h=0,min=0,s=0;
	CDateTime a(0,0,0,0,0,0);	
    a.setDate(y,m,d);
    a.setTime(h,min,s);
    a.getDateTime();
    return 0;
}