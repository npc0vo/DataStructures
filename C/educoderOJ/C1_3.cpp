//
// Created by Npc on 2024/4/9.
//
/*
根据带有空二叉树的先序序列建树

建好这棵二叉树之后，请求出它的深度。二叉树的深度是指从根节点到叶子结点时，最多经过了几层。如果是空树，深度为零。*/
#include"tree.h"
#include "iostream"
int depth(Bitnode *t)
{
    //在这里输入代码
    /*******begin*****/
    if(t==NULL)
    {
        return 0;
    }
    int left= depth(t->left);
    int right= depth(t->right);
    int max=0;
    if(left>right)
    {
        max=left;
    }
    else
        max=right;
    return max+1;
    /******end********/
}
