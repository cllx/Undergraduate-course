#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class CStudent
{
private:
    int un;        //学号
    char *p_name;      //姓名
    char *p_school;    //院系
    char *p_address;   //通讯地址
    char *tel;         //电话
	char *pn;
	char *ps;
	char *pa;
	char *t;
public:
	CStudent(int un,char *pn,char *ps,char *pa,char *t);
	void show();                                       //输出数据成员
	void setname();                           //设置姓名
	//int setnumber(int number);                          //设置学号
	void setschool();                       //设置院系              
	void setaddress();                     //设置通讯地址
	void settel();                         //设置电话
	int getnumber();                                   //获取学号
	char* getname();                                    //取姓名
	char* getschool();                                  //取学校
	char* getaddress();                                 //取邮编
	char* gettel();                                     //取电话号码
};																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																														
void CStudent:: setname()                     //设置姓名
{
    p_name = new char[strlen(pn)+1];             //申请存储空间
    strcpy(p_name,pn);
}
void CStudent:: setschool()                 //设置学校
{
    p_school = new char[strlen(ps)+1];         //申请存储空间
    strcpy(p_school,ps);
}
void CStudent:: setaddress()               //设置通讯地址
{
    p_address = new char[strlen(pa)+1];       //申请存储空间
    strcpy(p_address,pa);
}
void CStudent:: settel()                   //设置电话
{
    tel = new char[strlen(t)+1];             //申请存储空间
    strcpy(tel,t);
}
int CStudent:: getnumber()
{
    cout<<"修改学号:  ";
	cin>>un;
	return un;
};
char* CStudent:: getname()
{
	pn = new char[];
    cout<<"修改姓名:  ";
	cin>>pn;
	return pn;
	delete []pn;
}
char* CStudent:: getschool()
{
    ps = new char[];
    cout<<"修改学校院系:  ";
	cin>>ps;
	return ps;
	delete []ps;
}
char* CStudent:: getaddress()
{
	pa = new char[50];
    cout<<"修改通讯地址:  ";
	cin>>pa;
	return pa;
	delete []pa;
}
char* CStudent:: gettel()
{
	t = new char[11];
    cout<<"修改电话:  ";
	cin>>t;
	return t;
	delete []t;
}
void CStudent:: show()
{
    cout<<"学生学号:"<<un<<endl;
	cout<<"学生姓名:"<<p_name<<endl;
	cout<<"学生院系:"<<p_school<<endl;
	cout<<"学生通讯地址:"<<p_address<<endl;
	cout<<"学生电话:"<<tel<<endl;
	delete []p_name;
	delete []p_school;
	delete []p_address;
    delete []tel;
}
CStudent:: CStudent(int un,char *pn,char *ps,char *pa,char *t)
{
	cout<<"学生学号:"<<un<<endl;
	cout<<"学生姓名:"<<pn<<endl;
	cout<<"学生院系:"<<ps<<endl;
	cout<<"学生通讯地址:"<<pa<<endl;
	cout<<"学生电话:"<<t<<endl;
}
int main()
{
	int n = 2004005;
	char name[] = "张三",school[] = "工学院算机系",add[] = "四川雅安雨城区新康路49号邮编625014",tel[] = "0123344";
    CStudent stu(n,name,school,add,tel);
	stu.getnumber();
	stu.getname();
	stu.getschool();
	stu.getaddress();
	stu.gettel();
	stu.setname();
	stu.setschool();
	stu.setaddress();
	stu.settel();
	stu.show();
	return 0;
}