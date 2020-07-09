/*
*20140031 ��С�� �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
int swap(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int *Partition(int *array,int l,int r){
    if(l>=r)
        return array;
    int p=array[l],i=l,j=r;
    while(i<j){
        while(i<j && array[j]>=p)
            j--;
        swap(&array[i],&array[j]);  //ֱ������������ڵ�ǰǰ����������Ѿ���������ǰ��p֮ǰ������λ��
        while(i<j && array[i]<=p)
            i++;
        swap(&array[j],&array[i]);
    }
    Partition(array,l,i-1);         //���ѷֺõ�ǰһ���ּ�������Ŀ�������
    Partition(array,i+1,r);         //���ѷֺõĺ�һ���ּ�������Ŀ�������
    return array;
}
int main()
{
    int i=0,a[]={12,3,1,43,65,7,9,15,9,10,8,6};
    int *b;
    b=Partition(a,0,11);
    printf("��������������Ϊ:");
    for(i=0;i<12;i++){
        printf("%d  ",b[i]);
    }
    return 0;
}
