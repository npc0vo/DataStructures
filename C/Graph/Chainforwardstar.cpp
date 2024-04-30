//
// Created by Npc on 2024/4/25.
//

#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string.h"
using namespace std;
/*1. 概念
链式向前星代码是基于向前星代码的优化，
 这是极大多数算法竞赛以及高效率图论算法喜欢适用的创建方法，
 与邻接表和邻接矩阵比较容易的理解方式，向前星算法并不容易理解。

在理解链式向前星之前我们需要了解什么是向前星
 ，前向星是一种特殊的边集数组，我们把边集数组中的每一条边按照起点从小到大排序
 ，如果起点相同就按照终点从小到大排序
 ，并记录下以某个点为起点的所有边在数组中的起始位置和存储长度
 ,那么前向星就构造好了。

链式向前星的本质是利用链表的特性
 （一个结点指向另一个结点），以达到不需要像向前星那样排序
 （排序的平均情况需要O(nlogn)的代价）
 就可以直接搜索到目标，
 从而达到减少计算机运算时间使用的情况。*/


/*1.结构设计
 * 前向星是一种特殊的边集数组
 * 我们把边集数组中的每一条边按照起点从小到大排序
 * 如果起点相同就按照终点从小到大排序
 * 并记录下以某个点为起点的所有边在数组中的起始位置和存储长度,*/


/*a)Edge表示边，这个结构体数组将逐步记录边信息，其中包含有三个元素

l  w为权重即边之间的权值，下图中为默认的1，不演示

l  to表示为第i条边指向哪一个结点

l  edge[i].next表示第i条边的下一条边的序号

b)Cnt表示边的数量，在输入时利用他逐个+1

c)Head表示第x个结点所需要访问的边*/
struct Edge{
    int w;   //权重
    int to;  //to表示为第i条边指向哪一个节点
    int next; //next存储的是当前编号边的下一条边的编号。
    // 这样，我们可以通过next快速找到从同一个节点出发的下一条边。
}edge[10005]; //edge是一个Edge数组（边集）

int cnt=0; //用以控制并统计边的数量

int head[10005]; //head[i]存储的是节点i的第一条边的编号。这
// 样，我们可以通过head[i]快速找到从节点i出发的所有边。


//按顺序编号
void addEdge(int from,int to,int w)  //from就是第i个节点
{
    edge[cnt].to=to;
    edge[cnt].w=w;
    edge[cnt].next=head[from];
    head[from]=cnt++;   //cnt指向当前边的编号
}

/*注意，我们需要对全体数组进行赋-1的初值，
 * 这对于出错和检验错误都是很有帮助的，因为-1正是本算法的判定边界点
 * ，当然，这个边界点也可以由自己定位任意一个负数。*/

// 打印图的边列表
void printEdges(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << "Node " << i << " edges: ";
        for (int j = head[i]; j != -1; j = edge[j].next) {
            cout << "(" << i << "->" << edge[j].to << ", w=" << edge[j].w << ") ";
        }
        cout << endl;
    }
}

int main() {
    // 初始化数组
    memset(head, -1, sizeof(head));

    // 添加边到图中
    addEdge(1, 2, 1);
    addEdge(1, 3, 1);
    addEdge(2, 4, 1);
    addEdge(2, 5, 1);
    addEdge(3, 4, 1);
    addEdge(4, 5, 1);

    // 打印每个节点的边列表
    printEdges(5);
    system("pause");
    return 0;
}

