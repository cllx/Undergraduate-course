/*
*20140031 ��С�� �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
void move(int n,int x,int y,int z){
    if(n==1)
        printf("%c-->%c\n",x,z);
    else{
        move(n-1,x,z,y);    //��ǰn-1�������Ƶ��м�����
        printf("%c-->%c\n",x,z);  //�����һ�����Ƶ�Ŀ������
        move(n-1,y,x,z);    //��ǰn�����Ƶ�Ŀ������
    }
}
int main()
{
    int h;
    printf("����������:");
    scanf("%d",&h);
    printf("�ƶ�%2d�����ӵĲ���:\n",h);
    move(h,'a','b','c');
    return 0;
}
