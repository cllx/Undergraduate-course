#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
void getstring(char *string,char *file){
    FILE *fp;
    int i=0;
    if((fp=fopen(file,"r"))==NULL){
        printf("Can't open %s\n",file);
    }else{
        while(!feof(fp)){
            string[i]=fgetc(fp);
            i++;
        }
        //fgets(string,15,fp);
    }
}
int getInt(char *string,int *Ascstring){
    int i;
    for(i=0;i<strlen(string)-1;i++){
        Ascstring[i]=string[i];
    }
    return i;
}
void initable(int *AscToInt,int *rule,int ruleresult[2][3]){
    int j,i;
    for(j=0;j<95;j++){
        AscToInt[j]=j+32;
    }
    for(j=0;j<95;j++){
        if((j>32 && j<59) || (j>64 && j<91)){
            rule[j]=1;//表示是字母
        }else if(j>15 && j<26){
            rule[j]=2;//表示是数字
        }else{
            rule[j]=0;//表示字母数字都不是
        }
    }
    for(j=0;j<3;j++){
        for(i=0;i<2;i++){
            if(i==0 && j==0){
                ruleresult[i][j]=0;
            }else if(i==1 && j==0){
                ruleresult[i][j]=0;
            }else if(i==0 && j==1){
                ruleresult[i][j]=1;
            }else if(i==1 && j==1){
                ruleresult[i][j]=1;
            }else if(i==0 && j==2){
                ruleresult[i][j]=0;
            }else if(i==1 && j==2){
                ruleresult[i][j]=1;
            }
        }
    }
}
int judgestring(int *Ascstring,int *AscToInt,int *rule,int *ruleresult[2][3],int length){
    int flag=0,i=0,tmp,j;
    for(i;i<length;i++){
        for(j=0;j<95;j++){
            if(AscToInt[j]==Ascstring[i]) break;
        }
        tmp=rule[j];
        if(ruleresult[flag][tmp]==0){
            flag=0;
            break;
        }else{
            flag=1;
        }
        i++;
    }
    return flag;
}
int main()
{
    char myfile[20];
    char string[MAX];
    int AscString[MAX],j,AscToInt[MAX],rule[MAX],ruleresult[2][3],flag=0;
    printf("Enter the file name:");
    scanf("%s",myfile);
    getstring(string,myfile);
    int i=0;
    while(string[i]!=NULL){
        printf("%c",string[i]);
        i++;
    }
    j=getInt(string,AscString);
    for(i=0;i<j;i++){
        printf("%d\n",AscString[i]);
    }
    initable(AscToInt,rule,ruleresult);
    flag=judgestring(AscString,AscToInt,rule,ruleresult,j);
    if(flag==1){
        printf("输入的字符串符合规则");
    }else{
        printf("输入的字符串不符合规则");
    }
    return 0;
}
