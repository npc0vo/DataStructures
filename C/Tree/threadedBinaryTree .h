//
// Created by Npc on 2024/5/8.
//

#ifndef C_THREADEDBINARYTREE_H
#define C_THREADEDBINARYTREE_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*二叉树学到现在，会产生两个问题：

在n个结点的二叉树中，必定有n+1个空链域（叶子结点的左右子树空间浪费了）
二叉树的遍历，无论是递归还是非递归算法，效率都不算高。*/
#define ElemType int
typedef struct TBTNode{
    ElemType data; //数据元素
    TBTNode*lchild,*rchild;//左右孩子指针
    int ltag;//默认tag值为0代表左孩子，1表示前驱
    int rtag;//默认tag值为0代表有孩子，1表示后继
}TBTNode;

// 创建新节点
TBTNode* createNode(ElemType data) {
    TBTNode* newNode = (TBTNode*)malloc(sizeof(TBTNode));
    if (!newNode) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->ltag = 0;
    newNode->rtag = 0;
    return newNode;
}

// 中序线索化
void InThread(TBTNode* p, TBTNode*& pre) {
    if (p) {
        InThread(p->lchild, pre);
        if (!p->lchild) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre && !pre->rchild) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

// 中序遍历线索二叉树
void InOrder(TBTNode* root) {
    TBTNode* p = root;
    while (p) {
        while (p->ltag == 0)
            p = p->lchild;
        printf("%d ", p->data);
        while (p->rtag == 1 && p->rchild) {
            p = p->rchild;
            printf("%d ", p->data);
        }
        p = p->rchild;
    }
}

// 先序线索化
void PreThread(TBTNode* p, TBTNode*& pre) {
    if (p) {
        if (!p->lchild) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre && !pre->rchild) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        if (p->ltag == 0)
            PreThread(p->lchild, pre);
        if (p->rtag == 0)
            PreThread(p->rchild, pre);
    }
}

// 先序遍历线索二叉树
void PreOrder(TBTNode* root) {
    TBTNode* p = root;
    while (p) {
        printf("%d ", p->data);
        while (p->ltag == 0) {
            p = p->lchild;
            printf("%d ", p->data);
        }
        while (p->rtag == 1 && p->rchild)
            p = p->rchild;
        p = p->rchild;
    }
}

/// 后序线索化
void PostThread(TBTNode* p, TBTNode*& pre) {
    if (p) {
        PostThread(p->lchild, pre);
        PostThread(p->rchild, pre);
        if (!p->lchild) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre && !pre->rchild) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
    }
}

// 后序遍历线索二叉树
void PostOrder(TBTNode* root) {
    if (!root) return;

    TBTNode* p = root;
    TBTNode* pre = NULL;

    while (p != NULL && p->ltag == 0) {
        p = p->lchild;
    }

    while (p) {
        if (p->rtag == 0 && p->rchild != pre) {
            p = p->rchild;
            while (p != NULL && p->ltag == 0) {
                p = p->lchild;
            }
        } else {
            printf("%d ", p->data);
            pre = p;
            p = p->rchild;
        }
    }
}









/*
void InThread(TBTNode*p,TBTNode* &pre);
*/
/*通过中序遍历线索化*//*

void createInThread(TBTNode *root)
{
    TBTNode *pre=NULL;//前驱节点指针
    if(root!=NULL)
    {
        InThread(root,pre);
        //处理中序最后的一个节点
        pre->rchid=NULL;
        pre->rtag=1;
    }
}

void InThread(TBTNode*p,TBTNode* &pre)
{
    if(p!=NULL)
    {
        InThread(p->lchid,pre);//递归左子树线索化
        if(p->lchid==NULL)
        {
            //建立做孩子的前驱线索
            p->lchid=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchid==NULL)
        {
            //建立前驱节点的后继线索
            pre->rchid=p;
            pre->rtag=1;
        }
        pre=p;//标记当前节点，使其成刚刚访问的节点
        InThread(p->rchid,pre);
    }
}


*/
/*通过先序遍历线索化*//*

void preThread(TBTNode *p,TBTNode *&pre)
{
    if(p!=NULL)
    {
        if(p->lchid==NULL)
        {
            p->lchid=pre;
            p->lchid=1;
        }
        if(pre!=NULL&&pre->rchid==NULL)
        {
            pre->rchid=p;
            pre->rtag=1;
        }
    }
    pre=p;
    if(p->ltag==0)
    {
        preThread(p->lchid,pre);
    }
    if(p->rtag==0)
    {
        preThread(p->rchid,pre);
    }
    */
/*为何这边要加上判断语句if(p->ltag == 0)和 if(p->rtag == 0)？

是为了避免重复遍历同一个结点。如果不判断左右孩子是否为线索，那么程序就有可能把线索也当成左右孩子来访问，从而导致重复遍历同一个结点(绕圈圈~)，最终导致栈溢出。*//*

}
*/

#endif //C_THREADEDBINARYTREE_H
