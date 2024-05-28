//
// Created by Npc on 2024/5/8.
//

#include "threadedBinaryTree .h"
// 测试程序
int main() {
    TBTNode* root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);
    root->rchild->lchild = createNode(6);
    root->rchild->rchild = createNode(7);

    // 中序线索化
    TBTNode* pre = NULL;
    InThread(root, pre);
    // 中序遍历线索二叉树
    printf("Inorder Traversal: ");
    InOrder(root);
    printf("\n");

    // 先序线索化
    pre = NULL;
    PreThread(root, pre);
    // 先序遍历线索二叉树
    printf("Preorder Traversal: ");
    PreOrder(root);
    printf("\n");

    // 后序线索化
    pre = NULL;
    PostThread(root, pre);
    // 后序遍历线索二叉树
    printf("Postorder Traversal: ");
    PostOrder(root);
    printf("\n");
    system("pause");
    return 0;
}