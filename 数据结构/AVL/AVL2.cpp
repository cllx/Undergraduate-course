//
///*	
//
//*	ƽ�������(AVL):�����ڼ��������(��б������б��)
//
//*	����������(BST)����ʱ��Ч�ʴ�󽵵͵�O(n)������Ҫ
//
//*	�������ƽ�⣬ƽ��ķ����кܶ��֣���AVL��������ȣ�
//
//*	�˴�ͨ��ƽ�����ӵķ���ʹ��AVL�����ﵽƽ���Ŀ�ġ�
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
//#define LH -1		//LH,EH,RH��ʾƽ������ֵ
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
//	int bf;//����ǰ�ڵ���������߶ȼ�ȥ�������߶ȵĲ�
//
//	struct Anode *lchild, *rchild;
//
//}Anode, *AVLTree;/*AVL���ṹ���ڶ����������ϼ���һ��bfƽ������*/
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
////AVL������ؼ��ֲ���,*taller������¼����ڵ�����Ƿ��г���
//
//int InsertAVL(AVLTree *T, int key, int *taller)
//
//{
//
//	if (!(*T))
//
//	{//��AVL���ǿ�������ֱ�ӷ���ڵ��ڴ����ؼ��֣�������
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
//	{//��AVL�ǿ���
//
//		if (key == (*T)->data)
//
//		{//����ҵ���ǰ�ڵ��ֵ����������Ĺؼ��֣���˵���Ѵ��ڸùؼ��֣������ظ����룬��û����
//
//			(*taller) = 0;
//
//			return 0;
//
//		}
//
//		else if (key < (*T)->data)
//
//		{//��������Ĺؼ���С�ڵ�ǰ�ڵ�ֵ�����ڵ�ǰ�ڵ���������ݹ鿴�Ƿ����ýڵ�
//
//			if (!InsertAVL(&(*T)->lchild, key, taller))
//
//			{//����ʧ��
//
//				return 0;
//
//			}
//
//			if (*taller)
//
//			{//������ɹ�����*taller��Ȼ����1����ʱֻҪ���ݵ�ǰ�ڵ��ƽ���������������ﵽƽ��
//
//				switch ((*T)->bf)
//
//				{						//����ڵ��ڵ�ǰ�ڵ����������ĳ��
//
//					case LH:			//���ԭ���������߶Ⱦͱ���������1
//
//						LeftBalance(T); //�͵�����ƽ�⺯��
//
//						(*taller) = 0;  //ƽ������������ԭ���������޳��ߣ�������(*taller) = 0
//
//						break;
//
//					case EH:			//���ԭ�����������������ȸ�
//
//						(*T)->bf = LH;	//��ǰ�ڵ��ƽ�����Ӿ͸�ΪLH(��߸�1)
//
//						(*taller) = 1;	//���ԭ����������
//
//						break;
//
//					case RH:			//���ԭ���������߶Ⱦͱ���������1
//
//						(*T)->bf = EH;	//��������������ؼ��ֽڵ�󣬵�ǰ�ڵ�ƽ�����ӱ�ΪEH(���ҵȸ�)
//
//						(*taller) = 0;	//���ԭ��������δ����
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
//		{//��������Ĺؼ��ִ��ڵ�ǰ�ڵ�ֵ�����ڵ�ǰ�ڵ���������ݹ鿴�Ƿ����ýڵ�
//
//		 //���´������ͬ�ϣ�ֻ���������������������£�����׸��
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
////��ƽ�⺯�������ô˺���˵����ǰ�ڵ��������Ȼ��߲�ƽ��
//
//int LeftBalance(AVLTree *T)
//
//{//�˺�����������ƽ������������1.���ڵ㵥����		2.���ڵ���������Ȼ����ڵ�����
//
//	AVLTree L, Lr;
//
//	L = (*T)->lchild;		//��ǰ�����ڵ������
//
//	
//
//	switch (L->bf)
//
//	{
//
//		case LH:			//��L�������ߣ���ֱ�Ӹ��ڵ㵥���������������ڵ��������ӵ�ƽ������ֵ
//
//			(*T)->bf = L->bf = EH;		//��������벻�ɵ���
//
//			RightRotate(T);				//��Ϊ����ת������ı�ԭ����Tֵ(����ǰ�����ڵ㷢���仯)
//
//			break;
//
//		case RH:
//
//			Lr = L->rchild;	//��L�������ߣ������L���Һ���Lr��ƽ������ֵ���������ڵ�T��L��ƽ������ֵ
//
//			
//
//			switch(Lr->bf)
//
//			{//������޸�ƽ������ֵ�������л�����ͼ���
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
//			Lr->bf = EH;	//ƽ�����L���Һ���ƽ����������ΪEH�������ҵȸ�
//
//			
//
//			LeftRotate(&(*T)->lchild);		//�ȶԸ��ڵ�T�����ӽ�������
//
//			RightRotate(T);					//�ٶԸ��ڵ�T��������
//
//			break;
//
//	}
//
//}
//
// 
//
////��ƽ�⺯��������ͬ�ϣ���������ͬ�ԳƳ��񣬲���׸���������Ķ�
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
////��������
//
//void LeftRotate(AVLTree *T)
//
//{
//
//	AVLTree R;			
//
//	R = (*T)->rchild;				//ȡ��ǰ�����ڵ���Һ���
//
//	(*T)->rchild = R->lchild;		//���Һ���R��������Ϊ��ǰ�ڵ�*T���Һ���
//
//	R->lchild = (*T);				//��*T��ΪR������
//
//	(*T) = R;						//����ǰ�ڵ���Һ���R��Ϊ�µ������ڵ�
//
//}
//
// 
//
////��������
//
//void RightRotate(AVLTree *T)
//
//{//���������������෴������׸��
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
////AVL��ɾ���ؼ��ֲ���,*lower������¼����ڵ�����Ƿ��б䰫
//
//int DeleteAVL(AVLTree *T, int key, int *lower)
//
//{
//
//	if (!(*T))
//
//	{//����ǰ��Ϊ��������ɾ��ʧ�ܷ���0
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
//		{						//����ǰ�ڵ������ɾ���ؼ���
//
//			Delete(T);			//�����ɾ������
//
//			(*lower) = 1;		//���䰫
//
//			return 1;
//
//		}
//
//		else if (key < (*T)->data)
//
//		{//����ɾ���ؼ���С�ڵ�ǰ�ڵ�ֵ
//
//			if (!DeleteAVL(&(*T)->lchild, key, lower))
//
//			{//���������Ҳ�Ҳ������ڴ˹ؼ��ֵĽڵ�ֵ��ɾ��ʧ��
//
//				return 0;
//
//			}
//
//			
//
//			if (*lower)
//
//			{//��ɾ���ɹ�����*lower��Ȼ����1����ʱֻҪ���ݵ�ǰ�ڵ��ƽ���������������ﵽƽ��
//
//				switch ((*T)->bf)
//
//				{								//ɾ���Ľڵ��ڵ�ǰ�ڵ����������ĳ��
//
//					case LH:					//���ԭ���������߶Ⱦͱ���������1
//
//						(*T)->bf = EH;			//��ɾ�������ߵȸߣ���(*T)->bf = EH
//
//						(*lower) = 1;			//���ԭ�������䰫
//
//						break;
//
//					case EH:					//���ԭ�����������������ȸ�
//
//						(*T)->bf = RH;			//��ɾ�����������Ƚϸ�
//
//						(*lower) = 0;			//������䰫���ұ߲��䣬����������û�䰫
//
//						break;
//
//					case RH:					//���ԭ���������߶Ⱦͱ���������1
//
//						RightBalance(T);		//��ɾ��������������������2������Ҫ������ƽ�⺯��
//
//						(*lower) = 1;			//�����������ԭ�������䰫
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
//		{//����ɾ���ؼ��ִ��ڵ�ǰ�ڵ�ֵ������ͬ�ϣ�����׸��
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
////AVL��ɾ���ڵ��Լ������ṹ��������
//
//int Delete(AVLTree *p)
//
//{//*pΪ��ǰҪɾ���������ڵ㣬Ϊ��������������������ʣ����������
//
//	AVLTree q, s;//���������ڵ�ָ�룬q��s�ĸ��ڵ�
//
//	
//
//	if ((*p)->rchild == NULL)
//
//	{							//�����ǰ��ɾ���ڵ�û��������(����)
//
//		q = (*p);				//��ֱ�ӽ���ǰ�ڵ��������Ϊ�µ������ڵ�
//
//		(*p) = (*p)->lchild;	
//
//		free(q);				//�ͷŽڵ�ռ���ڴ�
//
//	}
//
//	else if ((*p)->lchild == NULL)
//
//	{							//����ͬ��
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
//	{//����ǰ��ɾ���ڵ������������������������ȡ�������������ӽ���ɾ���ڵ���Ǹ�ǰ��(���)�ڵ���Ϊ�µ������ڵ�
//
//		q = (*p);				//����ǰ��ɾ���ڵ㸳��q
//
//		s = (*p)->lchild;		//s�ǵ�ǰ��ɾ���ڵ�����ӣ�
//
//		
//
//		while (s->rchild)
//
//		{						//�˴�ѭ��Ϊ��Ѱ����ɾ���ڵ����ӵ����Һ��ӣ�����ɾ���ڵ���������ǰ���ڵ�
//
//			q = s;				//���s���Һ��ӣ���s����q��s���滻Ϊ���Һ��ӣ���q��s�ĸ��ڵ�
//
//			s = s->rchild;
//
//		}
//
//		
//
//		(*p)->data = s->data;	//��������������s������ɾ���ڵ���������ǰ���ڵ㣬���ǲ���ֱ��ɾ��*p�ڵ㣬����
//
//								//��s��ֵ������ɾ���ڵ�*p��Ȼ��ɾ��s�ڵ�Ϳ��Դﵽ������Ŀ��
//
//		if (q != (*p))
//
//		{								//��q������*p��˵��q��whileѭ���б��ı��ˣ���s���滻Ϊ�������Һ���
//
//			q->rchild = s->lchild;		//ɾ��s�ڵ�󣬲���֤s�������ӣ��ʽ���s�����Ӹ������ڵ�q���Һ���
//
//		}
//
//		else
//
//		{								//��q����*p��˵��whileѭ������Ĵ���û��ִ�У���s�����Һ��ӣ���ʱ
//
//			q->lchild = s->lchild;		//ɾ��s�ڵ��Ӧ�ð�s�����Ӹ���q�����ӣ���Ȼ��ȱ�첲������
//
//		}
//
//		
//
//		free(s);				//����*p��ֵ�ѱ��滻���ṹҲ�ѵ�����ɣ��ͷ�s�ڵ�ռ���ڴ�
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
////�ؼ��ֲ��Һ�����������������Ĳ�ѯ����һ�£�����׸����
//
////����������ο�����������(BST) ---- C����
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
////���������������(�ݹ�)
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
////���������������(�ݹ�)
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
////            	len--;    //���鳤��-1
////
////            	j--;    //�ظ����ٴν��в���
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





//AVL(�Զ�ƽ�������)

#include <stdio.h>

#include <stdlib.h>

typedef int ElemType;

//ÿ������ƽ��ֵ

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

 

//����ƽ�������

typedef struct BSTNode

{

     ElemType key;                                //ƽ��ֵ

     int bf;                             

     struct BSTNode *lchild,*rchild;                

}BSTNode, *BSTree;

 

 

//�������

void InOrderTraverse(BSTree root)

{

     if(NULL != root)

     {

          InOrderTraverse(root->lchild);

          printf("%d\t",root->key);

          InOrderTraverse(root->rchild);

    }

}

 

 

//ǰ�����

void PreOrderTraverse(BSTree root)

{

     if(NULL != root)

    {

          printf("%d,",root->key);

          PreOrderTraverse(root->lchild);

          PreOrderTraverse(root->rchild);

     }

}

 

 

//��������ת

void R_Rotate(BSTree *p)

{

     BSTree lc=(*p)->lchild;

     (*p)->lchild=lc->rchild;

     lc->rchild=*p;

     *p=lc;

}

 

//��������ת

void L_Rotate(BSTree *p)

{

     BSTree rc=(*p)->rchild;

     (*p)->rchild=rc->lchild;

     rc->lchild=*p;

     *p=rc;

}

 

 

//������������ƽ����ת

void LeftBalance(BSTree *T)

{

    BSTree lc=(*T)->lchild;

     BSTree rd = lc->rchild;

     //�жϽ������ı���ת

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

 

//������������ƽ����ת

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

 

 

//����Ԫ��

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

     printf("�������:\n");

     InOrderTraverse(root);

     printf("\n�������\n");

     PreOrderTraverse(root);

    printf("\n������37\n");

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
