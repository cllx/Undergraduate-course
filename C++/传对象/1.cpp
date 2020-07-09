#include <iostream.h>
#include <string.h>
#include <stdlib.h>
class CStrSub
{   
    char *str;
public:
    CStrSub(char *s);
    CStrSub(const CStrSub&);
    ~ CStrSub();  
    void set(char *s);
    void show()
	{
        cout<<str<<endl;
	}
};
CStrSub:: CStrSub(char *s)
{
    str = new char[strlen(s)+1];
    if(!str)
	{
        cout<<"ÉêÇë¿Õ¼äÊ§°Ü£¡"<<endl;
        exit(-1);
	}
    strcpy(str,s);
}
CStrSub:: CStrSub(const CStrSub &temp)
{
    str = new char[strlen(temp.str)+1];
    if(!str)
	{
        cout<<"ÉêÇë¿Õ¼äÊ§°Ü£¡"<<endl;
        exit(-1);
	}
    strcpy(str,temp.str);
}
CStrSub:: ~ CStrSub()
{
    if(str!=NULL) delete []str;
}
void CStrSub:: set(char *s)
{ 
    delete []str;
    str = new char[strlen(s)+1];
    if(!str)
	{
        cout<<"ÉêÇë¿Õ¼äÊ§°Ü£¡"<<endl;
        exit(-1);
	}
    strcpy(str,s);
}
CStrSub input(CStrSub temp)
{
    char s[20];
    cout<<"ÊäÈë×Ö·û´®£º"<<endl;
    cin>>s;
    temp.set(s);
    return temp;
}
CStrSub input1(CStrSub &temp)
{
    char s[20];
    cout<<"ÊäÈë×Ö·û´®£º"<<endl;
    cin>>s;
    temp.set(s);
    return temp;
}
CStrSub input(CStrSub *temp)
{
    char s[20];
    cout<<"ÊäÈë×Ö·û´®£º"<<endl;
    cin>>s;
    temp->set(s);
    return *temp;
}
void main()
{
    CStrSub a("hello");
    a.show();
    CStrSub b = input(a);
    a.show();
    b.show();
	CStrSub c = input1(a);
    a.show();
    c.show();
    CStrSub d = input(&a);
    a.show();
    d.show();
}