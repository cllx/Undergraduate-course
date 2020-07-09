#include <iostream>
using namespace std;
/*
struct menjin{
	int num;
};
*/
int main(){
	int n,i,count[1000]={0},A[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>A[i];
	}
	for(i=0;i<n;i++){
		count[A[i]]++;
		cout<<count[A[i]]<<' ';
	}
	return 0;
}
