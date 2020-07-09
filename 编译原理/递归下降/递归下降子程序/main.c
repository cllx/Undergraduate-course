#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SourceMaxLength 10000
void A();
void B();
void E();
void T();
void F();

struct sourceStr{
    char source[SourceMaxLength];
    int pointer;
};
struct sourceStr sour;
char token;
int flag=1;
char getToken()
{
    token=sour.source[sour.pointer];
    return token;
}

void error()
{
    flag=0;
    printf("error;");
}

void E()
{
    token=getToken();
    if(token!='(' && token!='i')
        error();
    else
    {
        T();
        A();
    }
}
void A()
{
    token=getToken();
    if(token!='+' && token!=')' && token!='#')
        error();
    else{
        if(token=='+')
        {
            sour.pointer++;
            T();
            A();
        }
        else{
            ;
        }
    }
}

void B()
{
    token=getToken();
    if(token!='*' && token!='+' && token!=')' && token!='#')
        error();
    else{
        if(token=='*')
        {
            sour.pointer++;
            F();
            B();
        }
        else
            ;
    }
}

void T()
{
    token=getToken();
    if(token!='(' && token!='i')
        error();
    else{
        F();
        B();
    }
}

void F()
{
    token=getToken();
    if(token!='(' && token!='i')
        error();
    else{
        if(token=='(')
        {
            sour.pointer++;
            E();
            token=getToken();
            if(token!=')')
                error();
            else
                sour.pointer++;
        }
        else{
            sour.pointer++;
        }
    }
}

int main()
{
    sour.pointer=0;
    strcpy(sour.source,"i+i*i#");

    E();
    if(flag==1)
    {
        printf("success!");
    }
    else
    {
        printf("error");
    }
    return 0;
}
