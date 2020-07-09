#include<bits/stdc++.h>
using namespace std;
const int maxn=1007;
int num[maxn];
int main()
{
    int n,a;
    while(cin>>n){
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            num[a]++;
            if(i<n) printf("%d ",num[a]);
            else printf("%d\n",num[a]);
        }
    }
    return 0;
}
