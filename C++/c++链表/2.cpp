#include <iostream>
using namespace std; 
struct stNode   
{  
	int num;  
    char name[10];  
    stNode *next;
};

void initStLink(
				int n);       //��ʼ������
void CreateStLink();                    //����ѭ������
//void dispStLink(stNode *p);             //���������Ϣ
void find(stNode *p);                 //����Ϊ5���˳�����
stNode *head;
stNode *pre;

int main()
{
    stNode *p;
	int m;
	cout<<"����=";
	cin>>m;
    CreateStLink();
	initStLink(m);
	//dispStLink(p);
    find(p);
	delete []p;
	return 0;
}

void CreateStLink()
{
    head = new stNode;
    if(head)
	{
	    head->next = NULL;
		pre = head;
		cout<<"ѭ���������ɹ�"<<endl;
	}
	else
	{
	    cout<<"ѭ��������ʧ��"<<endl;
	}
}

void initStLink(int n)
{
	stNode *r,*p;
    cout<<"���:";
    cin>>head->num;
	cout<<"����:";
	cin>>head->name;
	r = head;
    for(int i=1;i<n;i++)
	{
		p = new stNode;
	    cout<<"���:";
        cin>>p->num;
		cout<<"����:";
		cin>>p->name;
		r->next = p;
		r = p;
	}
	p->next = head;
}

/*void dispStLink(stNode *r)
{
	r = head->next;
    while(r!=NULL)
	{
	    cout<<"���:"<<r->num<<endl;
        cout<<"����:"<<r->name<<endl;
        r = r->next;
	}
}*/
void find(stNode *p)
{
    int i;
	stNode *s;
	p = head;
    while(p->next!=NULL)
	{
	    for(i=1;i<4;i++)
		{
		    p = p->next;
		}
		cout<<p->next->num<<endl;
		s = p->next;
		p->next = p->next->next;
		free(s);
		p = p->next;
	}
}