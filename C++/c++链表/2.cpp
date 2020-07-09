#include <iostream>
using namespace std; 
struct stNode   
{  
	int num;  
    char name[10];  
    stNode *next;
};

void initStLink(
				int n);       //初始化链表
void CreateStLink();                    //创建循环链表
//void dispStLink(stNode *p);             //输出链表信息
void find(stNode *p);                 //报数为5的人出队列
stNode *head;
stNode *pre;

int main()
{
    stNode *p;
	int m;
	cout<<"人数=";
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
		cout<<"循环链表创建成功"<<endl;
	}
	else
	{
	    cout<<"循环链表创建失败"<<endl;
	}
}

void initStLink(int n)
{
	stNode *r,*p;
    cout<<"序号:";
    cin>>head->num;
	cout<<"姓名:";
	cin>>head->name;
	r = head;
    for(int i=1;i<n;i++)
	{
		p = new stNode;
	    cout<<"序号:";
        cin>>p->num;
		cout<<"姓名:";
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
	    cout<<"序号:"<<r->num<<endl;
        cout<<"名字:"<<r->name<<endl;
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