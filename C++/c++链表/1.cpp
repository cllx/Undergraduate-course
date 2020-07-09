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
	cout<<"����=";
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
	    cout<<"���:";
        cin>>s->num;
	    cout<<"����:";
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
	    cout<<"���:"<<r->num<<endl;
        cout<<"����:"<<r->name<<endl;
        r = r->next;
	}
    cout<<"���:"<<r->num<<endl;
    cout<<"����:"<<r->name<<endl;
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
	cout<<"���ʣ�µ��ǵ�"<<r->num<<"����"<<endl;
	delete []r;
}