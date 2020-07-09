#include <iostream>
using namespace std;
class  CDate
{
    private:
        int year,month,day; //分别存放年、月、日    
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
    _itoa(year,str1,10);        //将年变换为字符串表示
    strcat(str1,"/");           //年、月、日之间用"/"隔开
    _itoa(month,t,10);          //将月变换为字符串表示
    strcat(str1,t);             //将年、月字符串拼接
    strcat(str1,"/");
    _itoa(day,t,10);
    strcat(str1,t);             //将年、月、日拼接成一个字符串
	strcat(str1,"/");
    return str1;
}
void CDate:: setDate(int y,int m,int d)
{
    cout<<"输入年份"<<endl;
	cin>>y;
	year = y;
    cout<<"输入月份"<<endl;
	cin>>m;
	month = m;
	cout<<"输入号数"<<endl;
	cin>>d;
	day = d;
}
class CTime
{
    
    private:
		int hour,minute,second;    //时、分、秒
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
    _itoa(hour,str2,10);        //将小时变换为字符串表示
    strcat(str2,":");           //小时、分钟、秒之间用":"隔开
    _itoa(minute,t,10);         //将分变换为字符串表示
    strcat(str2,t);             //将小时、分字符串拼接
    strcat(str2,":");
    _itoa(second,t,10);
    strcat(str2,t);             //将小时、分、秒拼接成一个字符串
    return str2;
}
void CTime:: setTime(int h,int m, int s)
{
    cout<<"输入小时"<<endl;
	cin>>h;
	hour = h;
    cout<<"输入分钟"<<endl;
	cin>>m;
	minute = m;
	cout<<"输入秒数"<<endl;
	cin>>s;
	second = s;
}
class CDateTime: public CDate, public CTime              //公有派生
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