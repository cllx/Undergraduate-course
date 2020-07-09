/*
*20140031 ��С�� �ƿ�2��
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std ;

class TreeNode//����һ����С��������
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

class Prim //����һ��Prim�㷨����
{
private:
    vector<vector<int> > m_nvvalues ; //������ͨͼ
    vector<TreeNode> MinTree ;    //��С������
    int NodeCount; //������ͨͼ�Ľ����
public:
    Prim (const vector<vector<int> >& vnvalues)
    {
        m_nvvalues = vnvalues ;
        NodeCount = (int)m_nvvalues.size () ;
    }
    void DoPrim ()
    {
        // �Ƿ񱻷��ʱ�־
        vector<bool> bFlag (NodeCount, false) ;
        bFlag[0]=true ;
        int firstNode ;
        int lastNode;
        int k=0 ;
        while(k<NodeCount-1)
        {
            //voctor<int>�����ֵ,Ҳ��Ĭ��ֵ
            int nMaxWeight=numeric_limits<int>::max () ;
            // �ҵ���ǰ���·��
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
        // ������
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
    const int NodeCount=6 ;//���������
    vector<vector<int> > values(NodeCount);//����һ����ά���������洢��ͨͼ
    for(size_t i=0;i<values.size();++i)//�ض��������Ĵ�С
    {
        values[i].resize(NodeCount,numeric_limits<int>::max()) ;
    }
    //����ͨͼ�е�Ȩֵ��ֵ
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
//����һ��prim��Ķ���
    Prim prim1(values) ;
//ʹ��prim���DoPrim����ʵ��Prim�㷨
    prim1.DoPrim () ;
    return 0 ;
}
