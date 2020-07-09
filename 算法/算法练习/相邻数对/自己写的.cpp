#include <iostream>
#include <malloc.h>
using namespace std;
//const int MAXSIZE = 1000;
#define MAXSIZE 1000
int main(){
	int j,i,n,count=0;
	cin>>n;
	int A[MAXSIZE];
	for(i=0;i<n;i++){
		cin>>A[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i]-A[j]==1 || A[i]-A[j]==-1){
				count++;
			}
		}
	}
	cout<<count/2;
	return 0;
}
