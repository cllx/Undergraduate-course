//
///*	
//
//*	平衡二叉树(AVL):由于在极端情况下(左斜树和右斜树)
//
//*	二叉搜索树(BST)查找时间效率大大降低到O(n)，故需要
//
//*	对其进行平衡，平衡的方法有很多种，如AVL，红黑树等，
//
//*	此处通过平衡因子的方法使用AVL树来达到平衡的目的。
//
//*
//
//*	2015.12.06
//
//*	By Snow Yong
//
//*
//
//*/
//
// 
//
// 
//
//#define LH -1		//LH,EH,RH表示平衡因子值
//
//#define EH 0
//
//#define RH 1
//
//#include <stdio.h>
//
//#include <stdlib.h>
//
// 
//
//typedef struct Anode{
//
//	int data;
//
//	int bf;//即当前节点的左子树高度减去右子树高度的差
//
//	struct Anode *lchild, *rchild;
//
//}Anode, *AVLTree;/*AVL树结构，在二叉树基础上加了一个bf平衡因子*/
//
// 
//
// 
//
//int InsertAVL(AVLTree *T, int key, int *taller);
//
//int LeftBalance(AVLTree *T);
//
//int RightBalance(AVLTree *T);
//
//void LeftRotate(AVLTree *T);
//
//void RightRotate(AVLTree *T);
//
//int DeleteAVL(AVLTree *T, int key, int *lower);
//
//int Delete(AVLTree *p);
//
//int SearchAVL(AVLTree T, int key, AVLTree f, AVLTree *p);
//
//void InOrderView(AVLTree T);
//
// 
//
// 
//
// 
//
////AVL树插入关键字操作,*taller用来记录插入节点后树是否有长高
//
//int InsertAVL(AVLTree *T, int key, int *taller)
//
//{
//
//	if (!(*T))
//
//	{//若AVL树是空树，则直接分配节点内存存入关键字，树长高
//
//		(*T) = (AVLTree)malloc(sizeof(Anode));
//
//		(*T)->data = key;
//
//		(*T)->lchild = (*T)->rchild = NULL;
//
//		(*taller) = 1;
//
//		return 1;
//
//	}
//
//	else
//
//	{//若AVL非空树
//
//		if (key == (*T)->data)
//
//		{//如果找到当前节点的值等于欲插入的关键字，则说明已存在该关键字，不再重复插入，树没长高
//
//			(*taller) = 0;
//
//			return 0;
//
//		}
//
//		else if (key < (*T)->data)
//
//		{//若欲插入的关键字小于当前节点值，则在当前节点的左子树递归看是否插入该节点
//
//			if (!InsertAVL(&(*T)->lchild, key, taller))
//
//			{//插入失败
//
//				return 0;
//
//			}
//
//			if (*taller)
//
//			{//若插入成功，则*taller必然等于1，此时只要根据当前节点的平衡因子来调整树达到平衡
//
//				switch ((*T)->bf)
//
//				{						//插入节点在当前节点的左子树的某处
//
//					case LH:			//如果原来左子树高度就比右子树高1
//
//						LeftBalance(T); //就调用左平衡函数
//
//						(*taller) = 0;  //平衡过后，树相对于原来的树并无长高，故设置(*taller) = 0
//
//						break;
//
//					case EH:			//如果原来左子树跟右子树等高
//
//						(*T)->bf = LH;	//则当前节点的平衡因子就改为LH(左边高1)
//
//						(*taller) = 1;	//相比原树，树长高
//
//						break;
//
//					case RH:			//如果原来右子树高度就比左子树高1
//
//						(*T)->bf = EH;	//则在左子树插入关键字节点后，当前节点平衡因子变为EH(左右等高)
//
//						(*taller) = 0;	//相比原树，树并未长高
//
//						break;
//
//				}
//
//			}
//
//		}
//
//		else
//
//		{//若欲插入的关键字大于当前节点值，则在当前节点的右子树递归看是否插入该节点
//
//		 //以下代码道理同上，只不过是在右子树上做文章，不再赘述
//
//			if (!InsertAVL(&(*T)->rchild, key, taller))
//
//			{
//
//				return 0;
//
//			}
//
//			if (*taller)
//
//			{
//
//				switch ((*T)->bf)
//
//				{
//
//					case LH:
//
//						(*T)->bf = EH;
//
//						(*taller) = 0;
//
//						break;
//
//					case EH:
//
//						(*T)->bf = RH;
//
//						(*taller) = 1;
//
//						break;
//
//					case RH:
//
//						RightBalance(T);
//
//						(*taller) = 0;
//
//						break;
//
//				}
//
//			}
//
//		}
//
//		
//
//		return 1;
//
//	}
//
//}
//
// 
//
// 
//
////左平衡函数，调用此函数说明当前节点的子树已然左边不平衡
//
//int LeftBalance(AVLTree *T)
//
//{//此函数包含了左平衡的两种情况：1.根节点单右旋		2.根节点左孩子左旋然后根节点右旋
//
//	AVLTree L, Lr;
//
//	L = (*T)->lchild;		//当前树根节点的左孩子
//
//	
//
//	switch (L->bf)
//
//	{
//
//		case LH:			//若L左子树高，则直接根节点单右旋，并修正根节点与其左孩子的平衡因子值
//
//			(*T)->bf = L->bf = EH;		//这两句代码不可调换
//
//			RightRotate(T);				//因为右旋转函数会改变原来的T值(即当前树根节点发生变化)
//
//			break;
//
//		case RH:
//
//			Lr = L->rchild;	//若L右子树高，则根据L的右孩子Lr的平衡因子值来修正根节点T与L的平衡因子值
//
//			
//
//			switch(Lr->bf)
//
//			{//分情况修改平衡因子值，请自行画辅助图理解
//
//				case LH:	
//
//					(*T)->bf = RH;
//
//					L->bf = EH;
//
//					break;
//
//				case EH:
//
//					(*T)->bf = L->bf = EH;
//
//					break;
//
//				case RH:
//
//					(*T)->bf = EH;
//
//					L->bf = LH;
//
//					break;
//
//			}
//
//			Lr->bf = EH;	//平衡完后L的右孩子平衡因子修正为EH，因左右等高
//
//			
//
//			LeftRotate(&(*T)->lchild);		//先对根节点T的左孩子进行左旋
//
//			RightRotate(T);					//再对根节点T进行右旋
//
//			break;
//
//	}
//
//}
//
// 
//
////右平衡函数，道理同上，代码差别如同对称成像，不再赘述，自行阅读
//
//int RightBalance(AVLTree *T)
//
//{
//
//	AVLTree R, Rl;
//
//	R = (*T)->rchild;
//
//	
//
//	switch (R->bf)
//
//	{
//
//		case LH:
//
//			Rl = R->lchild;
//
//			
//
//			switch(Rl->bf)
//
//			{
//
//				case LH:
//
//					(*T)->bf = EH;
//
//					R->bf = RH;
//
//					break;
//
//				case EH:
//
//					(*T)->bf = R->bf = EH;
//
//					break;
//
//				case RH:
//
//					(*T)->bf = LH;
//
//					R->bf = EH;
//
//					break;
//
//			}
//
//			Rl->bf = EH;
//
//			
//
//			RightRotate(&(*T)->rchild);
//
//			LeftRotate(T);
//
//			break;
//
//		case RH:
//
//			(*T)->bf = R->bf = EH;
//
//			LeftRotate(T);
//
//			break;
//
//	}
//
//}
//
// 
//
// 
//
////左旋函数
//
//void LeftRotate(AVLTree *T)
//
//{
//
//	AVLTree R;			
//
//	R = (*T)->rchild;				//取当前树根节点的右孩子
//
//	(*T)->rchild = R->lchild;		//将右孩子R的左孩子作为当前节点*T的右孩子
//
//	R->lchild = (*T);				//将*T作为R的左孩子
//
//	(*T) = R;						//将当前节点的右孩子R作为新的树根节点
//
//}
//
// 
//
////右旋函数
//
//void RightRotate(AVLTree *T)
//
//{//与左旋函数操作相反，不再赘述
//
//	AVLTree L;
//
//	L = (*T)->lchild;
//
//	(*T)->lchild = L->rchild;
//
//	L->rchild = (*T);
//
//	(*T) = L;
//
//}
//
// 
//
// 
//
////AVL树删除关键字操作,*lower用来记录插入节点后树是否有变矮
//
//int DeleteAVL(AVLTree *T, int key, int *lower)
//
//{
//
//	if (!(*T))
//
//	{//若当前树为空树，则删除失败返回0
//
//		return 0;
//
//	}
//
//	else
//
//	{
//
//		if (key == (*T)->data)
//
//		{						//若当前节点等于欲删除关键字
//
//			Delete(T);			//则调用删除函数
//
//			(*lower) = 1;		//树变矮
//
//			return 1;
//
//		}
//
//		else if (key < (*T)->data)
//
//		{//若欲删除关键字小于当前节点值
//
//			if (!DeleteAVL(&(*T)->lchild, key, lower))
//
//			{//如果左子树也找不到等于此关键字的节点值，删除失败
//
//				return 0;
//
//			}
//
//			
//
//			if (*lower)
//
//			{//若删除成功，则*lower必然等于1，此时只要根据当前节点的平衡因子来调整树达到平衡
//
//				switch ((*T)->bf)
//
//				{								//删除的节点在当前节点的左子树的某处
//
//					case LH:					//如果原来左子树高度就比右子树高1
//
//						(*T)->bf = EH;			//则删除后，两边等高，故(*T)->bf = EH
//
//						(*lower) = 1;			//相比原树，树变矮
//
//						break;
//
//					case EH:					//如果原来左子树与右子树等高
//
//						(*T)->bf = RH;			//则删除后右子树比较高
//
//						(*lower) = 0;			//左边树变矮，右边不变，但总体树高没变矮
//
//						break;
//
//					case RH:					//如果原来右子树高度就比左子树高1
//
//						RightBalance(T);		//则删除后，右子树比左子树高2，故需要调用右平衡函数
//
//						(*lower) = 1;			//调整过后，相比原树，树变矮
//
//						break;
//
//				}
//
//			}
//
//		}
//
//		else
//
//		{//若欲删除关键字大于当前节点值，道理同上，不再赘述
//
//			if (!DeleteAVL(&(*T)->rchild, key, lower))
//
//			{
//
//				return 0;
//
//			}
//
//			
//
//			if (*lower)
//
//			{
//
//				switch ((*T)->bf)
//
//				{
//
//					case LH:
//
//						LeftBalance(T);
//
//						(*lower) = 1;
//
//						break;
//
//					case EH:
//
//						(*T)->bf = LH;
//
//						(*lower) = 0;
//
//						break;
//
//					case RH:
//
//						(*T)->bf = EH;
//
//						(*lower) = 1;
//
//						break;
//
//				}
//
//			}
//
//		}
//
//		return 1;
//
//	}
//
//}
//
// 
//
// 
//
////AVL树删除节点以及后续结构调整函数
//
//int Delete(AVLTree *p)
//
//{//*p为当前要删除的树根节点，为了满足二叉搜索树的性质，分情况讨论
//
//	AVLTree q, s;//定义两个节点指针，q是s的父节点
//
//	
//
//	if ((*p)->rchild == NULL)
//
//	{							//如果当前欲删除节点没有右子树(孩子)
//
//		q = (*p);				//则直接将当前节点的左孩子作为新的树根节点
//
//		(*p) = (*p)->lchild;	
//
//		free(q);				//释放节点占用内存
//
//	}
//
//	else if ((*p)->lchild == NULL)
//
//	{							//道理同上
//
//		q = (*p);
//
//		(*p) = (*p)->rchild;
//
//		free(q);
//
//	}
//
//	else
//
//	{//若当前欲删除节点既有左子树又有右子树，则取此树中序遍历最接近欲删除节点的那个前驱(后继)节点作为新的树根节点
//
//		q = (*p);				//将当前欲删除节点赋给q
//
//		s = (*p)->lchild;		//s是当前欲删除节点的左孩子，
//
//		
//
//		while (s->rchild)
//
//		{						//此处循环为了寻找欲删除节点左孩子的最右孩子，即欲删除节点的中序遍历前驱节点
//
//			q = s;				//如果s有右孩子，则将s赋给q，s则替换为其右孩子，即q是s的父节点
//
//			s = s->rchild;
//
//		}
//
//		
//
//		(*p)->data = s->data;	//经过上述操作，s就是欲删除节点的中序遍历前驱节点，我们不是直接删除*p节点，而是
//
//								//将s的值赋给欲删除节点*p，然后删除s节点就可以达到调整的目的
//
//		if (q != (*p))
//
//		{								//若q不等于*p，说明q在while循环中被改变了，即s被替换为了其最右孩子
//
//			q->rchild = s->lchild;		//删除s节点后，不保证s不含左孩子，故将其s的左孩子赋给父节点q的右孩子
//
//		}
//
//		else
//
//		{								//若q等于*p，说明while循环体里的代码没有执行，即s不含右孩子，此时
//
//			q->lchild = s->lchild;		//删除s节点后，应该把s的左孩子赋给q的左孩子，不然就缺胳膊短腿了
//
//		}
//
//		
//
//		free(s);				//由于*p的值已被替换，结构也已调整完成，释放s节点占用内存
//
//	}
//
//	
//
//	return 1;
//
//}
//
// 
//
// 
//
////关键字查找函数，与二叉搜索树的查询函数一致，不再赘述，
//
////若有疑问请参考二叉搜索树(BST) ---- C语言
//
//int SearchAVL(AVLTree T, int key, AVLTree f, AVLTree *p)
//
//{
//
//	if (!T)
//
//	{
//
//		(*p) = f;
//
//		return 0;
//
//	}
//
//	else
//
//	{
//
//		if (key == T->data)
//
//		{
//
//			(*p) = T;
//
//			return 1;
//
//		}
//
//		else if (key < T->data)
//
//		{
//
//			return SearchAVL(T->lchild, key, T, p);
//
//		}
//
//		else
//
//		{
//
//			return SearchAVL(T->rchild, key, T, p);
//
//		}
//
//	}
//
//}
//
// 
//
////树的中序遍历函数(递归)
//
//void InOrderView(AVLTree T)
//
//{
//
//	if (!T)
//
//	{
//
//		return;
//
//	}
//
//	
//
//	InOrderView(T->lchild);
//
//	printf("%d--", T->data);
//
//	InOrderView(T->rchild);
//
//}
//
// 
//
//
////树的先序遍历函数(递归)
//
//void preOrderView(AVLTree T)
//
//{
//
//	if (!T)
//
//	{
//
//		return;
//
//	}
//
//
//	printf("%d,", T->data);
//
//	preOrderView(T->lchild);
//
//	preOrderView(T->rchild);
//
//}
//
//
//int main()
//
//{
//
//	int i, taller, lower;
//
//	int a[100] = {9,27,94,49,59,34,4,42,67,82,21,49,84,18,81,52,26,32,34,74,40,42,83,25,14,2,86,62,13,33,45,22,40,82,3,68,34,94,4,74,59,69,2,75,99,70,75,90,55,17,38,66,43,52,13,48,2,70,70,39,15,3,71,72,31,18,79,48,84,87,79,32,8,6,31,10,7,75,18,23,41,23,34,3,77,60,18,13,5,24,19,32,9,78,31,84,32,18,92,42};
//	int len = 100;
//	
////	for(int i=0;i<len;i++)
////
////	{
////
////    	for(int j=i+1;j<len;j++)
////
////    	{
////
////        	if(a[j]==a[i])
////
////        	{
////
////            	for(int k=j+1;k<len;k++)
////
////            	{
////
////                	a[k-1]=a[k];
////
////            	}
////
////            	len--;    //数组长度-1
////
////            	j--;    //重复点再次进行查重
////
////        	}
////
////    	}
////
////	}
//
//	
//	AVLTree p, T = NULL;
//
//	for (i = 0; i < len; i++)
//
//	{
//
//		InsertAVL(&T, a[i], &taller);
//
//	}
//
//	
//	preOrderView(T);
//	/*InOrderView(T);
//
//	
//
//	SearchAVL(T, 55, NULL, &p);
//
//	printf("\nSearch--p: %d", p->data);
//
//	
//
//	DeleteAVL(&T, 55, &lower);
//
//	
//
//	puts("\n");
//
//	InOrderView(T);
//
//	
//
//	SearchAVL(T, 55, NULL, &p);
//
//	printf("\nSearch--p: %d", p->data);
//
//	
//*/
//	return 0;
//
//}





//AVL(自动平衡二叉树)

#include <stdio.h>

#include <stdlib.h>

typedef int ElemType;

//每个结点的平均值

typedef enum

{

     EH = 0,

     LH = 1,

     RH = -1 

}bh_t;

 

typedef enum

{

      FALSE = 0,

      TRUE = 1

}bool_t;

 

//定义平衡二叉树

typedef struct BSTNode

{

     ElemType key;                                //平衡值

     int bf;                             

     struct BSTNode *lchild,*rchild;                

}BSTNode, *BSTree;

 

 

//中序遍历

void InOrderTraverse(BSTree root)

{

     if(NULL != root)

     {

          InOrderTraverse(root->lchild);

          printf("%d\t",root->key);

          InOrderTraverse(root->rchild);

    }

}

 

 

//前序遍历

void PreOrderTraverse(BSTree root)

{

     if(NULL != root)

    {

          printf("%d,",root->key);

          PreOrderTraverse(root->lchild);

          PreOrderTraverse(root->rchild);

     }

}

 

 

//单向右旋转

void R_Rotate(BSTree *p)

{

     BSTree lc=(*p)->lchild;

     (*p)->lchild=lc->rchild;

     lc->rchild=*p;

     *p=lc;

}

 

//单向左旋转

void L_Rotate(BSTree *p)

{

     BSTree rc=(*p)->rchild;

     (*p)->rchild=rc->lchild;

     rc->lchild=*p;

     *p=rc;

}

 

 

//先左旋后右旋平衡旋转

void LeftBalance(BSTree *T)

{

    BSTree lc=(*T)->lchild;

     BSTree rd = lc->rchild;

     //判断进行向哪边旋转

    switch(lc->bf)

     {

          case LH:

               (*T)->bf=lc->bf=EH;

               R_Rotate(T);

               break;

          case RH:

               switch(rd->bf)

               {

                case LH:

                     (*T)->bf=RH;

                     lc->bf=EH;

                     break;

                case EH:

                     (*T)->bf=lc->bf=EH;

                     break;

                case RH:

                     (*T)->bf=EH;

                     lc->bf=LH;

                     break;

               }

           rd->bf=EH;

           L_Rotate(&((*T)->lchild));

           R_Rotate(T);

           break;

     }

}

 

//先右旋后左旋平衡旋转

void RightBalance(BSTree *T)

{

     BSTree rc=(*T)->rchild;

     BSTree ld=rc->lchild;

     switch(rc->bf)

     {

          case RH:

               (*T)->bf=rc->bf=EH;

               L_Rotate(T);

               break;

          case LH:

               switch(ld->bf)

               {

                case RH:

     (*T)->bf=LH;

     rc->bf=EH;

     break;

    case EH:

     (*T)->bf=rc->bf=EH;

     break;

    case LH:

     (*T)->bf=EH;

     rc->bf=RH;

     break;

   }

   ld->bf=EH;

   R_Rotate(&((*T)->rchild));

   L_Rotate(T);

   break;

 }

}

 

 

//插入元素

bool_t InsertAVL(BSTree *t,ElemType e,bool_t *taller)

{

     if(NULL == t)

          return FALSE;

     if(NULL == *t)

     {

          *t=(BSTree)malloc(sizeof(BSTNode));

          if(NULL == *t)

               return FALSE;

          (*t)->key=e;

          (*t)->lchild=(*t)->rchild=NULL;

          (*t)->bf=EH;

          *taller=TRUE;

     }

     else

     {

          if(e==(*t)->key)

          {

               *taller=FALSE;

               return FALSE;

          }

         if(e<(*t)->key)

          {

               if(FALSE == InsertAVL(&((*t)->lchild),e,taller))

                return FALSE;

               if(*taller)

               {

                switch((*t)->bf)

                {

                     case LH:

                          LeftBalance(t);

                          *taller=FALSE;

                          break;

                     case EH:

                          (*t)->bf=LH;

                          *taller=TRUE;

                          break;

                     case RH:

                          (*t)->bf=EH;

                          *taller=FALSE;

                          break;

                }

               }

          }

          else

          {

               if(FALSE == InsertAVL(&((*t)->rchild),e,taller))

                return FALSE;

               if(*taller)

               {

                switch((*t)->bf)

                {

                     case RH:

                          RightBalance(t);

                          *taller=FALSE;

                          break;

                     case EH:

                          (*t)->bf=RH;

                          *taller=TRUE;

                          break;

                     case LH:

                          (*t)->bf=EH;

                          *taller=FALSE;

                          break;

                }

               }

          }

     }

     return TRUE;

}

 

 

BSTree searchAVL(BSTree t,ElemType key)

{

     BSTree p=t;

     while(p)

     {

          if(p->key==key)

               return p;

          else if(p->key<key)

               p=p->rchild;

          else

               p=p->lchild;

     }

     return p;

}

 

static void destroy(BSTree *t)

{

     if(NULL != *t)

     {

          destroy(&((*t)->lchild));

          destroy(&((*t)->rchild));

          free(*t);

          *t = NULL;

     }

     return;

}

void destroyAVL(BSTree root)

{

     if(NULL != root)

     {

          destroy(&root);

     }

     return;

}

 

int main()

{

     BSTree root=NULL,r;

     bool_t taller=FALSE;

     int array[]={74,13,77,44,72,93,27,69,5,56,19,83,25,29,48,21,55,1,98,78,33,56,14,75,32,66,27,46,50,84,76,38,71,88,2,56,12,60,63,19,26,7,96,72,16,53,81,30,10,45,91,25,91,54,7,13,73,49,14,39,70,71,19,3,91,68,55,66,14,39,29,67,19,23,23,54,40,98,74,74,24,69,16,10,62,83,33,19,92,83,83,55,87,85,7,1,75,6,52,40};

     int i = 0;

     for(i=0; i < 100; i++)

          InsertAVL(&root,array[i],&taller);

     printf("中序遍历:\n");

     InOrderTraverse(root);

     printf("\n先序遍历\n");

     PreOrderTraverse(root);

    printf("\n搜索：37\n");

     r=searchAVL(root,37);

     if(r)

     {

          printf("%d\n",r->key);

     }

     else

     {

          printf("not find!\n");

     }

     destroyAVL(root);

     root = NULL;

     return 0;

}
