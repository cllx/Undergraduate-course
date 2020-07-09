/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
void move(int n,int x,int y,int z){
    if(n==1)
        printf("%c-->%c\n",x,z);
    else{
        move(n-1,x,z,y);    //将前n-1个盘子移到中间塔上
        printf("%c-->%c\n",x,z);  //将最后一个盘移到目的塔上
        move(n-1,y,x,z);    //将前n个盘移到目的塔上
    }
}
int main()
{
    int h;
    printf("输入盘子数:");
    scanf("%d",&h);
    printf("移动%2d个盘子的步骤:\n",h);
    move(h,'a','b','c');
    return 0;
}
