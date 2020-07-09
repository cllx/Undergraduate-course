#include <iostream>
#include <iomanip>
using namespace std;

struct Window{
	int x1;
	int y1;
	int x2;
	int y2;
	int id;
};
struct Test{
	int testx;
	int testy;
};

int main(){
	int N,M,i,j;
	int testx,testy;
	cin>>N>>M;
	Window chuang[10];
	Test testxy[10];
	for(i=1;i<=N;i++){
		cin>>chuang[i].x1>>chuang[i].y1>>chuang[i].x2>>chuang[i].y2;
		chuang[i].id = i; 
	}
	for(j=0;j<M;j++){
		cin>>testxy[j].testx>>testxy[j].testy;
	}
	int count;
	for(j=0;j<M;j++){
		for(i=N;i>0;i--){
			if(testxy[j].testx<=chuang[i].x2 && testxy[j].testx>=chuang[i].x1 && testxy[j].testy<=chuang[i].y2 && testxy[j].testy>=chuang[i].y1){
				cout<<chuang[i].id<<endl;
				Window tem = chuang[i];
				for(count=i;count<N;count++)
					chuang[count] = chuang[count+1];
				chuang[N] = tem;
				break;
			}
		}
		if(i==0)
			cout<<"IGNORED"<<endl;
	}
	return 0;
}

