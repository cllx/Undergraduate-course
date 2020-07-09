/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int cock,hen,chick,money;
	printf("公鸡  母鸡  小鸡\n");
    for(cock=1;cock<=20;cock++){
		money=100;
		int money1=money-5*cock;  //减去买公鸡的钱
		for(hen=1;hen<=33;hen++){
            int money2=money1;
		    money2=money2-3*hen;  //减去买母鸡的钱
			for(chick=0;chick<=99;chick=chick+3){
			    int money3=money2;
			    money3=money3-chick/3;  //减去买小鸡的钱
				if((cock+hen+chick==100)&&(money3==0)){  //如果鸡的数量为100，剩的钱为0，则刚好
				    printf("%d     %d     %d\n",cock,hen,chick);
				}
			}
		}
	}
	return 0;
}
