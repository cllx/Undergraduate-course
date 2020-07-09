/*
*20140031 陈小龙 计科2班
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
        swap(&array[i],&array[j]);  //直到后面的数大于当前前面的数或者已经遍历到当前的p之前，交换位置
        while(i<j && array[i]<=p)
            i++;
        swap(&array[j],&array[i]);
    }
    Partition(array,l,i-1);         //在已分好的前一部分继续上面的快速排序
    Partition(array,i+1,r);         //在已分好的后一部分继续上面的快速排序
    return array;
}
int main()
{
    int i=0,a[]={12,3,1,43,65,7,9,15,9,10,8,6};
    int *b;
    b=Partition(a,0,11);
    printf("快速排序后的数组为:");
    for(i=0;i<12;i++){
        printf("%d  ",b[i]);
    }
    return 0;
}
