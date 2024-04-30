//
// Created by Npc on 2024/4/25.
//DFS（Depth-First-Search，深度优先搜索）算法的具体做法是：从某个点一直往深处走，走到不能往下走之后，
// 就回退到上一步，直到找到解或把所有点走完。


/*
void dfs()//参数用来表示状态
{
    if(到达终点状态)
    {
        ...//根据需求添加
        return;
    }
    if(越界或者是不合法状态)
        return;
    if(特殊状态)//剪枝，去除一些不需要访问的场景，不一定i俺家
        return ;
    for(扩展方式)
    {
        if(扩展方式所达到状态合法)
        {
            修改操作;//根据题意来添加
            标记；
            dfs（）；
            (还原标记)；
            //是否还原标记根据题意
            //如果加上（还原标记）就是 回溯法
        }

    }
}*/
//从pos点开始，深度遍历无向图
//pos表示当前结点，G表示图，visited[]数组用来表示该节点是否已经访问
#include <stdio.h>
#include <stdlib.h>

// 定义图的顶点结构体
typedef struct ArcNode {
    int adjvex;             // 邻接点在顶点数组中的下标
    struct ArcNode *next;   // 指向下一个邻接点的指针
} *node;

typedef struct VertexNode {
    node firstarc;          // 指向第一个邻接点的指针
} VertexNode;

typedef struct Graph {
    VertexNode vertice[30]; // 图的顶点数组
} *pGraph;

// 初始化图
pGraph initGraph() {
    pGraph G = (pGraph)malloc(sizeof(struct Graph));
    for (int i = 0; i < 30; ++i) {
        G->vertice[i].firstarc = NULL;
    }
    return G;
}

// 添加边到图中
void addEdge(pGraph G, int from, int to) {
    node newNode = (node)malloc(sizeof(struct ArcNode));
    newNode->adjvex = to;
    newNode->next = G->vertice[from].firstarc;
    G->vertice[from].firstarc = newNode;
}

// 深度优先搜索函数
void DFS(int pos, pGraph G, int visited[30]) {
    node p;
    printf("%d ", pos);    // 打印深度遍历的点
    visited[pos] = 1;      // 标记为已访问过
    p = G->vertice[pos].firstarc;  // 将当前点的第一个指针赋值给p
    // 是否存在邻接点
    while (p != NULL) {
        // 判断该邻接点是否被遍历过
        if (visited[p->adjvex] == 0) {
            DFS(p->adjvex, G, visited);
        }
        p = p->next;    // 后移一位，为之后是否有邻接点做准备
    }
}

int main() {
    // 初始化图
    pGraph G = initGraph();
    int visited[30] = {0};  // 初始化访问标记数组
    // 添加边到图中
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 5);
    // 深度优先搜索并打印遍历结果
    printf("DFS result: ");
    DFS(0, G, visited);
    printf("\n");
    system("pause");
    return 0;
}
/*
    0
   / \
  1   2
 / \   \
3   4   5
*/
