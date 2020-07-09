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



void leftRotate(TreeNode*& root)//左左
{
    TreeNode *l1 = root;
    TreeNode *l2 = root->leftC;
    l1->leftC = l2->rightC;
    l2->rightC = l1;
    l1->height = (getHeight(l1->leftC) > getHeight(l1->rightC) ? getHeight(l1->leftC) : getHeight(l1->rightC)) + 1;
    l2->height = (getHeight(l2->leftC) > getHeight(l2->rightC) ? getHeight(l2->leftC) : getHeight(l2->rightC)) + 1;
    root = l2;
}

void rightRotate(TreeNode*& root)//右右
{
    TreeNode *l1 = root;
    TreeNode *l2 = root->rightC;
    l1->rightC = l2->leftC;
    l2->leftC = l1;
    l1->height = getHeight(l1);
    l2->height = getHeight(l2);
    root = l2;
}

///左右，先右旋，再左旋
void DoubleRotateLR(TreeNode* &n1)
{
    rightRotate(n1->leftC);
    leftRotate(n1);
}

//右左，先左旋，后右旋
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
    if (node->data >= data)//结点的值大于data
    {
        Insert(node->leftC, data);//不断插入

        if ((getHeight(node->leftC) - getHeight(node->rightC)) == 2)
        {//说明需要左旋
            if (data < node->leftC->data)
            {
                leftRotate(node);
            }
            else
            {
                DoubleRotateLR(node);
            }
        }
        else if (node->data < data)//没有相同的值
        {
            Insert(node->rightC, data);
            //如果高度之差为2的话就失去了平衡,需要旋转
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

void  inOrderTraversal(TreeNode* root)//非递归中序遍历
{//先左，再中，最后右，对于每个子树也是一样的顺序
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
    if (node == NULL) return; //没有找到值是x的节点

    if (x < node->data)
    {
        //如果x小于节点的值,就继续在节点的左子树中删除x
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
        //如果x大于节点的值,就继续在节点的右子树中删除x
        deleteNode(node->rightC, x);
        if (2 == getHeight(node->leftC) > getHeight(node->rightC))
        {
            if (node->leftC ->rightC && getHeight(node->leftC->rightC) > getHeight(node->leftC->leftC))
                DoubleRotateLR(node);
            else
                leftRotate(node);
        }
    }
    else //如果相等,此节点就是要删除的节点
    {
        if (node->leftC && node->rightC) //此节点有两个儿子
        {
            TreeNode* ptr = node->rightC; //ptr指向节点的右儿子

            while (ptr->leftC != NULL) ptr = ptr->leftC;//找到右子树中值最小的节点
                                                      //把右子树中最小节点的值赋值给本节点
            node->data = ptr->data;
            //删除右子树中最小值的节点
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
            //此节点有1个或0个儿子
            if (node->leftC == NULL) //有右儿子或者没有儿子
                node = node->rightC;
            else if (node->rightC == NULL) //有左儿子
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

