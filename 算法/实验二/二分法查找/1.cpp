/*
*20140031 ��С�� �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
int ersearch(int array[],int n,int k){
    int low=0,high=n-1,m;
	while(low<=high){
	    m=(low+high)/2;//ÿ�δӵ�ǰ�ĵ�λ�͸�λ���м����
		if(k==array[m])//������ҵ��ͽ�������
			return m;
		else if(k>array[m])
			low=m+1;   //Ҫ���ҵ�ֵ���ڵ�ǰ���м�ֵ����ǰ�м����һλΪ��λ
		else
			high=m-1;  //Ҫ���ҵ�ֵС�ڵ�ǰ���м�ֵ����ǰ�м����һλΪ��λ
	}
	return -1;
}
int main(){
	int k,index,length=10;
	int array[]={1,2,3,4,5,6,7,8,9,10};
	printf("����Ҫ���ҵ���:");
	scanf("%d",&k);
	index=ersearch(array,length,k);
	if(index!=-1)
	    printf("\nҪ���ҵ������±���%d\n",index);
	else
		printf("\nҪ���ҵ�������������");
}
