//
// Created by Npc on 2024/4/28.
//

#ifndef C_KRUSKAL_H
#define C_KRUSKAL_H
/*1. 克鲁斯卡尔算法简介
克鲁斯卡尔（Kruskal）算法是一种用来寻找最小生成树的算法（用来求加权连通图的最小生成树的算法）。在剩下的所有未选取的边中，找最小边，如果和已选取的边构成回路，则放弃，选取次小边。

而具体的操作过程为：

a) 将图的所有连接线去掉，只剩顶点

b) 从图的边集数组中找到权值最小的边，将边的两个顶点连接起来

c)  继续寻找权值最小的边，将两个顶点之间连接起来，如果选择的边使得最小生成树出现了环路，则放弃该边，选择权值次小的边

d) 直到所有的顶点都被连接在一起并且没有环路，最小生成树就生成了。*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAXEDGE 100
#define MAXVERTEX 100
typedef struct Edge{
    int begin; //边的起点
    int end; //边的终点
    int weight; //边的权值
}Edge;

typedef struct Graph{
    char vertex[MAXVERTEX];
    Edge edges[MAXEDGE];
    int numvertex,numedges;
}MGraph;

void CreateGraph(MGraph *G)
{
    printf("请输入顶点和边的个数:\n");
    scanf("%d %d",&G->numvertex,&G->numedges);
    printf("请输入顶点：\n");
    getchar();//利用该函数情况缓冲区
    for(int i=0;i<G->numvertex;i++)
    {
        scanf("%c",&G->vertex[i]);
    }
    printf("按权值从小到大输入边(vi,vj)对应的起点和终点的下标，begin,end,以及权值weight“\n");
    for(int k=0;k<G->numedges;k++)
    {
        Edge e;
        scanf("%d%d%d",&e.begin,&e.end,&e.weight);
        G->edges[k]=e;
    }
}

int Find(int *parent,int f)
{
    while(parent[f]>0)
    {
        f=parent[f];
    }
    return f;
}

//最小生成树,克鲁斯卡尔算法
void Kruskal(MGraph *G)
{
    int parent[MAXVERTEX]; //存放最小生成树的顶点
    for(int i=0;i<G->numvertex;i++)
    {
        parent[i]=0;
    }
    int m,n;
    for(int i=0;i<G->numvertex;i++)
    {
        n= Find(parent,G->edges[i].begin);
        m= Find(parent,G->edges[i].end);
        if(n!=m)//n=m说明有环
        {
            parent[n]=m;
            printf("(%d,%d) %d\t",G->edges[i].begin,G->edges[i].end,G->edges[i].weight);
            //打印边和权值

        }
    }
}
#endif //C_KRUSKAL_H
