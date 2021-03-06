#include <bits/stdc++.h>
using namespace std;
const int maxn=20005; //一直初始化为10001，错误50分 
int vis[maxn];
int ma,s;

//int i; 若程序中i为全局变量，则提交只有50分，原因暂不清楚，将i改成局部变量后，提交，100分
vector <int> G[maxn];
void init()
{
 for(int i=0;i<maxn;i++)
 G[i].clear();
}
void dfs(int u,int cost)
{
 vis[u]=1; //是否通过 
 if(ma<cost)
 {
  ma=cost; //记录最长路径距离 
  s=u;  //记录最长距离的最后一个点 
 }
 for(int i=0;i<G[u].size();i++) //对U的每一个邻接点遍历 
 {
  if(!vis[G[u][i]])  //若该邻接点未标记，则距离加1，继续递归调用 
  dfs(G[u][i],cost+1);
 }
}
int main()
{
 int n,m,x,i;
 cin>>n>>m;
 init();
 for(i=2;i<=n+m;i++)
 {
    cin>>x;
    G[i].push_back(x);
    G[x].push_back(i);
 }
 ma=-1;  //每次调用dfs函数时，首先要对最大值初始化为-1，且vis初始化为0 
 memset(vis,0,sizeof(vis));
 dfs(1,0);
 ma=-1;
 memset(vis,0,sizeof(vis));
 dfs(s,0);
 cout<<ma<<endl;
 return 0;
}
