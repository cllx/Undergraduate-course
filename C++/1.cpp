#include<iostream>
using namespace std;
struct structNode
{
    int num;
	char name[10];
	float score;
	structNode *next;
};
structNode *head;
structNode *pre;
void init()
{
    head = new structNode;
	if(head)
	{
	    cout<<"ѧ���������ɹ�!\n";
		head->next = NULL;
		pre = head;
	}
	else 
	{
	    cout<<"�ǳ��ź���ѧ�����������ɹ�!\n";
	}
}
void headaftercreat(structNode *s,int m)
{
	cin>>m;
	for(int i = 0;i<m;i++)
	{
		s=new structNode;
        cout<<"ѧ��:";
		cin>>s->num;
		cout<<"����:";
		cin>>s->name;
		cout<<"�ɼ�:";
		cin>>s->score;
		s->next=head->next;
		head->next =s;
	}
}
void outlist(structNode *s)
{
    s = head->next;
	while(s!=NULL)
	{
	    cout<<"ѧ��:"<<s->num<<endl;
        cout<<"����:"<<s->name<<endl;
		cout<<"�ɼ�:"<<s->score<<endl;
		s = s->next;
	}	
}
int main()
{
	int m;
	structNode *s;
    init();
    headaftercreat(s,m);
	cout<<endl;
    outlist(s);
	delete[] s;
	s = NULL;
	return 0;
}