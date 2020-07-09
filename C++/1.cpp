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
	    cout<<"学生链表创建成功!\n";
		head->next = NULL;
		pre = head;
	}
	else 
	{
	    cout<<"非常遗憾，学生链表创建不成功!\n";
	}
}
void headaftercreat(structNode *s,int m)
{
	cin>>m;
	for(int i = 0;i<m;i++)
	{
		s=new structNode;
        cout<<"学号:";
		cin>>s->num;
		cout<<"名字:";
		cin>>s->name;
		cout<<"成绩:";
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
	    cout<<"学号:"<<s->num<<endl;
        cout<<"名字:"<<s->name<<endl;
		cout<<"成绩:"<<s->score<<endl;
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