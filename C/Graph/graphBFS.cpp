//
// Created by Npc on 2024/4/25.
//

/**
 * 返回合适的检索数据
 */
/*
int BFS(Node root, Node target)
{
    Queue<Node> queue;  //创建队列
    int step = 0;       // 当前队列的步骤点
    // initialize
    add root to queue;
    // BFS
    while (queue is not empty)
    {
        step = step + 1;
        //步数逐渐增加
        int size = queue.size();
        for (int i = 0; i < size; ++i)
        {
            Node cur = the first node in queue;
            if cur is target
                return step - 1;
            for (Node next : the neighbors of cur)
            {//这里常用一个二维方向数组实现
                add next to queue;
            }
            remove the first node from queue;
        }
    }
    return -1;          //出错返回值
}*/
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
    int Vnum;               // 图的顶点数量
} *pGraph;

// 初始化图
pGraph initGraph(int Vnum) {
    pGraph G = (pGraph)malloc(sizeof(struct Graph));
    for (int i = 0; i < 30; ++i) {
        G->vertice[i].firstarc = NULL;
    }
    G->Vnum = Vnum;
    return G;
}

// 添加边到图中
void addEdge(pGraph G, int from, int to) {
    node newNode = (node)malloc(sizeof(struct ArcNode));
    newNode->adjvex = to;
    newNode->next = G->vertice[from].firstarc;
    G->vertice[from].firstarc = newNode;
}

// 广度优先搜索函数
void BFSL(int pos, pGraph G, int visited[30]) {
    int queue[G->Vnum];     // 队列辅助 BFS 遍历
    int head = 0, tail = 0; // 队头、队尾指针
    node p;
    queue[tail] = pos;
    visited[pos] = 1;       // 标记遍历过
    tail++;
    while (head != tail) {
        pos = queue[head];  // 出队操作
        head++;
        printf("%d ", pos);
        p = G->vertice[pos].firstarc;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) // 判断是否遍历过
            {
                queue[tail] = p->adjvex;    // 入队操作
                visited[p->adjvex] = 1;     // 标记遍历过
                tail++;
            }
            p = p->next;
        }
    }
}

int main() {
    // 初始化图
    pGraph G = initGraph(6);
    int visited[30] = {0};  // 初始化访问标记数组
    // 添加边到图中
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 5);
    // 广度优先搜索并打印遍历结果
    printf("BFS result: ");
    BFSL(0, G, visited);
    printf("\n");
    system("pause");
    return 0;
}
/*
   0
  / \
 1   2
 |   |
 4   5
 |
 3
*/
