#include<iostream>
#include<string>
using namespace std;
#define MAX 100
struct Split{
    char string2[MAX];
};
Split* Pk(char *A,int *B,int *C){
    Split cut[MAX];
	char *p = A;
	int i,j,m=0,n=0,k=0,flag1=0,flag2=0,flag3=0;
	while(*p!=NULL){
		for(j=0;j<6;j++){
			if(*p == C[j]){
				if(flag3==1){
				    n++;
				}
				cut[n].string2[k] = *p;
				cout<<"["<<n<<"]"<<"["<<k<<"]";
			    cout<<cut[n].string2[k]<<endl;
				n++;
                m=0;
			    p++;
				flag1=1;
				break;
			}
		}
		for(i=0;i<3;i++){
			if(*p == B[i]){
				n++;
				m=0;
				p++;
				flag2=1;
				break;
			}
		}
		flag3=0;
		if(flag1 == 0 && flag2 == 0){
			cut[n].string2[m] = *p;
			cout<<"["<<n<<"]"<<"["<<m<<"]";
			cout<<cut[n].string2[m]<<endl;
			m++;
			p++;
			flag3=1;
		}
		flag1 = 0; flag2 = 0;
	}
	return cut;
}
int main(){
	Split *Coll;
	int i,j;
	int Split_1[] = {32,10,9};
	int Split_2[] = {44,59,123,125,40,41};
	char *string1 = "main (){int i,j,k23,mab;}";
	Coll = Pk(string1,Split_1,Split_2);
	for(i=0;i<14;i++){
		for(j=0;j<4;j++){
			if(Coll[i].string2[j]!=NULL){
			    cout<<Coll[i].string2[j];
			}
		}
		cout<<endl;
	}
    return 0;
}
