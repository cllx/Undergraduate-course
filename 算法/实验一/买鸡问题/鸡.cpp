/*
*20140031 ��С�� �ƿ�2��
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int cock,hen,chick,money;
	printf("����  ĸ��  С��\n");
    for(cock=1;cock<=20;cock++){
		money=100;
		int money1=money-5*cock;  //��ȥ�򹫼���Ǯ
		for(hen=1;hen<=33;hen++){
            int money2=money1;
		    money2=money2-3*hen;  //��ȥ��ĸ����Ǯ
			for(chick=0;chick<=99;chick=chick+3){
			    int money3=money2;
			    money3=money3-chick/3;  //��ȥ��С����Ǯ
				if((cock+hen+chick==100)&&(money3==0)){  //�����������Ϊ100��ʣ��ǮΪ0����պ�
				    printf("%d     %d     %d\n",cock,hen,chick);
				}
			}
		}
	}
	return 0;
}
