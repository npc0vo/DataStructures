//
// Created by Npc on 2024/4/21.
//

#ifndef C_BINARYTREE_H
#define C_BINARYTREE_H

#include "stdio.h"
#include "stdlib.h"
//二叉树的节点设计
/*a)结点元素，data域，用来存储数据，其可以是int，char等基本的类型，同时也可以是struct等这些复杂的复合数据类型。

b)左孩子结点，left指针，总是用来指向当前结点的下一层的左边结点，其属于一种指针。

c)右孩子结点，right指针，总是用来指向当前结点的下一层的右边结点，其属于一种指针。

d)父结点（可选），parent指针，总是指向当前结点的前一个结点，简称父亲结点，其不属于必须结点设计，省略掉可以打扰节省内存的效果，而使用则可以更方便进行定向搜索，本案例中不使用父节点。*/

//树的节点
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

//树根
typedef struct {
    Node* root;
}Tree;

//树的创建
void insert(Tree* tree,int value)
{
    //创建一个节点，让左右指针全部指向空,数据为value
    //即树的初始化
    Node *node=(Node*)malloc(sizeof (Node));
    node->data=value;
    node->left=NULL;
    node->right=NULL;

    //判断树是不是空树，如果是，直接让树根指向这一个节点
    if(tree->root==NULL)
    {
        tree->root=node;
    }else//不是空树
    {
        Node *temp=tree->root;
        while(temp!=NULL)
        {
            //小于就进左儿子
            if(value<temp->data) {
                if (temp->left == NULL) {
                    temp->left = node;
                    return;
                } else {//否则继续往下搜寻
                    temp = temp->left;
                }
            }
            else{
                if(temp->right==NULL)
                {
                    temp->right=node;
                    return;
                }else{
                    temp=temp->right;
                }
            }
        }
    }
    return;


}


//遍历树
/*Method-1*/
//in-order traversal
void inorder(Node *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}
/*Method-2*/
//preorder traversal
void preorder(Node* node)
{
    if(node!=NULL)
    {;
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
/*Method-3*/
//postorder traversal
void postorder(Node* node)
{
    if(node!=NULL)
    {;
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}
#endif //C_BINARYTREE_H
