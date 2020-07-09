#include<stdio.h>
#include<stdlib.h>
int main(){
	int i, n, x, maxn = -1, max , a[10000];
	scanf("%d",&n);
	for(i=0;i<10000;i++){
		a[i] = 0;
	} 
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	for(i=0;i<10000;i++){
		if(a[i]>maxn){
			maxn = a[i];
			max = i; 
		}
	}
	printf("%d\n",max);
}
