#include <iostream>
#include <math.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include <cstdio>
#include <string.h>
#include <stdio.h>
using namespace std;


struct pp{
    string ss;
    double pr;
    long long am;
};
int i,j,n;
int a[5001]={0};
pp p[5001],s[5001],b[5001];
int is=0,ib=0;
double mpr=0,repr=0;
long long mam=0,ream=0;
long long alls=0.00,allb=0.00;
int main(){
    n=1;
    freopen("in.txt","r",stdin);
    while(cin>>p[n].ss){
        if(p[n].ss!="cancel"){
            cin>>p[n].pr>>p[n].am;
            n++;
            a[i]=0;
        }
        else {
            int del;
            cin>>del;
            a[del]=1;
            n++;
        }
    }
    for(i=1;i<n;i++){
        if(a[i]==0){
            if(p[i].ss=="buy"){
                b[ib].ss="buy";
                b[ib].am=p[i].am;
                b[ib].pr=p[i].pr;
                ib++;
            }
            else if(p[i].ss=="sell"){
                s[is].ss="sell";
                s[is].am=p[i].am;
                s[is].pr=p[i].pr;
                is++;
            }
        }
    }
   for(i=0;i<is;i++){
        for(j=i+1;j<is;j++){
            if(s[i].pr>s[j].pr){
                swap(s[i].pr,s[j].pr);
                swap(s[i].am,s[j].am);
            }
        }
    }
    for(i=0;i<ib;i++){
        for(j=i+1;j<ib;j++){
            if(b[i].pr>b[j].pr){
                swap(b[i].pr,b[j].pr);
                swap(b[i].am,b[j].am);
            }
        }
    }
    for(i=0;i<is;i++){
            allb=0.0;
            alls+=s[i].am;
            mpr=s[i].pr;
        for(j=0;j<ib;j++){
             if(b[j].pr>=mpr){
                 allb+=b[j].am;
            }
        }
        mam=min(alls,allb);
        if(mam>ream){
            repr=mpr;
            ream=mam;
        }
    }
    printf("%.2lf %lld\n",repr,ream);
    return 0;
}
