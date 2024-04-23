//
// Created by Npc on 2024/4/22.
//



/*1. 简介
哈夫曼树（Huffman Tree），又名：最优二叉树，赫夫曼树
其标准含义是：给定N个权值作为N个叶子结点，构造一棵二叉树，若该树的带权路径长度达到最小，
 称这样的二叉树为最优二叉树，也称为哈夫曼树。哈夫曼树是带权路径长度最短的树，权值较大的结点离根较近。*/

/*2.相关名词
a) 路径：在一棵树中，一个结点到另一个结点之间的通路，称为路径。

b) 路径长度：在一条路径中，每经过一个结点，路径长度都要加 1 。例如在一棵树中，规定根结点所在层数为1层，那么从根结点到第 i 层结点的路径长度为 i - 1 。

c) 结点的权：给每一个结点赋予一个新的数值，被称为这个结点的权。

d) 结点的带权路径长度：指的是从根结点到该结点之间的路径长度与该结点的权的乘积。

e)  树的带权路径长度为树中所有叶子结点的带权路径长度之和。通常记作 “WPL”*/
#ifndef C_HUFFMANTREE_H
#define C_HUFFMANTREE_H
#include "stdio.h"
#include "stdlib.h"

/*构建HuffmanTree的算法步骤,原则:权重越大的结点距离树根越近*/
/* 1.首先，选出我们数据中最小的两个数据，
 * 构建成二叉树的左孩子和右孩子，而根的数据为两者之和
 * 2.其次，将刚才合成的数据作为右孩子，左孩子从未处理的数据中选出最小的一个，
 * 作为左孩子，他们的根同样为左右孩子的权值和
 * 3.不断重复上述的步骤，直到将所有的数据全部处理完并构建出二叉树
 * ，这棵二叉树就是我们的哈夫曼树。*/
/*有点贪心算法的味道*/



/*HuffmanTree的节点结构*/
typedef struct {
    int weight;   //节点权重
    int parent,left,right;  //父节点，左孩子和右孩子在数组中的位置下标
}HTNode,*HuffmanTree;   //HuffmanTree 是指向htnode结构体的指针
 void Select(HuffmanTree HT,int end,int *s1,int *s2);

/*HuffmanTree的构建*/
/*参数说明，HT为地址传递的HTNODE类型数组,w为存储节点权重值的数组,n为结点个数*/
void CreateHuffmanTree(HuffmanTree *HT,int *w,int n)
{
    if(n<=1)
    {
        return;
    }
    int m=2*n-1;//哈夫曼树总节点数，n为叶子节点数  即n+n-1 n-1是构建HuffmanTree新产生的节点数
    *HT=(HuffmanTree) malloc((sizeof (HTNode))*(m+1));//不用0号位置，便于定位
    HuffmanTree p=*HT;//p是HTnode类型数组的地址

    //初始化
    //初始化哈夫曼树中的所有节点,即需要构建的节点
    for(int i=1;i<=n;i++)
    {
        (p+i)->weight=*(w+i-1);
        (p+i)->parent=0;
        (p+i)->left=0;
        (p+i)->right=0;
    }
    //从树组的下标n+1开始初始化哈夫曼树中除叶子节点外的节点
    for(int i=n+1;i<=m;i++)
    {
        (p+i)->weight=0;
        (p+i)->parent=0;
        (p+i)->left=0;
        (p+i)->right=0;
    }

    //构建哈夫曼树
    for(int i=n+1;i<=m;i++)
    {
        int s1,s2;
        Select(*HT,i-1,&s1,&s2); //查找HT类型数组中权重最小的两个,S1,S2分别是其下标
        (*HT)[s1].parent=(*HT)[s2].parent=i;
        (*HT)[i].left=s1;
        (*HT)[i].right=s2;
        (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
    }
}


//哈夫曼树查找函数的实现
/*查找算法根据构建哈夫曼树算法衍生而来，
 * 我们在构建二叉树时需要查找出哪些数据最小，以符合我们哈夫曼树的最优解情况。*/
/* 算法步骤-
 * 1.从待处理数据的头部位置开始，首先找到两个无父结点的结点（说明还未使用其构建成树）
 * 2.然后和后续无父结点的结点依次做比较，
 * 3.如果比两个结点中较小的那个还小，就保留这个结点，删除原来较大的结点；
 * 4.如果介于两个结点权重值之间，替换原来较大的结点；*/
/*参数说明HT即HTNODE类型数组，*/
 void Select(HuffmanTree HT,int end,int *s1,int *s2)
{
    int min1=0,min2=0;
    //遍历树组的初始下标为1
    int i=1;
    //找到还没有父节点的节点，即没有成树的节点
    while(HT[i].parent!=0&&i<=end)
    {
        i++;
    }
    min1=HT[i].weight;
    *s1=i;
    i++;
    while(HT[i].parent!=0&&i<=end)
    {
        i++;
    }
    //对找到的两个结点比较大小，min2为大的，min1为小的S
    if(HT[i].weight<min1)
    {
        min2=min1;
        *s2=*s1;
        min1=HT[i].weight;
        *s1=i;
    }
    else{
        min2=HT[i].weight;
        *s2=i;
    }
    i++;

    //两个结点和后续的所有未成树的节点作比较
    for(;i<=end;i++)
    {
        //如果遍历的节点已成树就直接跳过
        if(HT[i].parent!=0)
        {
            continue;
        }
        //如果比最小的小，就将min2=min1，min1赋值为新节点的下表
        if(HT[i].weight<min1)
        {
            min2=min1;
            *s2=*s1;
            min1=HT[i].weight;
            *s1=i;
        }
        //如果介于两者之间,就跟将min2赋值为新节点
        else if(HT[i].weight>=min1&&HT[i].weight<min2)
        {
            *s2=i;
            min2=HT[i].weight;
        }
        //如果比两者都大就什么都不做
    }
}



#endif //C_HUFFMANTREE_H
