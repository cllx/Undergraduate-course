#include <iostream>
using namespace std; 
struct stNode   
{  
    int num;  
    char name[10];  
    stNode *next;
};
void initStLink(int n);                        
void dispStLink(); 
void find();            
stNode *head=NULL;       
stNode *pre;
int main()
{
	int m;
	cout<<"人数=";
	cin>>m;
	initStLink(m);
	dispStLink();
    find();
	return 0;
}

void initStLink(int n)
{
	stNode *r,*s;
	r=head;
    for(int i=1;i<n+1;i++)
	{
	    s = new stNode;
	    cout<<"序号:";
        cin>>s->num;
	    cout<<"姓名:";
	    cin>>s->name;
	    s->next=NULL;
	    if(head!=NULL)
	    {
		    r->next = s;	
	    }
	    else
	    {
	        head=s;
	    }
	    r = s;	   
	}
	s->next = head;
}

void dispStLink( )
{
	stNode *r;
	r = head;
	cout<<endl;
    while(r->next!=head)
	{
	    cout<<"序号:"<<r->num<<endl;
        cout<<"名字:"<<r->name<<endl;
        r = r->next;
	}
    cout<<"序号:"<<r->num<<endl;
    cout<<"名字:"<<r->name<<endl;
}
void find()
{
    int i;
	stNode *r,*s;
	r = head;
    while(r->next!=r)
	{
	    for(i=1;i<4;i++)
		{
		    r = r->next;
		}
		s = r->next;
		r->next = s->next;
		cout<<s->num<<endl;
		free(s);
		r = r->next;
	}
	cout<<"最后剩下的是第"<<r->num<<"个人"<<endl;
	delete []r;
}