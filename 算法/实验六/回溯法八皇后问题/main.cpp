/*
*20140031 ��С�� �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
#define max 8
int queen[max],sum=0; //maxΪ�����������
void show() //������лʺ������
{
    int i;
    printf("(");
    for(i = 0; i < max; i++)
         printf(" %d", queen[i]);
    printf(")\n");
    sum++;
}
int PLACE(int n) //��鵱ǰ���ܷ���ûʺ�
{
    int i;
    for(i = 0; i < n; i++) //�����źͶԽ������Ƿ���Է��ûʺ�
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
            return 1;
    return 0;
}
void NQUEENS(int n) //���ݳ��Իʺ�λ��,nΪ������
{
    int i;
    for(i = 0; i < max; i++)
    {
        queen[n] = i; //���ʺ�ڵ���ǰѭ������λ��
        if(!PLACE(n))
        {
            if(n == max - 1)
                show(); //���ȫ���ںã���������лʺ������
            else
                NQUEENS(n + 1); //��������ڷ���һ���ʺ�
        }
    }
}
int main()
{
    NQUEENS(0); //�Ӻ�����Ϊ0��ʼ���γ���
    printf("%d", sum);
    system("pause");
    return 0;
}
