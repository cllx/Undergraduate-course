#include <iostream>
using namespace std;
#define MAXVEX 50                  //ͼ�����ڵ���
#define MAXIMUN 65535              //����Ϊ�����

typedef struct{                   //�����ڽӾ�������ݽṹ
	char vexs[MAXVEX];
	int edges[MAXVEX][MAXVEX];
	int vexNum, adgeNum;           //�ֱ��ʾͼ�нڵ�����ͱߵ�����
}AGraph;

int main(){
	void createAG(AGraph *);
	void prim(AGraph*);
	AGraph g;
	createAG(&g);
	prim(&g);
	return 0;
}

//Prim�㷨�����С������
void prim(AGraph *g){
	int U[MAXVEX], S[MAXVEX], n =0;     //U����Լ���Ķ���,S���ʣ��Ķ���,�Ѽ���U�еĶ������
	int min = 0;                        //���ڱ�������������Ȩֵ
	for(int i = 0; i < g->vexNum;++i){  //��ͼ�еĶ������S�У�ֻ�洢����ı��.
		S[i] = i;
	}
//������һ��������뼯��U�У�����������0�Ŷ���
	U[0] = 0;
	++n;
//ͬʱ��S��ȥ��0�Ŷ��㣬���︳ֵΪ-1
	S[0] = -1;
	cout<<"\n��С����������Щ�߹��ɣ�\n";
	for(int j = 1; j < g->vexNum; ++j){
		int mintemp = MAXIMUN;
		int indexK, indexP;
//̰�ķ�Ѱ�����ż��붥�㲢��index��¼��λ��
		for(int k = 0; k < n; ++k){
			for(int p = 0; p < g->vexNum; ++p)
			if((S[p] != -1) && (mintemp >g->edges[U[k]][p])){
				indexK = U[k];
				indexP = p;
				mintemp = g->edges[indexK][indexP];
			}
		}
		U[n++] = indexP;                                  //���������U��
		S[indexP] = -1;                                   //���ö����S��ȥ��
		min += mintemp;
		cout<<g->vexs[indexK]<<"->"<<g->vexs[indexP]<<" ";
	}
	cout<<"\n��С����������Ȩ��Ϊ��"<<min<<endl;
}
void createAG(AGraph *g)                                  //����������
{
	int vNum, aNum;                                       //�ֱ����Ҫ������ͼ�Ľڵ����ͱ���
	int start, end;                                       //start->end��ʾ�ڵ�start��end֮����һ����
	int weight;                                           //�ߵ�Ȩ��
	cout<<"������ͼ�нڵ�ĸ����ͱߵ�����:";
	cin>>vNum>>aNum;
	printf("\n������%d���ڵ����Ϣ��", vNum);
//�����ڵ�
	for(int i = 0; i < vNum; ++i){
		cin>>g->vexs[i];
	}
	cout<<"��������ڵ��ż���洢�Ľڵ���Ϣ"<<endl;
	for(int k = 0; k < vNum; ++k)
		cout<<k<<":"<<g->vexs[k]<<"";
	cout<<endl;
//��ʼ������ͼ�ı���Ϣ
	for(int m = 0; m < vNum; ++m)
		for(int n = 0; n < vNum; ++n){
			g->edges[m][n] = MAXIMUN;
		}
//��������ͼ�ı���Ϣ
	for(int j = 0; j < aNum; ++j){
		cout<<"\n�������"<<j+1<<"���ߵ�start��end�ڵ�ͱߵ�Ȩ��weight:";
		cin>>start>>end>>weight;
		g->edges[start][end] = weight;
	    g->edges[end][start] = weight;
	}
//��ʼ��vexNum��adgeNum
	g->vexNum = vNum;
	g->adgeNum = aNum;
}