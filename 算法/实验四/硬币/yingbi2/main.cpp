/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE   9
int array[] = {1,3,5,MAX_VALUE};
int next[MAX_VALUE] = {0};

void SegNum(int nSum, int* pData, int nDepth)
{
    if(nSum < 0)
        return;
    if(nSum == 0)
    {
        for(int j = 0; j < nDepth; j++){
            printf("%d ",pData[j]);
        }
        printf("\n");
        return;
    }
    int i = (nDepth == 0 ? next[0] : pData[nDepth-1]);
    for(; i <= nSum;)           //当当前的硬币不大于剩下还差待找的钱时
    {
        pData[nDepth++] = i;    //使用该硬币，添加到使用的硬币集中
        SegNum(nSum-i,pData,nDepth);//待找的钱数减去该硬币面值
        nDepth--;               //每一种策略(决策)选择完成输出后，保存的已选硬币记录便删去，用作下一个策略选择记录
        i = next[i];
    }
}
void ShowResult(int array[],int nLen)
{
    next[0] = array[0];
    int i = 0;
    for(; i < nLen-1; i++)
        next[array[i]] = array[i+1];
    next[array[i]] = array[i]+1;
    int pData[MAX_VALUE];
    SegNum(MAX_VALUE,pData,0);
    delete pData;
}
int main()
{
    ShowResult(array,sizeof(array)/sizeof(int));
    return 0;
}
