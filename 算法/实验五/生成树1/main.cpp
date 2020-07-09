/*
*20140031 陈小龙 计科2班
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 50                  //图中最大节点数
#define MAXIMUN 65535              //定义为最大数

typedef struct{                   //定义邻接矩阵的数据结构
	char vexs[MAXVEX];
	int edges[MAXVEX][MAXVEX];
	int vexNum, adgeNum;           //分别表示图中节点个数和边的条数
}AGraph;

int main(){
	void createAG(AGraph *);
	void prim(AGraph*);
	AGraph g;
	createAG(&g);
	prim(&g);
	return 0;
}

//Prim算法求解最小生成树
void prim(AGraph *g){
	int U[MAXVEX], S[MAXVEX], n =0;     //U存放以加入的顶点,S存放剩余的顶点,已加入U中的顶点个数
	int j,min = 0;                        //用于保存生成树的总权值
	for(int i = 0; i < g->vexNum;++i){  //将图中的顶点存入S中，只存储顶点的编号.
		S[i] = i;
	}
//将任意一个顶点放入集合U中，这里假设放入0号顶点
	U[0] = 0;
	++n;
//同时从S中去掉0号顶点，这里赋值为-1
	S[0] = -1;
	printf("\n最小生成树由这些边构成：\n");
	for(j = 1; j < g->vexNum; ++j){
		int mintemp = MAXIMUN;
		int indexK, indexP;
//贪心法寻找最优加入顶点并用index记录其位置
		for(int k = 0; k < n; ++k){
			for(int p = 0; p < g->vexNum; ++p)
			if((S[p] != -1) && (mintemp >g->edges[U[k]][p])){
				indexK = U[k];
				indexP = p;
				mintemp = g->edges[indexK][indexP];
			}
		}
		U[n++] = indexP;                                  //将顶点加入U中
		S[indexP] = -1;                                   //将该顶点从S中去掉
		min += mintemp;
		printf("%d->%d ",g->vexs[indexK],g->vexs[indexP]);
	}
	printf("\n最小生成树的总权重为：%d\n",min);
}
void createAG(AGraph *g)                                  //创建无向网
{
	int vNum, aNum;                                       //分别代表要创建的图的节点数和边数
	int start, end;                                       //start->end表示节点start和end之间有一条边
	int weight;                                           //边的权重
	printf("请输入图中节点的个数和边的条数:");
	scanf("%d %d",&vNum,&aNum);
	printf("请输入%d个节点的信息：",vNum);
//创建节点
	for(int i = 0; i < vNum; ++i){
		scanf("%d",&g->vexs[i]);
	}
	printf("这里输出节点编号及其存储的节点信息\n");
	for(int k = 0; k < vNum; ++k){
	    printf("%d:%d ",k,g->vexs[k]);
	}
	printf("\n");
//初始化无向图的边信息
	for(int m = 0; m < vNum; ++m)
		for(int n = 0; n < vNum; ++n){
			g->edges[m][n] = MAXIMUN;
		}
//创建无向图的边信息
	for(int j = 0; j < aNum; ++j){
		printf("\n请输入第%d条边的start和end节点和边的权重weight:",j+1);
		scanf("%d %d %d",&start,&end,&weight);
		g->edges[start][end] = weight;
	    g->edges[end][start] = weight;
	}
//初始化vexNum和adgeNum
	g->vexNum = vNum;
	g->adgeNum = aNum;
}
