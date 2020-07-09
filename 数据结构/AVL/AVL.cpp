#include <iostream>
#include <malloc.h>
#include <stack>

using namespace std;

typedef struct TreeNode
{
    int height;
    int data;
    TreeNode* leftC;
    TreeNode* rightC;
}TreeNode;

int getHeight(TreeNode* s)
{
    if (s != NULL)
    {
        return s->height;
    }
    return -1;
}

void InitTree(TreeNode** list)
{
    *list = (TreeNode*)malloc(sizeof(TreeNode));
    (*list)->height = 0;
    (*list)->leftC = NULL;
    (*list)->rightC = NULL;
}



void leftRotate(TreeNode*& root)//����
{
    TreeNode *l1 = root;
    TreeNode *l2 = root->leftC;
    l1->leftC = l2->rightC;
    l2->rightC = l1;
    l1->height = (getHeight(l1->leftC) > getHeight(l1->rightC) ? getHeight(l1->leftC) : getHeight(l1->rightC)) + 1;
    l2->height = (getHeight(l2->leftC) > getHeight(l2->rightC) ? getHeight(l2->leftC) : getHeight(l2->rightC)) + 1;
    root = l2;
}

void rightRotate(TreeNode*& root)//����
{
    TreeNode *l1 = root;
    TreeNode *l2 = root->rightC;
    l1->rightC = l2->leftC;
    l2->leftC = l1;
    l1->height = getHeight(l1);
    l2->height = getHeight(l2);
    root = l2;
}

///���ң���������������
void DoubleRotateLR(TreeNode* &n1)
{
    rightRotate(n1->leftC);
    leftRotate(n1);
}

//������������������
void DoubleRotateRL(TreeNode* &n1)
{
    leftRotate(n1->rightC);
    rightRotate(n1);
}


void Insert(TreeNode*& node, int data)
{
    if (node == NULL)
    {
        TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
        tmp->data = data;
        tmp->height = 0;
        tmp->leftC = NULL;
        tmp->rightC = NULL;
        node = tmp;
        return;
    }
    if (node->data >= data)//����ֵ����data
    {
        Insert(node->leftC, data);//���ϲ���

        if ((getHeight(node->leftC) - getHeight(node->rightC)) == 2)
        {//˵����Ҫ����
            if (data < node->leftC->data)
            {
                leftRotate(node);
            }
            else
            {
                DoubleRotateLR(node);
            }
        }
        else if (node->data < data)//û����ͬ��ֵ
        {
            Insert(node->rightC, data);
            //����߶�֮��Ϊ2�Ļ���ʧȥ��ƽ��,��Ҫ��ת
            if (2 == getHeight(node->rightC) - getHeight(node->leftC))
            {
                if (data > node->rightC->data)
                {
                    rightRotate(node);
                }
                else
                {
                    DoubleRotateRL(node);
                }
            }
        }
    }
    node->height = (getHeight(node->leftC) > getHeight(node->rightC) ? getHeight(node->leftC) : getHeight(node->rightC)) + 1;
}

void preOrder(TreeNode* node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << endl;
    preOrder(node->leftC);
    preOrder(node->rightC);
}

void  inOrderTraversal(TreeNode* root)//�ǵݹ��������
{//�������У�����ң�����ÿ������Ҳ��һ����˳��
    stack<TreeNode *> S;
    while (true)
    {
        if (root)
        {
            S.push(root);
            root = root->leftC;
        }
        else
        {
            if (S.empty())
            {
                break;
            }
            root = S.top();
            cout << root->data << " ";
            S.pop();
            root = root->rightC;
        }
    }
}

void deleteNode(TreeNode* &node, int x)
{
    if (node == NULL) return; //û���ҵ�ֵ��x�Ľڵ�

    if (x < node->data)
    {
        //���xС�ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
        deleteNode(node->leftC, x);
        if (2 == getHeight(node->rightC) - getHeight(node->leftC))
        {
            if (node->rightC->leftC && getHeight(node->rightC->leftC) > getHeight(node->rightC->rightC))
                DoubleRotateRL(node);
            else
                rightRotate(node);
        }
    }
    else if (x > node->data)
    {
        //���x���ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
        deleteNode(node->rightC, x);
        if (2 == getHeight(node->leftC) > getHeight(node->rightC))
        {
            if (node->leftC ->rightC && getHeight(node->leftC->rightC) > getHeight(node->leftC->leftC))
                DoubleRotateLR(node);
            else
                leftRotate(node);
        }
    }
    else //������,�˽ڵ����Ҫɾ���Ľڵ�
    {
        if (node->leftC && node->rightC) //�˽ڵ�����������
        {
            TreeNode* ptr = node->rightC; //ptrָ��ڵ���Ҷ���

            while (ptr->leftC != NULL) ptr = ptr->leftC;//�ҵ���������ֵ��С�Ľڵ�
                                                      //������������С�ڵ��ֵ��ֵ�����ڵ�
            node->data = ptr->data;
            //ɾ������������Сֵ�Ľڵ�
            deleteNode(node->rightC, ptr->data);
            if (2 == getHeight(node->leftC) - getHeight(node->rightC))
            {
                if (node->leftC->rightC && getHeight(node->leftC->rightC) > getHeight(node->leftC->leftC))
                    DoubleRotateLR(node);
                else
                    leftRotate(node);
            }
        }
        else
        {
            TreeNode* ptr = node;
            //�˽ڵ���1����0������
            if (node->leftC == NULL) //���Ҷ��ӻ���û�ж���
                node = node->rightC;
            else if (node->rightC == NULL) //�������
                node = node->leftC;

            delete ptr;
            ptr = NULL;
        }
    }

    if (node)
        node->height = (getHeight(node->leftC) > getHeight(node->rightC) ? getHeight(node->leftC) : getHeight(node->rightC)) + 1;
}

int main()
{
    TreeNode *head;
    InitTree(&head);
    int A[] = {45,53,32,74,90,40,31,43,38,56,17,79,24,57,54,2,97,70,20,72,43,79,12,35,45,76,13,10,98,33,0,90,1,40,8,72,24,24,13,81,20,36,45,30,69,48,27,14,23,48,38,54,40,6,36,49,70,43,96,83,59,37,84,15,29,86,92,62,60,39,61,19,19,22,39,58,67,31,82,94,74,22,96,13,98,77,83,40,81,83,55,71,65,12,70,85,83,21,71,2}; 
    for (int i = 0; i < 100; i++)
    {
        Insert((*head).leftC, A[i]);
    }
    //preOrder((*head).leftC);
    inOrderTraversal((*head).leftC);
    cout << endl;
    //deleteNode((*head).leftC, 1);
    //inOrderTraversal((*head).leftC);
    cout << endl;
    //Insert((*head).leftC, 1);
    //deleteNode((*head).leftC, 4);
    //inOrderTraversal((*head).leftC);
    cout << endl;
    //preOrder((*head).leftC);

    return 0;
}

