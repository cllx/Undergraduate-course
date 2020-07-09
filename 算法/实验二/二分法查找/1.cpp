/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
int ersearch(int array[],int n,int k){
    int low=0,high=n-1,m;
	while(low<=high){
	    m=(low+high)/2;//每次从当前的低位和高位的中间查找
		if(k==array[m])//如果查找到就结束返回
			return m;
		else if(k>array[m])
			low=m+1;   //要查找的值大于当前的中间值，当前中间的下一位为低位
		else
			high=m-1;  //要查找的值小于当前的中间值，当前中间的上一位为低位
	}
	return -1;
}
int main(){
	int k,index,length=10;
	int array[]={1,2,3,4,5,6,7,8,9,10};
	printf("输入要查找的数:");
	scanf("%d",&k);
	index=ersearch(array,length,k);
	if(index!=-1)
	    printf("\n要查找的数的下标是%d\n",index);
	else
		printf("\n要查找的数不在数组内");
}
