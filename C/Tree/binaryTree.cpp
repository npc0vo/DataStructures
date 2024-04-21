//
// Created by Npc on 2024/4/21.
//

#include "binaryTree.h"
#include "stdlib.h"
#include "iostream"
int main()
{
    Tree tree;
    tree.root=NULL;//创建一个空树
    int n;
    std::cout<<"请输入要创建多大的树"<<std::endl;
    scanf("%d",&n);

    //输入n个数,并创建这个树
    for(int i=0;i<n;i++)
    {
        int temp;
        std::cout<<">";
        scanf("%d",&temp);
        insert(&tree,temp);
    }


    printf("\n");
    std::cout<<"中序遍历结果:"<<std::endl;
    inorder(tree.root); //中序遍历
    printf("\n");
    std::cout<<"先序遍历结果:"<<std::endl;
    preorder(tree.root);
    printf("\n");
    std::cout<<"后序遍历结果:"<<std::endl;
    postorder(tree.root);
    system("pause");
    return 0;
}