#include <stdio.h>
#include <algorithm>
using namespace std;
#define OFFSET 500000
int HASH[10000001];
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=-500000;i<=500000;i++){
			HASH[i+OFFSET]=0;
		}
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			HASH[x+OFFSET]++;
		}
		for(int i=500000;i>=-500000;i--){
			if(HASH[i+OFFSET]!=0){
				for(int j=0;j<HASH[i+OFFSET];j++){
					printf("%d",i);
					m--;
					if(m!=0) printf(" ");
					else{
						printf("\n");
						break;
					} 
				}
				if(m==0) break;
			}
		}
	}
	return 0; 
}
