//
// Created by Npc on 2024/4/24.
//

/*邻接表（Adjacency List）顾名思义，就是通过链表或者利用数组模拟链表的方式将图的相连接关系表示的一种方法，
 * 存储方法跟树的孩子链表示法相类似，是一种顺序分配和链式分配相结合的存储结构。
 * 如这个表头结点所对应的顶点存在相邻顶点，
 * 则把相邻顶点依次存放于表头结点所指向的单向链表中。*/
#include "stdio.h"
#include "iostream"
#include "malloc.h"
#define maxSize 1000
using namespace std;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct{
    int data;
    ArcNode *firstarc;
}Vnode;


typedef struct {
    Vnode adjlist[maxSize];
    int n,e;
}AGraph;//可以利用结构体整体结构，也可利用

AGraph *graph;


//插入链表尾部
void insertNode(ArcNode *node,ArcNode *newNode)
{
    ArcNode *p=node;
    while(p->nextarc!=NULL)
    {
        p=p->nextarc;
    }
    p->nextarc=newNode;
}

void create() {
    graph = (AGraph *) malloc(sizeof(AGraph));
    cout << "输入顶点的数目:" << endl;
    cin >> graph->n;
    cout << "输入图中边的数目：" << endl;
    cin >> graph->e;
    int u = -1, v = -1;
    //初始化有几个链
    for (int i = 0; i < graph->n; i++) {
        graph->adjlist[i].firstarc = NULL;
    }

    ArcNode *node;
    for (int i = 0; i < graph->e; i++) {
        cout << "请输入联通点A与B" << endl;
        cin >> u >> v;
        node = (ArcNode *) malloc(sizeof(ArcNode));
        node->adjvex = v;
        node->nextarc = NULL;
        graph->adjlist[u].data = u;
        if (graph->adjlist[u].firstarc == NULL) {
            //边
            graph->adjlist[u].firstarc = node;
        } else {
            //插入边
            insertNode(graph->adjlist[u].firstarc, node);
        }
    }
}


void traverseTree()
{
    for(int i=0;i<graph->n;i++)
    {
        if(graph->adjlist[i].firstarc!=NULL)
        {
            cout<<"与"<<i<<"连接的点有:";
            ArcNode *p=graph->adjlist[i].firstarc;
            while(p!=NULL)
            {
                cout<<p->adjvex<<" ";
                p=p->nextarc;
            }
        }
    }
}


int main()
{
    create();
    traverseTree();
    cout<<endl;
    system("pause");
    return 0;
}