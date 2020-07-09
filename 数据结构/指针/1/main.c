#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1,b=2;
    swap1(&a,&b);
    printf("%d,%d\n",a,b);
    swap2(&a,&b);
    printf("\n\n%d,%d\n",a,b);

    return 0;

}
    int swap1(int *x,int *y){
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
        return 0;
    }
    int swap2(int *x,int *y){
        int *temp;
        temp = x;
        x = y;
        y = temp;
        return 0;
    }
