#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class CStudent
{
private:
    int un;        //ѧ��
    char *p_name;      //����
    char *p_school;    //Ժϵ
    char *p_address;   //ͨѶ��ַ
    char *tel;         //�绰
	char *pn;
	char *ps;
	char *pa;
	char *t;
public:
	CStudent(int un,char *pn,char *ps,char *pa,char *t);
	void show();                                       //������ݳ�Ա
	void setname();                           //��������
	//int setnumber(int number);                          //����ѧ��
	void setschool();                       //����Ժϵ              
	void setaddress();                     //����ͨѶ��ַ
	void settel();                         //���õ绰
	int getnumber();                                   //��ȡѧ��
	char* getname();                                    //ȡ����
	char* getschool();                                  //ȡѧУ
	char* getaddress();                                 //ȡ�ʱ�
	char* gettel();                                     //ȡ�绰����
};																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																														
void CStudent:: setname()                     //��������
{
    p_name = new char[strlen(pn)+1];             //����洢�ռ�
    strcpy(p_name,pn);
}
void CStudent:: setschool()                 //����ѧУ
{
    p_school = new char[strlen(ps)+1];         //����洢�ռ�
    strcpy(p_school,ps);
}
void CStudent:: setaddress()               //����ͨѶ��ַ
{
    p_address = new char[strlen(pa)+1];       //����洢�ռ�
    strcpy(p_address,pa);
}
void CStudent:: settel()                   //���õ绰
{
    tel = new char[strlen(t)+1];             //����洢�ռ�
    strcpy(tel,t);
}
int CStudent:: getnumber()
{
    cout<<"�޸�ѧ��:  ";
	cin>>un;
	return un;
};
char* CStudent:: getname()
{
	pn = new char[];
    cout<<"�޸�����:  ";
	cin>>pn;
	return pn;
	delete []pn;
}
char* CStudent:: getschool()
{
    ps = new char[];
    cout<<"�޸�ѧУԺϵ:  ";
	cin>>ps;
	return ps;
	delete []ps;
}
char* CStudent:: getaddress()
{
	pa = new char[50];
    cout<<"�޸�ͨѶ��ַ:  ";
	cin>>pa;
	return pa;
	delete []pa;
}
char* CStudent:: gettel()
{
	t = new char[11];
    cout<<"�޸ĵ绰:  ";
	cin>>t;
	return t;
	delete []t;
}
void CStudent:: show()
{
    cout<<"ѧ��ѧ��:"<<un<<endl;
	cout<<"ѧ������:"<<p_name<<endl;
	cout<<"ѧ��Ժϵ:"<<p_school<<endl;
	cout<<"ѧ��ͨѶ��ַ:"<<p_address<<endl;
	cout<<"ѧ���绰:"<<tel<<endl;
	delete []p_name;
	delete []p_school;
	delete []p_address;
    delete []tel;
}
CStudent:: CStudent(int un,char *pn,char *ps,char *pa,char *t)
{
	cout<<"ѧ��ѧ��:"<<un<<endl;
	cout<<"ѧ������:"<<pn<<endl;
	cout<<"ѧ��Ժϵ:"<<ps<<endl;
	cout<<"ѧ��ͨѶ��ַ:"<<pa<<endl;
	cout<<"ѧ���绰:"<<t<<endl;
}
int main()
{
	int n = 2004005;
	char name[] = "����",school[] = "��ѧԺ���ϵ",add[] = "�Ĵ��Ű�������¿�·49���ʱ�625014",tel[] = "0123344";
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