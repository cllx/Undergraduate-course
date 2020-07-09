/*
*20140031 陈小龙 计科2班
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std ;

class TreeNode//定义一个最小生成树类
{
public:
    int m_firstNode;
    int m_lastNode ;
    int m_Value ;
    TreeNode (int firstNode= 0, int lastNode = 0, int Value = 0)
        {
            m_firstNode=firstNode;
            m_lastNode =lastNode;
            m_Value =Value;
        }
};

class Prim //定义一个Prim算法的类
{
private:
    vector<vector<int> > m_nvvalues ; //无向连通图
    vector<TreeNode> MinTree ;    //最小生成树
    int NodeCount; //无相连通图的结点数
public:
    Prim (const vector<vector<int> >& vnvalues)
    {
        m_nvvalues = vnvalues ;
        NodeCount = (int)m_nvvalues.size () ;
    }
    void DoPrim ()
    {
        // 是否被访问标志
        vector<bool> bFlag (NodeCount, false) ;
        bFlag[0]=true ;
        int firstNode ;
        int lastNode;
        int k=0 ;
        while(k<NodeCount-1)
        {
            //voctor<int>的最大值,也是默认值
            int nMaxWeight=numeric_limits<int>::max () ;
            // 找到当前最短路径
            int i = 0 ;
            while (i<NodeCount)
            {
                if(!bFlag[i])
                {
                    ++ i ;
                    continue ;
                }
                for (int j = 0; j < NodeCount; ++ j)
                {
                    if (!bFlag[j] && nMaxWeight > m_nvvalues[i][j])
                    {
                        nMaxWeight = m_nvvalues[i][j] ;
                        firstNode = i ;
                        lastNode = j ;
                    }
                }
                ++ i ;
            }
            bFlag[lastNode] = true ;
            MinTree.push_back (TreeNode(firstNode, lastNode, nMaxWeight)) ;
            ++k ;
        }
        // 输出结果
        for (vector<TreeNode>::const_iterator ite = MinTree.begin() ;
                ite != MinTree.end() ;
                ++ ite )
        {
            cout << (*ite).m_firstNode+1 << "->"
                 << (*ite).m_lastNode+1<< " : "
                 << (*ite).m_Value << endl ;
        }
    }
} ;

int main()
{
    const int NodeCount=6 ;//定义结点个数
    vector<vector<int> > values(NodeCount);//定义一个二维容器用来存储连通图
    for(size_t i=0;i<values.size();++i)//重定义容器的大小
    {
        values[i].resize(NodeCount,numeric_limits<int>::max()) ;
    }
    //将连通图中的权值赋值
    values[0][1] = 6 ;
    values[0][2] = 1 ;
    values[0][3] = 5 ;
    values[1][0] = 6 ;
    values[1][2] = 5 ;
    values[1][4] = 3 ;
    values[2][0] = 1 ;
    values[2][1] = 5 ;
    values[2][3] = 5 ;
    values[2][4] = 6 ;
    values[2][5] = 4 ;
    values[3][0] = 5 ;
    values[3][2] = 5 ;
    values[3][5] = 2 ;
    values[4][1] = 3 ;
    values[4][2] = 6 ;
    values[4][5] = 6 ;
    values[5][2] = 4 ;
    values[5][3] = 2 ;
    values[5][4] = 6 ;
//定义一个prim类的对象
    Prim prim1(values) ;
//使用prim类的DoPrim方法实现Prim算法
    prim1.DoPrim () ;
    return 0 ;
}
