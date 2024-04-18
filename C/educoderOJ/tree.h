//
// Created by Npc on 2024/4/9.
//

#ifndef C_TREE_H
#define C_TREE_H
#include<stdio.h>
#include<stdlib.h>

typedef struct Bitnode
{
    char data;
    struct Bitnode *left,*right;
}Bitnode;
Bitnode *CreatBitree_level();
Bitnode* buildTree() {
    char data;
    scanf("%c",&data);
    if(data=='$')
    return NULL;
    if(data=='#')
        return NULL;
    else
    {
        Bitnode *t=(Bitnode*)malloc(sizeof(Bitnode));
        t->data=data;
        t->left=buildTree();
        t->right=buildTree();
        return t;
    }
}
int depth(Bitnode *t);
#endif //C_TREE_H
