#include <stdio.h>
#include <math.h>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;
struct course{
	int score;
	float credit;
};
int main(){
	course mark[59];
	float sum=0,tmp=0;
	for(int i=0;i<59;i++){
		scanf("%d %f",&mark[i].score,&mark[i].credit);
	}
	for(int j=0;j<59;j++){
		sum=sum+mark[j].credit * mark[j].score;
		tmp=tmp+mark[j].credit;
	}
	printf("%f",sum/tmp);
}
